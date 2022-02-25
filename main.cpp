#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogConnexion connexion;

    connexion.exec();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
          db.setHostName(connexion.getDatabaseIP());
          db.setDatabaseName(connexion.getDatabaseName());
          db.setUserName(connexion.getUsername());
          db.setPassword(connexion.getPassword());
          bool ok = db.open();

    MainWindow w;
    w.show();

    return a.exec();
}
