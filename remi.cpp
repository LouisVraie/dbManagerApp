#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include "dialoginsertionremi.h"
#include "ui_mainwindow.h"


/**
 * @brief Cette fonction sert a afficher un message de confirmation pour quitter
 * @return Retourne un booléen vrai si l'utilisateur confirme, sinon renvoie faux
 */
bool MainWindow::quitConfirm()
{
    qDebug()<<"MainWindow::quitConfirm()";
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment quitter cette fenêtre ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Cette fonction permet d'executer la fonction quitConfirm() quand l'utilisateur cherche a fermer la fenetre
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug()<<"MainWindow::closeEvent(QCloseEvent *event)";
    if(quitConfirm())
    {
        event->accept();
    }
    else {
        event->ignore();
    }
}

/**
 * @brief Cette fonction permet de creer une fenetre de dialogue contenant l'interface d'ajout, et de recuperer le nom de la table où on a demaré la fenetre
 */
void MainWindow::on_pushButton_Ajouter_clicked()
{
    qDebug()<<"MainWindow::on_pushButton_Ajouter_clicked";
    DialogInsertionRemi insertion;

    //on recupere le nom de la table du QListeWidget qui est selectionné
    insertion.getNomTableSelectionner(MainWindow::ui->listWidget_Table->currentItem()->text());
    qDebug()<<"nomTable = "<<nomTable;
    insertion.exec();
}
