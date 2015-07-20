#include "myopenglwidget.h"
#include <QOpenGLVertexArrayObject>

using namespace std;

// shader program to use
GLuint myShaderProgram;
GLuint myFloorShader;

// Constants to help with location bindings
#define VERTEX_DATA 0
#define VERTEX_NORMAL 1

// VAO and VBO to handle vertex state and data
GLuint myVAO;
GLuint myVBO;
GLuint myFaceNormalVBO;
GLuint myIndexVBO;

myOpenGLWidget::myOpenGLWidget(QWidget *parent, QVector<GLfloat>* vertexBufer,
                               QVector<GLfloat>* normalBuffer, QVector<GLushort>* indexBuffer) :
    QOpenGLWidget(parent),
    vertexBuffer_(vertexBufer),
    normalBuffer_(normalBuffer),
    indexBuffer_(indexBuffer),
    cameraPosition_(0.0, 0.0, 5.0),   //since model will be max -1 and 1 this should give us good view with room to rotate and scale
    translation_(0.0, 0.0, 0.0),
    modelCenter_(0.0, 0.0, 0.0),
    rotation_(0.0, 0.0, 0.0),
    scale_(1),
    fov_(45),
    //defaults from shader
    specularPower_(128),
    specularAlbedo_(0.7, 0.7, 0.7),
    diffuseAlbedo_(0.5, 0.2, 0.7),
    ambient_(0.1, 0.1, 0.1),
    ambientLightIntensity_(1),
    pointLightIntensity_(1)
{
}

myOpenGLWidget::~myOpenGLWidget()
{
}

void myOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.7f, 0.3f, 0.0f );
    // Setup the vertex state array object. All subsequent buffers will bound to it
    qVAO_ = new QOpenGLVertexArrayObject();
    bool good = qVAO_->create();
    good ?  : cout << "VOA error\n";
    qVAO_->bind();
    // These two lines will print out the version of OpenGL and GLSL
    // that are being used so that problems due to version differences
    // can easily be identified.
    printf("OpenGL version: %s\n", (const char*) glGetString(GL_VERSION));
    printf("GLSL version: %s\n", (const char*) glGetString(GL_SHADING_LANGUAGE_VERSION));
    // Do any necessary initializations (enabling buffers, setting up shaders, geometry etc.)
    // This is done by calling the function setupRenderingContext().
    setupRenderingContext();
    GLenum err;
    if((err = glGetError()) != GL_NO_ERROR)
    {
        cout << "ASSERT ERROR init!" << endl;
        cerr << "OpenGL error: " << err << endl;
    }
}

void myOpenGLWidget::paintGL()
{
    GLint mv_matrix = glGetUniformLocation(myShaderProgram, "mv_matrix");
    GLint proj_matrix = glGetUniformLocation(myShaderProgram, "proj_matrix");
    GLint diffuse_albedo = glGetUniformLocation(myShaderProgram, "diffuse_albedo");
    GLint specular_albedo = glGetUniformLocation(myShaderProgram, "specular_albedo");
    GLint specular_power = glGetUniformLocation(myShaderProgram, "specular_power");
    GLint ambient = glGetUniformLocation(myShaderProgram, "ambient");
    GLint point_Light_Intensity = glGetUniformLocation(myShaderProgram, "point_Light_Intensity");
    GLint ambient_Light_Intensity = glGetUniformLocation(myShaderProgram, "ambient_Light_Intensity");

    // Projection matrix : 45 Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    glm::mat4 projectionMatrix = glm::perspective(fov_, 4.0f / 3.0f, 0.1f, 100.0f);

    // View matrix
    glm::mat4 viewMatrix = glm::lookAt(cameraPosition_, // Camera is at (X,Y,Z), in World Space
                                       glm::vec3(0, 0, 0), // and looks at the origin
                                       glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
                                       );

    // Model matrix : an identity matrix (model will be at the origin)
    glm::mat4 Model = glm::mat4(1.0f);

    // Scale Model
    glm::mat4 scaleMatrix = glm::scale(Model, glm::vec3(scale_));

    // Rotate Model
    glm::mat4 xRotationMatrix = glm::rotate(Model, (float)(rotation_.x), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 yRotationMatrix = glm::rotate(Model, (float)(rotation_.y), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 zRotationMatrix = glm::rotate(Model, (float)(rotation_.z), glm::vec3(0.0f, 0.0f, 1.0f));

    // Translate Model
    glm::mat4 sendModelToOrigin = glm::translate(glm::mat4(1.0f), -modelCenter_);
    glm::mat4 returnModelToPosition = glm::translate(glm::mat4(1.0f), modelCenter_);
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), translation_);

    Model = Model * translationMatrix * returnModelToPosition* xRotationMatrix * yRotationMatrix * zRotationMatrix * scaleMatrix * sendModelToOrigin;

    glm::mat4 mvMatrix = viewMatrix * Model;

    // Clear the window and the depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glUseProgram(myShaderProgram);

    // Send our transformation to the currently bound shader,
    glUniformMatrix4fv(mv_matrix, 1, GL_FALSE, &mvMatrix[0][0]);
    glUniformMatrix4fv(proj_matrix, 1, GL_FALSE, &projectionMatrix[0][0]);

    glUniform3fv(diffuse_albedo, 1, &diffuseAlbedo_[0]);
    glUniform3fv(specular_albedo, 1, &specularAlbedo_[0]);
    glUniform1f(specular_power, specularPower_);
    glUniform3fv(ambient, 1, &ambient_[0]);
    glUniform1f(point_Light_Intensity, pointLightIntensity_);
    glUniform1f(ambient_Light_Intensity, ambientLightIntensity_);

    glDrawElements(GL_TRIANGLES, indexBuffer_->size(), GL_UNSIGNED_SHORT, 0);

    // Draw a floor in polished silver using it's own shader
    glUseProgram(myFloorShader);
    GLint floor_mv_matrix = glGetUniformLocation(myShaderProgram, "mv_matrix");
    GLint floor_proj_matrix = glGetUniformLocation(myShaderProgram, "proj_matrix");
    GLint floorSpecular_power = glGetUniformLocation(myShaderProgram, "specular_power");
    GLint floorAmbient = glGetUniformLocation(myShaderProgram, "ambient");
    GLint floorPoint_Light_Intensity = glGetUniformLocation(myShaderProgram, "point_Light_Intensity");
    GLint floorAmbient_Light_Intensity = glGetUniformLocation(myShaderProgram, "ambient_Light_Intensity");

    Model = glm::mat4(1.0f);
    glm::mat4 floorMVMatrix = viewMatrix * Model;
    glUniformMatrix4fv(floor_mv_matrix, 1, GL_FALSE, &floorMVMatrix[0][0]);
    glUniformMatrix4fv(floor_proj_matrix, 1, GL_FALSE, &projectionMatrix[0][0]);

    // Let floor be affected by lighting
    glUniform1f(floorSpecular_power, specularPower_);
    glUniform3fv(floorAmbient, 1, &ambient_[0]);
    glUniform1f(floorPoint_Light_Intensity, pointLightIntensity_);
    glUniform1f(floorAmbient_Light_Intensity, ambientLightIntensity_);

    glBegin(GL_QUADS);
    glVertex3f(-2, -2, -2);
    glVertex3f(-2, 2, -2);
    glVertex3f(2, 2, -2);
    glVertex3f(2, -2, -2);
    glEnd();
    glFlush();

    GLenum err;
    if((err = glGetError()) != GL_NO_ERROR)
    {
        cout << "ASSERT ERROR! draw" << endl;
        cerr << "OpenGL error: " << err << endl;
    }
}

void myOpenGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    GLenum err;
    if((err = glGetError()) != GL_NO_ERROR)
    {
        cout << "ASSERT ERROR! resize" << endl;
        cerr << "OpenGL error: " << err << endl;
    }
}

// This function does any needed initialization on the rendering context.
void myOpenGLWidget::setupRenderingContext()
{
    // Background
    glClearColor(0.2f, 0.7f, 0.3f, 0.0f );
    glEnable(GL_DEPTH_TEST);

    const char* vShader = "per-fragment-phong.vs.glsl";
    const char* fShader = "per-fragment-phong.fs.glsl";
    loadShaders(vShader, fShader, &myShaderProgram);

    vShader = "floor.vs.glsl";
    fShader = "floor.fs.glsl";
    loadShaders(vShader, fShader, &myFloorShader);

    glGenBuffers(1, &myVBO);
    glBindBuffer(GL_ARRAY_BUFFER, myVBO);
    int verticesByteSize = vertexBuffer_->size()*sizeof(GLfloat);;
    glBufferData(GL_ARRAY_BUFFER, verticesByteSize, vertexBuffer_->data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(VERTEX_DATA);
    glVertexAttribPointer(VERTEX_DATA,4,GL_FLOAT,GL_FALSE, 0, (const GLvoid*) 0 );

    int faceNormalsByteSize = normalBuffer_->size()*sizeof(GLfloat);
    glGenBuffers(1, &myFaceNormalVBO);
    glBindBuffer(GL_ARRAY_BUFFER, myFaceNormalVBO);
    glBufferData(GL_ARRAY_BUFFER, faceNormalsByteSize, normalBuffer_->data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(VERTEX_NORMAL);
    glVertexAttribPointer(VERTEX_NORMAL,3,GL_FLOAT,GL_FALSE,0,(const GLvoid*) 0);

    glGenBuffers(1, &myIndexVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, myIndexVBO);
    int indicesByteSize = sizeof(GLushort)*indexBuffer_->size();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesByteSize, indexBuffer_->data(), GL_STATIC_DRAW );
    GLenum err;
    if((err = glGetError()) != GL_NO_ERROR)
    {
        cout << "ASSERT ERROR! setup" << endl;
        cerr << "OpenGL error: " << err << endl;
    }
}

void myOpenGLWidget::loadShaders(const char* vShader, const char* fShader, GLuint* program)
{
    //Now, let's setup the shaders
    GLuint hVertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint hFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    *program = (GLuint)NULL;
    GLint testVal;

    if(!loadShaderFile(vShader, hVertexShader))
    {
      glDeleteShader(hVertexShader);
      glDeleteShader(hFragmentShader);
      cout << "The Vertex shader could not be found." << endl;
    }

    if(!loadShaderFile(fShader, hFragmentShader))
    {
      glDeleteShader(hVertexShader);
      glDeleteShader(hFragmentShader);
      cout << "The Fragment shader could not be found." << endl;
    }

    glCompileShader(hVertexShader);
    glCompileShader(hFragmentShader);

    // Check for any error generated during shader compilation
    glGetShaderiv(hVertexShader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
      char source[8192];
      char infoLog[8192];
      glGetShaderSource(hVertexShader, 8192, NULL, source);
      glGetShaderInfoLog(hVertexShader, 8192, NULL, infoLog);
      cout << "The Vertex shader failed to compile:" << endl;
      fprintf(stderr, "%s\n", infoLog);
      glDeleteShader(hVertexShader);
      glDeleteShader(hFragmentShader);
    }
    glGetShaderiv(hFragmentShader, GL_COMPILE_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
      char source[8192];
      char infoLog[8192];
      glGetShaderSource(hFragmentShader, 8192, NULL, source);
      glGetShaderInfoLog(hFragmentShader, 8192, NULL, infoLog);
      cout << "The Fragment shader failed to compile:" << endl;
      fprintf(stderr, "%s\n", infoLog);
      glDeleteShader(hVertexShader);
      glDeleteShader(hFragmentShader);
    }

    // Create the shader program and bind locations for the vertex
    // attributes before linking. The linking process can also generate errors

    *program = glCreateProgram();
    glAttachShader(*program, hVertexShader);
    glAttachShader(*program, hFragmentShader);

    glBindAttribLocation(*program, VERTEX_DATA, "position");
    glBindAttribLocation(*program, VERTEX_NORMAL, "normal");
    //glBindAttribLocation(myShaderProgram, VERTEX_COLOUR, "color");

    glLinkProgram(*program);
    glDeleteShader(hVertexShader);
    glDeleteShader(hFragmentShader);
    glGetProgramiv(*program, GL_LINK_STATUS, &testVal);
    if(testVal == GL_FALSE)
    {
      char infoLog[1024];
      glGetProgramInfoLog(*program, 1024, NULL, infoLog);
      cout << "The shader program failed to link:" << endl << (const char*)infoLog << endl;
      glDeleteProgram(*program);
      *program = (GLuint)NULL;
    }
}

// Load the shader from the specified file. Returns false if the shader could not be loaded
static GLubyte shaderText[8192];
bool myOpenGLWidget::loadShaderFile(const char *filename, GLuint shader)
{
    GLint shaderLength = 0;
    FILE *fp;

    // Open the shader file
    fp = fopen(filename, "r");
    if(fp != NULL)
    {
        // See how long the file is
        while (fgetc(fp) != EOF)
          shaderLength++;

        // Go back to beginning of file
        rewind(fp);

        // Read the whole file in
        fread(shaderText, 1, shaderLength, fp);

        // Make sure it is null terminated and close the file
        shaderText[shaderLength] = '\0';
        fclose(fp);
    }
    else
    {
        return false;
    }

    // Load the string into the shader object
    GLchar* fsStringPtr[1];
    fsStringPtr[0] = (GLchar *)((const char*)shaderText);
    glShaderSource(shader, 1, (const GLchar **)fsStringPtr, NULL );

    return true;
}

void myOpenGLWidget::setCamera(glm::vec3 position)
{
    cameraPosition_ = position;
    update();
}

void myOpenGLWidget::setTranslation(glm::vec3 translation)
{
    translation_ = translation;
    update();
}

void myOpenGLWidget::setModelCenter(glm::vec3 center)
{
    modelCenter_ = center;
    update();
}

void myOpenGLWidget::setRotation(glm::vec3 rotationInDegrees)
{
    rotation_.x = rotationInDegrees.x;
    rotation_.y = rotationInDegrees.y;
    rotation_.z = rotationInDegrees.z;
    update();
}

void myOpenGLWidget::setScale(float scale)
{
    scale_ = scale;
    update();
}

void myOpenGLWidget::setFOV(float fov)
{
    fov_ = fov;
    update();
}

void myOpenGLWidget::setSpecularPower(float power)
{
    specularPower_ = power;
    update();
}


void myOpenGLWidget::setSpecularAlbedo(glm::vec3 specularAlbedo)
{
    specularAlbedo_ = specularAlbedo;
    update();
}

void myOpenGLWidget::setDiffuseAlbedo(glm::vec3 diffuseAlbedo)
{
    diffuseAlbedo_ = diffuseAlbedo;
    update();
}

void myOpenGLWidget::setAmbient(glm::vec3 ambient)
{
    ambient_ = ambient;
    update();
}

void myOpenGLWidget::setAmbientLightIntensity(float ambientLightIntensity)
{
    ambientLightIntensity_ = ambientLightIntensity;
    update();
}

void myOpenGLWidget::setPointLightIntensity(float pointLightIntensity)
{
    pointLightIntensity_ = pointLightIntensity;
    update();
}
