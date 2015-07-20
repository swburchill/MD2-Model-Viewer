/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *imagesLayout_2;
    QWidget *containerWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLabel *label_8;
    QDoubleSpinBox *scaleSB;
    QDoubleSpinBox *fovSB;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QDoubleSpinBox *yRotationSB;
    QDoubleSpinBox *zRotationSB;
    QLabel *label_2;
    QDoubleSpinBox *xRotationSB;
    QLabel *label_3;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *xTranslationSB;
    QDoubleSpinBox *yTranslationSB;
    QDoubleSpinBox *zTranslationSB;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QDoubleSpinBox *ambientLightIntensitySB;
    QLabel *label_10;
    QDoubleSpinBox *diffuseAlbedoGSB;
    QDoubleSpinBox *diffuseAlbedoBSB;
    QLabel *label_12;
    QDoubleSpinBox *diffuseAlbedoRSB;
    QDoubleSpinBox *ambientBSB;
    QDoubleSpinBox *ambientGSB;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QDoubleSpinBox *pointLightIntensitySB;
    QDoubleSpinBox *specularAlbedoBSB;
    QDoubleSpinBox *specularAlbedoRSB;
    QLabel *label_11;
    QDoubleSpinBox *ambientRSB;
    QDoubleSpinBox *specularAlbedoGSB;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QDoubleSpinBox *specularPowerSB;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout;
    QPushButton *loadButton;
    QPushButton *quitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1326, 886);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        imagesLayout_2 = new QHBoxLayout();
        imagesLayout_2->setSpacing(6);
        imagesLayout_2->setObjectName(QStringLiteral("imagesLayout_2"));
        containerWidget = new QWidget(centralWidget);
        containerWidget->setObjectName(QStringLiteral("containerWidget"));
        containerWidget->setMinimumSize(QSize(800, 600));

        imagesLayout_2->addWidget(containerWidget);


        verticalLayout_3->addLayout(imagesLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        scaleSB = new QDoubleSpinBox(centralWidget);
        scaleSB->setObjectName(QStringLiteral("scaleSB"));
        scaleSB->setMinimum(0.01);
        scaleSB->setMaximum(10);
        scaleSB->setSingleStep(0.1);
        scaleSB->setValue(1);

        gridLayout_2->addWidget(scaleSB, 0, 1, 1, 1);

        fovSB = new QDoubleSpinBox(centralWidget);
        fovSB->setObjectName(QStringLiteral("fovSB"));
        fovSB->setMinimum(-1);
        fovSB->setMaximum(360);
        fovSB->setSingleStep(0.1);
        fovSB->setValue(45);

        gridLayout_2->addWidget(fovSB, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        yRotationSB = new QDoubleSpinBox(centralWidget);
        yRotationSB->setObjectName(QStringLiteral("yRotationSB"));
        yRotationSB->setMinimum(-1);
        yRotationSB->setMaximum(360);

        gridLayout_3->addWidget(yRotationSB, 1, 1, 1, 1);

        zRotationSB = new QDoubleSpinBox(centralWidget);
        zRotationSB->setObjectName(QStringLiteral("zRotationSB"));
        zRotationSB->setMinimum(-1);
        zRotationSB->setMaximum(360);

        gridLayout_3->addWidget(zRotationSB, 2, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        xRotationSB = new QDoubleSpinBox(centralWidget);
        xRotationSB->setObjectName(QStringLiteral("xRotationSB"));
        xRotationSB->setMinimum(-1);
        xRotationSB->setMaximum(360);

        gridLayout_3->addWidget(xRotationSB, 0, 1, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_4->addWidget(label_5, 1, 0, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 2, 0, 1, 1);

        xTranslationSB = new QDoubleSpinBox(centralWidget);
        xTranslationSB->setObjectName(QStringLiteral("xTranslationSB"));
        xTranslationSB->setMinimum(-10);
        xTranslationSB->setMaximum(10);
        xTranslationSB->setSingleStep(0.1);

        gridLayout_4->addWidget(xTranslationSB, 0, 1, 1, 1);

        yTranslationSB = new QDoubleSpinBox(centralWidget);
        yTranslationSB->setObjectName(QStringLiteral("yTranslationSB"));
        yTranslationSB->setMinimum(-10);
        yTranslationSB->setMaximum(10);
        yTranslationSB->setSingleStep(0.1);

        gridLayout_4->addWidget(yTranslationSB, 1, 1, 1, 1);

        zTranslationSB = new QDoubleSpinBox(centralWidget);
        zTranslationSB->setObjectName(QStringLiteral("zTranslationSB"));
        zTranslationSB->setMinimum(-10);
        zTranslationSB->setMaximum(10);
        zTranslationSB->setSingleStep(0.1);

        gridLayout_4->addWidget(zTranslationSB, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_4);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_5->addWidget(label_14);

        ambientLightIntensitySB = new QDoubleSpinBox(centralWidget);
        ambientLightIntensitySB->setObjectName(QStringLiteral("ambientLightIntensitySB"));
        ambientLightIntensitySB->setMaximum(10);
        ambientLightIntensitySB->setSingleStep(0.1);
        ambientLightIntensitySB->setValue(1);

        horizontalLayout_5->addWidget(ambientLightIntensitySB);


        gridLayout_5->addLayout(horizontalLayout_5, 0, 3, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 2, 0, 1, 1);

        diffuseAlbedoGSB = new QDoubleSpinBox(centralWidget);
        diffuseAlbedoGSB->setObjectName(QStringLiteral("diffuseAlbedoGSB"));
        diffuseAlbedoGSB->setDecimals(5);
        diffuseAlbedoGSB->setMaximum(1);
        diffuseAlbedoGSB->setSingleStep(0.01);
        diffuseAlbedoGSB->setValue(0.2);

        gridLayout_5->addWidget(diffuseAlbedoGSB, 2, 2, 1, 1);

        diffuseAlbedoBSB = new QDoubleSpinBox(centralWidget);
        diffuseAlbedoBSB->setObjectName(QStringLiteral("diffuseAlbedoBSB"));
        diffuseAlbedoBSB->setDecimals(5);
        diffuseAlbedoBSB->setMaximum(1);
        diffuseAlbedoBSB->setSingleStep(0.01);
        diffuseAlbedoBSB->setValue(0.7);

        gridLayout_5->addWidget(diffuseAlbedoBSB, 2, 3, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 4, 0, 1, 1);

        diffuseAlbedoRSB = new QDoubleSpinBox(centralWidget);
        diffuseAlbedoRSB->setObjectName(QStringLiteral("diffuseAlbedoRSB"));
        diffuseAlbedoRSB->setDecimals(5);
        diffuseAlbedoRSB->setMaximum(1);
        diffuseAlbedoRSB->setSingleStep(0.01);
        diffuseAlbedoRSB->setValue(0.5);

        gridLayout_5->addWidget(diffuseAlbedoRSB, 2, 1, 1, 1);

        ambientBSB = new QDoubleSpinBox(centralWidget);
        ambientBSB->setObjectName(QStringLiteral("ambientBSB"));
        ambientBSB->setDecimals(5);
        ambientBSB->setMaximum(1);
        ambientBSB->setSingleStep(0.01);
        ambientBSB->setValue(0.1);

        gridLayout_5->addWidget(ambientBSB, 4, 3, 1, 1);

        ambientGSB = new QDoubleSpinBox(centralWidget);
        ambientGSB->setObjectName(QStringLiteral("ambientGSB"));
        ambientGSB->setDecimals(5);
        ambientGSB->setMaximum(1);
        ambientGSB->setSingleStep(0.01);
        ambientGSB->setValue(0.1);

        gridLayout_5->addWidget(ambientGSB, 4, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_4->addWidget(label_13);

        pointLightIntensitySB = new QDoubleSpinBox(centralWidget);
        pointLightIntensitySB->setObjectName(QStringLiteral("pointLightIntensitySB"));
        pointLightIntensitySB->setSingleStep(0.1);
        pointLightIntensitySB->setValue(1);

        horizontalLayout_4->addWidget(pointLightIntensitySB);


        gridLayout_5->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        specularAlbedoBSB = new QDoubleSpinBox(centralWidget);
        specularAlbedoBSB->setObjectName(QStringLiteral("specularAlbedoBSB"));
        specularAlbedoBSB->setDecimals(5);
        specularAlbedoBSB->setMaximum(1);
        specularAlbedoBSB->setSingleStep(0.01);
        specularAlbedoBSB->setValue(0.7);

        gridLayout_5->addWidget(specularAlbedoBSB, 3, 3, 1, 1);

        specularAlbedoRSB = new QDoubleSpinBox(centralWidget);
        specularAlbedoRSB->setObjectName(QStringLiteral("specularAlbedoRSB"));
        specularAlbedoRSB->setDecimals(5);
        specularAlbedoRSB->setMaximum(1);
        specularAlbedoRSB->setSingleStep(0.01);
        specularAlbedoRSB->setValue(0.7);

        gridLayout_5->addWidget(specularAlbedoRSB, 3, 1, 1, 1);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 3, 0, 1, 1);

        ambientRSB = new QDoubleSpinBox(centralWidget);
        ambientRSB->setObjectName(QStringLiteral("ambientRSB"));
        ambientRSB->setDecimals(5);
        ambientRSB->setMaximum(1);
        ambientRSB->setSingleStep(0.01);
        ambientRSB->setValue(0.1);

        gridLayout_5->addWidget(ambientRSB, 4, 1, 1, 1);

        specularAlbedoGSB = new QDoubleSpinBox(centralWidget);
        specularAlbedoGSB->setObjectName(QStringLiteral("specularAlbedoGSB"));
        specularAlbedoGSB->setDecimals(5);
        specularAlbedoGSB->setMaximum(1);
        specularAlbedoGSB->setSingleStep(0.01);
        specularAlbedoGSB->setValue(0.7);

        gridLayout_5->addWidget(specularAlbedoGSB, 3, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_6->addWidget(label_9);

        specularPowerSB = new QDoubleSpinBox(centralWidget);
        specularPowerSB->setObjectName(QStringLiteral("specularPowerSB"));
        specularPowerSB->setMaximum(255);
        specularPowerSB->setValue(128);

        horizontalLayout_6->addWidget(specularPowerSB);


        gridLayout_5->addLayout(horizontalLayout_6, 0, 1, 1, 1);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_5);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        horizontalLayout->addWidget(loadButton);

        quitButton = new QPushButton(centralWidget);
        quitButton->setObjectName(QStringLiteral("quitButton"));

        horizontalLayout->addWidget(quitButton);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(quitButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_7->setText(QApplication::translate("MainWindow", "Scale", 0));
        label_8->setText(QApplication::translate("MainWindow", "FOV", 0));
        label->setText(QApplication::translate("MainWindow", "Model x Rotation", 0));
        label_2->setText(QApplication::translate("MainWindow", "Model y Rotation", 0));
        label_3->setText(QApplication::translate("MainWindow", "Model z Rotation", 0));
        label_4->setText(QApplication::translate("MainWindow", "Model x Translation", 0));
        label_5->setText(QApplication::translate("MainWindow", "Model y Translation", 0));
        label_6->setText(QApplication::translate("MainWindow", "Model z Translation", 0));
        label_14->setText(QApplication::translate("MainWindow", "Ambient Light Intensity", 0));
        label_10->setText(QApplication::translate("MainWindow", "Diffuse Albedo", 0));
        label_12->setText(QApplication::translate("MainWindow", "Ambient", 0));
        label_13->setText(QApplication::translate("MainWindow", "Point Light Instensity", 0));
        label_11->setText(QApplication::translate("MainWindow", "Specular Albedo", 0));
        label_9->setText(QApplication::translate("MainWindow", "Specular Exponent", 0));
        label_15->setText(QApplication::translate("MainWindow", "Shading Controls", 0));
        loadButton->setText(QApplication::translate("MainWindow", "Load MD2 Model", 0));
        quitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
