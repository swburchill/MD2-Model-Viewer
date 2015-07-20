#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QOpenGLFunctions>
#include <QFileDialog>
#include <iostream>
#include "md2.h"

namespace Ui {
class MainWindow;
}

class QVBoxLayout;
class myOpenGLWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadModel();
    void updateToGuiValues();

private:
    void connectSlots();
    glm::vec3 calcNormal(glm::vec3 point1, glm::vec3 point2, glm::vec3 point3);
    void createWidget();
    void createVertexBuffer();
    void createNormalBuffer();
    void createIndexBuffer();
    void normalizeVertices(float absMax);
    void resetGuiValues();

    Ui::MainWindow *ui;
    MD2* currentModel_;
    QVector<GLfloat>* vertexBuffer_;
    QVector<GLfloat>* normalBuffer_;
    QVector<GLushort>* indexBuffer_;
    QMap<int, QList<triangle_t*> >* facesTable_;

    myOpenGLWidget* scene_;
    QVBoxLayout* layout_;

    float xmid_;
    float ymid_;
    float zmid_;
};

#endif // MAINWINDOW_H
