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

/**
 * @brief MainWindow::on_pushButtonFilter_clicked
 * Méthode private slots de la classe MainWindow qui
 */
void MainWindow::on_pushButtonFilter_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonFilter_clicked()";
    filter = ui->lineEditFilter->text();
    afficherTableUtilisateur();
    filter = "";
}

/**
 * @brief MainWindow::updateWindowTitle
 * Méthode publique de la classe MainWindow qui actualise le titre de la MainWindow
 */
void MainWindow::updateWindowTitle()
{
    qDebug()<<"void MainWindow::updateWindowTitle()";
    setWindowTitle("dbManagerApp - "+database+" - "+username+"@"+databaseIp);
}
