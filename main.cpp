#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.hide();

    //si la connexion est faite
    if(w.connection()){
        w.show();

    }

    return a.exec();
}
