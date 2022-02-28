/**********POUR AFFICHER LES TABLES ************/

//ajouter en public dans le maiwindow.h
//void AfficherTable();
//void on_listWidget_Table_itemClicked(QListWidgetItem *item);
//QString currentTable

#include "mainwindow.h"
#include <QMainWindow>
#include <QListWidget>
#include <QSqlQuery>
#include <QDebug>
#include "dialogconnexion.h"





/**
 * @brief Affiche les tables de la base
 */
void MainWindow::afficherListeTable()
{

    QString txtAfficheTable ="SHOW TABLES;";//Ligne de code sql en string
    QSqlQuery reqAfficheTable(txtAfficheTable);//Convertit la requête en Sql
    qDebug()<<txtAfficheTable;

    while (reqAfficheTable.next()) {//Tant qu'on peut passer au prochain
        QString nomTable=reqAfficheTable.value(0).toString();//On récupère le nom de la table
        ui->listWidget_Table->addItem(nomTable);//Et on l'affiche
    }
}



/**
 * @brief Récupère le nom de la table lorsque l'utilisateur clique dessus
 * @param item
 * @return Retourne une variable pour pouvoir afficher le contenu de la table
 */
void MainWindow::on_listWidget_Table_itemClicked(QListWidgetItem *item)//Méthode pour
{
    this->currentTable=item->text();//Met à jour la variable
    qDebug()<<currentTable;
    afficherTableUtilisateur();
}

/**********AVERTISSEMENT FERMETURE DIALOG************/

#include <QCloseEvent>
#include <QMessageBox>


/* A insérer dans le dialogconnexion.h
public :
    bool quitConfirm();
    void closeEvent(QCloseEvent *event);
*/

/**
 * @brief Permet d'avertir l'utilisateur pour quitter la boite de dialogue
 * @return Renvoie un booléen vrai ou faux
 */
bool DialogConnexion::quitConfirmConnexion()
{
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous quitter la page de connexion ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)//Si l'utilisateur clique sur "oui"
    {
        return true;//Le booléen retourne "vrai"
    }
    else {
        return false;//Le booléen retourne "faux"
    }
}



/**
 * @brief Permet de quitter ou laisser la fenêtre
 * @param event
 */
void DialogConnexion::closeEvent(QCloseEvent *event)
{
    if(quitConfirmConnexion())//Si le bouléen est vrai
    {
        event->accept();//Fermeture de l'application
    }
    else {
        event->ignore();//Ignore la demande
    }
}
