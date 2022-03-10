#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include "dialoginsertionremi.h"
#include "ui_mainwindow.h"
/*
 * A mettre dans le .h

bool quitConfirm();
void closeEvent(QCloseEvent *event);
void on_pushButton_Ajouter_clicked():
QString gestionSpecialCaractere(QString chaine);

 */

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

QString MainWindow::gestionSpecialCaractere(QString chaine)
{
    qDebug()<<"QString MainWindow::gestionSpecialCaractere(QString chaine)";

    //on verifie si la chaine contient un caractere special tel que ' "
    if(chaine.indexOf("'") != -1 )
    {
        chaine.replace(chaine.indexOf("'"),1, "''");
    }
    else if (chaine.indexOf('"') != -1 )
    {
        chaine.replace(chaine.indexOf('"'), 1, "''");
    }
    return  chaine;
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

    //on execute la fonction qui permet la creation des colonnes
    insertion.createTableColonne(MainWindow::ui->listWidget_Table->currentItem()->text());

    qDebug()<<"remi.cpp nomTable = "<<currentTable;
    insertion.exec();
}
