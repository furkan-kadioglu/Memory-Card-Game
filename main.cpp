#include <QtWidgets/QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QLibraryInfo>
#include "mainwindow.h"

int main(int argc, char *argv[])
{    
    QApplication::setApplicationName("memory-game");
    QApplication::setApplicationVersion("1.0");

    QTranslator tQt, tApp;
    tQt.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    tApp.load(QApplication::applicationName() + "_" + QLocale::system().name(), ":/translations");

    QApplication a(argc, argv);
    QApplication::installTranslator(&tQt);
    QApplication::installTranslator(&tApp);


    //initiliaze MainWindow to start a game 
    MainWindow w;
    w.show();

    return a.exec();
}
