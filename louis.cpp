#include "mainwindow.h"
#include "dialogconnexion.h"
#include <QDebug>

/**
 * @brief MainWindow::on_action_Disconnect_triggered
 * Méthode private slots de la classe MainWindow qui déconnecte l'utilisateur et rappelle une fenêtre de connexion
 */
void MainWindow::on_action_Disconnect_triggered()
{
    qDebug()<<"void MainWindow::on_action_Disconnect_triggered()";
    //on cache la mainwindow
    hide();

    //si l'utlisateur se reconnecte
    if (connection()){
        //on affiche la mainwindow
        show();
    }
}
