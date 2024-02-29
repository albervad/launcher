#include "launcher.h"
#include <QApplication>
#include <qscreen.h>
#include <QSharedMemory>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    //If the application is already running, exit the new instance.
    QSharedMemory shared("62d50669-bd94-4a94-88pb-b964090n7e04");
    if (!shared.create(512, QSharedMemory::ReadWrite))
    {
        exit(0);
    }
    else
    {
        qDebug() << "Application started successfully.";
    }

    launcher w;
    w.resize(0, 0);
    return a.exec();
}