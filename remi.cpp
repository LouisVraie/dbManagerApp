#include "mainwindow.h"

/*
 a mettre dans le .h
#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>


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
    if(QMessageBox::warning(this,this->windowTitle(),"voulez-vous vraiment quitter cette fenetre ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
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
