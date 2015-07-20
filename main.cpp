#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("Stephen Burchill");
    app.setApplicationName("Assignment 2: Mesh Viewer (Rendering Pipeline / Local Illumination)");
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
