#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogConnexion w;
    w.show();

    return a.exec();
}
