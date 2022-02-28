#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QDebug>

/**
 * @brief MainWindow::connection
 * @return bool
 */
bool MainWindow::connection()
{
    DialogConnexion connexion;

    if(connexion.exec()==QDialog::Accepted) {
        //récupération des informations de connexion
        username = connexion.getUsername();
        password = connexion.getPassword();
        database = connexion.getDatabaseName();
        databaseIp = connexion.getDatabaseIP();
        return true;
    } else {
        return false;
    }
}
