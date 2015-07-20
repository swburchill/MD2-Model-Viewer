#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myopenglwidget.h"
#include <QVBoxLayout>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    layout_ = new QVBoxLayout(ui->containerWidget);
    ui->containerWidget->setLayout(layout_);

    connectSlots();
    currentModel_ = new MD2();
    loadModel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSlots()
{
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadModel()));
    connect(ui->xRotationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->yRotationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->zRotationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->xTranslationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->yTranslationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->zTranslationSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->scaleSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->fovSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->pointLightIntensitySB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->diffuseAlbedoRSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->diffuseAlbedoGSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->diffuseAlbedoBSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->specularPowerSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->specularAlbedoRSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->specularAlbedoGSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->specularAlbedoBSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));

    connect(ui->ambientLightIntensitySB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->ambientRSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->ambientGSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
    connect(ui->ambientBSB, SIGNAL(valueChanged(double)), this, SLOT(updateToGuiValues()));
}

void MainWindow::updateToGuiValues()
{
    glm::vec3 rotation;
    glm::vec3 translation;
    float fov;
    float scale;
    float ambientLightIntensity;
    float pointLightIntensity;
    float specularPower;
    glm::vec3 diffuseAlbedo;
    glm::vec3 ambient;
    glm::vec3 specularAlbedo;

    rotation.x = (float)ui->xRotationSB->value();
    if(rotation.x >= 360.0)
    {
        rotation.x = 0.0;
        ui->xRotationSB->setValue(0.0);
    }
    if(rotation.x < 0)
    {
        rotation.x = 359.0;
        ui->xRotationSB->setValue(359.0);
    }
    rotation.y = (float)ui->yRotationSB->value();
    if(rotation.y >= 360.0)
    {
        rotation.y = 0.0;
        ui->yRotationSB->setValue(0.0);
    }
    if(rotation.y < 0)
    {
        rotation.y = 359.0;
        ui->yRotationSB->setValue(359.0);
    }
    rotation.z = (float)ui->zRotationSB->value();
    if(rotation.z >= 360.0)
    {
        rotation.z = 0.0;
        ui->zRotationSB->setValue(0.0);
    }
    if(rotation.z < 0)
    {
        rotation.z = 359.0;
        ui->zRotationSB->setValue(359.0);
    }

    translation.x = (float)ui->xTranslationSB->value();
    translation.y = (float)ui->yTranslationSB->value();
    translation.z = (float)ui->zTranslationSB->value();

    fov = (float)ui->fovSB->value();
    if(fov >= 360.0)
    {
        fov = 0.0;
        ui->fovSB->setValue(0.0);
    }
    if(fov < 0)
    {
        fov = 359.0;
        ui->fovSB->setValue(359.0);
    }

    scale = (float)ui->scaleSB->value();

    pointLightIntensity = (float)ui->pointLightIntensitySB->value();

    diffuseAlbedo.x = (float)ui->diffuseAlbedoRSB->value();
    diffuseAlbedo.y = (float)ui->diffuseAlbedoGSB->value();
    diffuseAlbedo.z = (float)ui->diffuseAlbedoBSB->value();

    specularPower = (float)ui->specularPowerSB->value();

    specularAlbedo.x = (float)ui->specularAlbedoRSB->value();
    specularAlbedo.y = (float)ui->specularAlbedoGSB->value();
    specularAlbedo.z = (float)ui->specularAlbedoBSB->value();

    ambientLightIntensity = (float)ui->ambientLightIntensitySB->value();

    ambient.x = (float)ui->ambientRSB->value();
    ambient.y = (float)ui->ambientGSB->value();
    ambient.z = (float)ui->ambientBSB->value();

    scene_->setPointLightIntensity(pointLightIntensity);
    scene_->setDiffuseAlbedo(diffuseAlbedo);
    scene_->setSpecularPower(specularPower);
    scene_->setSpecularAlbedo(specularAlbedo);
    scene_->setAmbientLightIntensity(ambientLightIntensity);
    scene_->setAmbient(ambient);
    scene_->setScale(scale);
    scene_->setFOV(fov);
    scene_->setRotation(rotation);
    scene_->setTranslation(translation);
    scene_->setModelCenter(glm::vec3(xmid_, ymid_, zmid_)); //from bounding box calculation.
}

void MainWindow::resetGuiValues()
{
    ui->xRotationSB->setValue(0.0);
    ui->yRotationSB->setValue(0.0);
    ui->zRotationSB->setValue(0.0);

    ui->xTranslationSB->setValue(0.0);
    ui->yTranslationSB->setValue(0.0);
    ui->zTranslationSB->setValue(0.0);

    ui->scaleSB->setValue(1.0);
    ui->fovSB->setValue(45.0);

    ui->pointLightIntensitySB->setValue(1);

    ui->diffuseAlbedoRSB->setValue(0.5);
    ui->diffuseAlbedoGSB->setValue(0.2);
    ui->diffuseAlbedoBSB->setValue(0.7);

    ui->specularPowerSB->setValue(128.0);
    ui->specularAlbedoRSB->setValue(0.7);
    ui->specularAlbedoGSB->setValue(0.7);
    ui->specularAlbedoBSB->setValue(0.7);

    ui->ambientLightIntensitySB->setValue(1);
    ui->ambientRSB->setValue(0.1);
    ui->ambientGSB->setValue(0.1);
    ui->ambientBSB->setValue(0.1);
}

void MainWindow::loadModel()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",tr("Files (*.md2)"));
    bool success = false;
    if(fileName!=NULL)
    {
        success = currentModel_->LoadModel(fileName.toUtf8().constData());
        if(success == false)
        {
            cout << "Error loading MD2 model" << endl;
        }
        else
        {
            resetGuiValues();
            //convert buffers for opengl
            createVertexBuffer();
            createIndexBuffer();
            createNormalBuffer();
            createWidget();
        }
    }
    else
    {
        cout << "No Valid MD2 Filename selected" << endl;
    }
}

// Calculate normal from vertices
glm::vec3 MainWindow::calcNormal(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3)
 {
  // Calculate vectors
  float v1x = point1.x - point2.x;
  float v1y = point1.y - point2.y;
  float v1z = point1.z - point2.z;

  float v2x = point2.x - point3.x;
  float v2y = point2.y - point3.y;
  float v2z = point2.z - point3.z;

  // Get cross product of vectors
  float nx = (v1y * v2z) - (v1z * v2y);
  float ny = (v1z * v2x) - (v1x * v2z);
  float nz = (v1x * v2y) - (v1y * v2x);

  // Normalise final vector
  float vLen = sqrt( (nx * nx) + (ny * ny) + (nz * nz) );

  glm::vec3 Result;
  if (vLen != 0)
  {
      Result.x = (float)(nx / vLen);
      Result.y = (float)(ny / vLen);
      Result.z = (float)(nz / vLen);
  }
  else
  {
      Result.x = (float)(nx);
      Result.y = (float)(ny);
      Result.z = (float)(nz);
  }

  return Result;
 }

void MainWindow::createVertexBuffer()
{
    vertexBuffer_ = new QVector<GLfloat>();

    float absMax = fabs(currentModel_->m_vertices[0][0]);
    float xmax = currentModel_->m_vertices[0][0];
    float xmin = currentModel_->m_vertices[0][0];
    float ymax = currentModel_->m_vertices[0][1];
    float ymin = currentModel_->m_vertices[0][1];
    float zmax = currentModel_->m_vertices[0][2];
    float zmin = currentModel_->m_vertices[0][2];
    float value = 0.0;
    float absValue = 0.0;

    for(int i = 0; i <(currentModel_->num_xyz); i++)
    {
        for(int j = 0; j < 3; j++)
        {
            value = currentModel_->m_vertices[i][j];
            absValue = fabs(value);
            if (absValue > absMax)
            {
                absMax = absValue;
            }
            vertexBuffer_->append(value);
            //compute bounding box
            if(j==0)
            {
                if (value > xmax)
                {
                    xmax = value;
                }
                if (value < xmin)
                {
                    xmin = value;
                }
            }
            if(j==1)
            {
                if (value > ymax)
                {
                    ymax = value;
                }
                if (value < ymin)
                {
                    ymin = value;
                }
            }
            if(j==2)
            {
                if (value > zmax)
                {
                    zmax = value;
                }
                if (value < zmin)
                {
                    zmin = value;
                }
            }

        }
        vertexBuffer_->append(1.0f);
    }
    if(absMax != 0)
    {
        //normalize so max and min are at most 1 and -1
        xmax /= absMax;
        xmin /= absMax;
        ymax /= absMax;
        ymin /= absMax;
        zmax /= absMax;
        zmin /= absMax;
    }
    xmid_ = (xmax+xmin)/2;
    ymid_ = (ymax+ymin)/2;
    zmid_ = (zmax+zmin)/2;
    if(absMax != 0)
    {
        // Map values to range [-1, 1]
        normalizeVertices(absMax);
    }
}

//This will ensure the model is always in our viewing volume and that we have the room to rotate and scale
void MainWindow::normalizeVertices(float absMax)
{
    int skipPointIndicator = 3;
    for(int i = 0; i<vertexBuffer_->size(); i++)
    {
       if(i!=skipPointIndicator)
       {
          vertexBuffer_->replace(i, vertexBuffer_->at(i)/absMax);
       }
       else
       {
          skipPointIndicator+=4;
       }
    }
}

void MainWindow::createNormalBuffer()
{
    normalBuffer_ = new QVector<GLfloat>();
    for(int vertex = 0; vertex < currentModel_->num_xyz; vertex++)
    {
       GLfloat sumXNormals = 0.0;
       GLfloat sumYNormals = 0.0;
       GLfloat sumZNormals = 0.0;
       GLfloat xNormal = 0.0;
       GLfloat yNormal = 0.0;
       GLfloat zNormal = 0.0;

        foreach(triangle_t* tri, (*facesTable_)[vertex])
        {
            glm::vec3 point1, point2, point3, result;
            point1.x = currentModel_->m_vertices[tri->index_xyz[0]][0];
            point1.y = currentModel_->m_vertices[tri->index_xyz[0]][1];
            point1.z = currentModel_->m_vertices[tri->index_xyz[0]][2];
            point2.x = currentModel_->m_vertices[tri->index_xyz[1]][0];
            point2.y = currentModel_->m_vertices[tri->index_xyz[1]][1];
            point2.z = currentModel_->m_vertices[tri->index_xyz[1]][2];
            point3.x = currentModel_->m_vertices[tri->index_xyz[2]][0];
            point3.y = currentModel_->m_vertices[tri->index_xyz[2]][1];
            point3.z = currentModel_->m_vertices[tri->index_xyz[2]][2];
            result = calcNormal(point1, point2, point3);
            sumXNormals += result.x;
            sumYNormals += result.y;
            sumZNormals += result.z;
        }

        xNormal = (float)sumXNormals/((*facesTable_)[vertex].size());
        yNormal = (float)sumYNormals/((*facesTable_)[vertex].size());
        zNormal = (float)sumZNormals/((*facesTable_)[vertex].size());

        normalBuffer_->append(xNormal);
        normalBuffer_->append(yNormal);
        normalBuffer_->append(zNormal);
    }
}

void MainWindow::createIndexBuffer()
{
    indexBuffer_ = new QVector<GLushort>();
    facesTable_ = new QMap<int, QList<triangle_t*> >();
    int index = 0;
    for(int i = 0; i <(currentModel_->num_tris); i++)
    {
        triangle_t* tri = currentModel_->tris + i;
        for (int j = 0; j <3; j++)
        {
            index = tri->index_xyz[j];
            indexBuffer_->append(index);
            //add triangle to list for this specific vertex
            (*facesTable_)[index].append(tri);
        }
    }
}

void MainWindow::createWidget()
{
   if(scene_ != NULL)
   {
      layout_->removeWidget(scene_);
   }
   scene_ = new myOpenGLWidget(this, vertexBuffer_, normalBuffer_, indexBuffer_);
   layout_->addWidget(scene_);
}
