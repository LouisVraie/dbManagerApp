#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
          db.setHostName("acidalia");
          db.setDatabaseName("customdb");
          db.setUserName("mojito");
          db.setPassword("J0a1m8");
          bool ok = db.open();

    QApplication a(argc, argv);
    DialogConnexion w;
    w.show();

    return a.exec();
}
