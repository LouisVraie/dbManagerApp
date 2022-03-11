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
#include <QSqlError>
#include "dialogconnexion.h"




/**
 * @brief Affiche les tables de la base
 * cette méthode vide la listWidget des tables et obtient les tables de la base de données
 */
void MainWindow::afficherListeTable()
{
    qDebug()<<"void MainWindow::afficherListeTable()";
    ui->tabWidget->setCurrentIndex(0);
    ui->listWidget_Table->clear();//On clear la liste
    QString txtAfficheTable ="SHOW TABLES;";//Ligne de code sql en string
    QSqlQuery reqAfficheTable(txtAfficheTable);//Convertit la requête en Sql
    qDebug()<<txtAfficheTable;
    if (reqAfficheTable.next())
    {
        QString libelleTable=reqAfficheTable.value(0).toString();//On récupère le nom de la table
        ui->listWidget_Table->addItem(libelleTable);//Et on l'affiche
        while (reqAfficheTable.next()) {//Tant qu'on peut passer au prochain
            QString libelleTable=reqAfficheTable.value(0).toString();//On récupère le nom de la table
            ui->listWidget_Table->addItem(libelleTable);//Et on l'affiche
        }
        ui->listWidget_Table->setCurrentRow(0);
        currentTable=ui->listWidget_Table->currentItem()->text();
        afficherTableUtilisateur();
    } else {
        ui->textBrowserRequestResult->setText(tr("The database ")+database+tr(" doesn't contain any table !"));
    }
}



/**
 * @brief Récupère le nom de la table lorsque l'utilisateur clique dessus
 * @param item
 * @return Retourne une variable pour pouvoir afficher le contenu de la table
 */
void MainWindow::on_listWidget_Table_itemClicked(QListWidgetItem *item)//Méthode pour
{
    qDebug()<<"void MainWindow::on_listWidget_Table_itemClicked(QListWidgetItem *item)";
    this->currentTable=item->text();//Met à jour la variable
    afficherTableUtilisateur();
    ui->tabWidget->setCurrentIndex(0);
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
    qDebug()<<"bool Dialog";
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
    qDebug()<<"Quitter";
    if(quitConfirmConnexion())//Si le bouléen est vrai
    {
        event->accept();//Fermeture de l'application
    }
    else {
        event->ignore();//Ignore la demande
    }
}




/**********COMBO BOX************/

#include <QComboBox>

/* A ajouter en public dans mainwindow.h
void remplirComboBox();
A ajouter dans le constructeur de la mainwindow.cpp
remplirComboBox();
 */


/**
 * @brief Affiche les base connecté à l'utilisateur
 */
void MainWindow::remplirComboBox()
{
    qDebug()<<"void MainWindow::remplirComboBox()";
    ui->comboBox_Databases->clear();//Nétoie la comboBox


    QString txtReqRemblirComboBox = "SHOW DATABASES";//Ecrit la requête qui affiche les bases
    QSqlQuery reqRemplirComboBox(txtReqRemblirComboBox);//Conversion en sql
    while(reqRemplirComboBox.next())//Tant que quelque chose est écrit
    {
        ui->comboBox_Databases->addItem(reqRemplirComboBox.value(0).toString());//Le rajoute dans la comboBox
    }
    ui->comboBox_Databases->setCurrentText(database);
}



/****CHANGER DE BASE COMBO BOX****/

/**
 * @brief Change de base lorsque l'utilisateur clique sur la combobox
 */

void MainWindow::on_comboBox_Databases_activated(const QString &)
{
    qDebug()<<"void MainWindow::on_comboBox_Databases_activated(const QString &)";
    database=ui->comboBox_Databases->currentText();//On change le nom de la base
    qDebug()<<database;

    //On se connecte a la base séléctionné
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
          db.setHostName(databaseIp);
          db.setDatabaseName(database);
          db.setUserName(username);
          db.setPassword(password);
          bool ok = db.open();
          qDebug()<<ok;
    updateWindowTitle();
    ui->listWidget_Table->clear();//On clear la liste
    ui->tableWidget_Table->clear();//On clear le contenu des tables

    int nbCol = ui->tableWidget_Table->columnCount();//Compte le combre de colonne
    for (int i = nbCol; i >= 0 ; i-- )//Tant que colonne supérieur ou égal à 0
    {
        ui->tableWidget_Table->removeColumn(i);//La colonne est supprmée
    }

    afficherListeTable();//On réaffiche les tables
}



/*********BOUTONS CLEAR***********/

//Dans le mainwindow.h private slots :
//on_pushButtonClearRequest_clicked()
//on_pushButtonClearResult_clicked()


void MainWindow::on_pushButtonClearRequest_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonClearRequest_clicked()";
    ui->plainTextEdit_RequeteSQL->clear();//Clear le plainText
}

void MainWindow::on_pushButtonClearResult_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonClearResult_clicked()";

    ui->tableWidgetRequestResult->clear();//Clear le contenu de la table

    int nbCol = ui->tableWidgetRequestResult->columnCount();//Compte le combre de colonne
    for (int i = nbCol; i >= 0 ; i-- )//Tant que colonne supérieur ou égal à 0
    {
        ui->tableWidgetRequestResult->removeColumn(i);//La colonne est supprmée
    }
}
