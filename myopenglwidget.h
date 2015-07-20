#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_3_1>
#include <QVector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

class QOpenGLVertexArrayObject;

class myOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_1
{
    Q_OBJECT
public:
    myOpenGLWidget(QWidget *parent = 0,
                   QVector<GLfloat>* vertexBufer = new QVector<GLfloat>,
                   QVector<GLfloat>* normalBuffer_ = new QVector<GLfloat>,
                   QVector<GLushort> *indexBuffer = new QVector<GLushort>);
    ~myOpenGLWidget();
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

public:
    void setupRenderingContext();
    void loadShaders(const char *vShader, const char *fShader, GLuint *program);
    bool loadShaderFile(const char *filename, GLuint shader);

    void setCamera(glm::vec3 position);
    void setTranslation(glm::vec3 translation);
    void setModelCenter(glm::vec3 center);
    void setRotation(glm::vec3 rotationInDegrees);
    void setScale(float scale);
    void setFOV(float fov);
    void setSpecularPower(float power);
    void setSpecularAlbedo(glm::vec3 specularAlbedo);
    void setDiffuseAlbedo(glm::vec3 diffuseAlbedo);
    void setAmbient(glm::vec3 ambient);
    void setAmbientLightIntensity(float ambientLightIntensity);
    void setPointLightIntensity(float pointLightIntensity);

private:
    QOpenGLVertexArrayObject* qVAO_;
    QVector<GLfloat>* vertexBuffer_;
    QVector<GLfloat>* normalBuffer_;
    QVector<GLushort>* indexBuffer_;

    glm::vec3 cameraPosition_;
    glm::vec3 translation_;
    glm::vec3 modelCenter_;
    glm::vec3 rotation_;
    float scale_;
    float fov_;
    float specularPower_;
    glm::vec3 specularAlbedo_;
    glm::vec3 diffuseAlbedo_;
    glm::vec3 ambient_;
    float ambientLightIntensity_;
    float pointLightIntensity_;
};

#endif // MYOPENGLWIDGET_H
