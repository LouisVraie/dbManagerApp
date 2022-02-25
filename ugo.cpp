//ajouter en public dans le maiwindow.h
//void AfficherTable();
//void on_listWidget_Table_itemClicked(QListWidgetItem *item);
//QString currentTable 

#include "mainwindow.h"
#include <QMainWindow>	
#include <QListWidget>
#include <QSqlQuery>
#include <QDebug>

void MainWindow::afficherListeTable()//Méthode pour afficher les tables de la base
{

    QString txtAfficheTable ="SHOW TABLES;";//Ligne de code sql en string
    QSqlQuery reqAfficheTable(txtAfficheTable);//Convertit la requête en Sql
    qDebug()<<txtAfficheTable;

    while (reqAfficheTable.next()) {//Tant qu'on peut passer au prochain
        QString nomTable=reqAfficheTable.value(0).toString();//On récupère le nom de la table
        ui->listWidget_Table->addItem(nomTable);//Et on l'affiche
    }
}

void MainWindow::on_listWidget_Table_itemClicked(QListWidgetItem *item)
{
    this->currentTable=item->text();//Met à jour la variable
    qDebug()<<currentTable;
    afficherTableUtilisateur();
}
