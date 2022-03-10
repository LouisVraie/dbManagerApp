#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoginsertiontabletheo.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>
/**
 * @brief MainWindow::pushButton_Executer
 * Fonction de récupération de la requete utilisateur
 * depuis le plainTextEdit_RequeteSQL.
 * Puis Execute la commande dans la base de donnée.
 */

void MainWindow::on_pushButton_Executer_clicked(){
    //Déclaration d'une variable de récupération de la requete SQL
    QString requeteSQL;
    QString resultatError;
    requeteSQL=ui->plainTextEdit_RequeteSQL->toPlainText();
    //Execute la commande sur la base de donnée
    QSqlQuery query_resultat(requeteSQL);
    resultatError=query_resultat.lastError().text();
    QString sDate = QDateTime::currentDateTime().toString("[dd/MM/yyyy hh:mm:ss]");
    if(resultatError!=" "){
        ui->textBrowserRequestResult->setText(sDate+" "+resultatError);
    }
    else {
        ui->textBrowserRequestResult->setText(sDate+"Successful request");
    }

    afficherTableauUserRequest();

}

void MainWindow::afficherTableauUserRequest(){
    //Déclaration d'une variable de récupération de la requete SQL
    QString requeteSQL;
    requeteSQL=ui->plainTextEdit_RequeteSQL->toPlainText();
    //requeteSQL="show tables;";
    //Execute la commande sur la base de donnée
    QSqlQuery query_resultat(requeteSQL);
    // AFFICHAGE DU CONTENU DE LA TABLE
    nbLignes = 0;
    //on efface
    ui->tableWidgetRequestResult->setRowCount(0);
    ui->tableWidgetRequestResult->setColumnCount(0);
    int nbColonne=query_resultat.record().count();
    ui->tableWidgetRequestResult->setColumnCount(nbColonne);
    int nbLigne=query_resultat.numRowsAffected();
    ui->tableWidgetRequestResult->setRowCount(nbLigne);
    int noLigne=0;


    if(requeteSQL.trimmed().left(6).toUpper()=="SELECT" || requeteSQL.trimmed().left(4).toUpper()=="DESC" || requeteSQL.trimmed().left(4).toUpper()=="SHOW")
    {
        for(int noChamp=0;noChamp<nbColonne;noChamp++)
        {
            ui->tableWidgetRequestResult->setHorizontalHeaderItem(noChamp,new QTableWidgetItem(query_resultat.record().fieldName(noChamp)));
        }
    }

    while(query_resultat.next())
    {

        for (int noCol=0;noCol<nbColonne;noCol++) {
            ui->tableWidgetRequestResult->setItem(noLigne,noCol,new QTableWidgetItem(query_resultat.value(noCol).toString()));
        }
        noLigne++;

    }

}
void MainWindow::on_pushButton_AddTable_clicked()
{
    qDebug()<<"MainWindow::on_pushButton_AddTable_clicked";
    DialogInsertionTableTheo insertion;
    insertion.exec();
}

