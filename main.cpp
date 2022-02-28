#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DialogConnexion connexion;

    if(connexion.exec()==QDialog::Accepted) {
        connexion.getUsername();
        MainWindow w;
        w.show();
        return a.exec();
    }
}
