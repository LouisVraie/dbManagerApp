#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include "dialoginsertionremi.h"
/*
 a mettre dans le .h
  public:
  bool quitConfirm();
  void closeEvent(QCloseEvent *event);

*/

/**
 * @brief Cette fonction sert a afficher un message de confirmation pour quitter
 * @return Retourne un booléen vrai si l'utilisateur confirme, sinon renvoie faux
 */
bool MainWindow::quitConfirm()
{
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
    if(quitConfirm())
    {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void MainWindow::on_pushButton_Ajouter_clicked()
{
    DialogInsertionRemi insertion;
    insertion.exec();
}
