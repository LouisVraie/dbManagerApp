#include "mainwindow.h"

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
    qDebug()<<"bouton exec";
    //Déclaration d'une variable de récupération de la requete SQL
    QString requeteSQL;
    QString resultatError;
    requeteSQL=ui->plainTextEdit_RequeteSQL->toPlainText();
    //Execute la commande sur la base de donnée
    QSqlQuery query_resultat(requeteSQL);
    resultatError=query_resultat.lastError().text();
    qDebug()<<"ResultatError"<<resultatError;
    QString sDate = QDateTime::currentDateTime().toString("[dd/MM/yyyy hh:mm:ss]");
    if(resultatError!=" "){
        ui->textBrowserRequestResult->setText(sDate+" "+resultatError);
    }
    else {
        ui->textBrowserRequestResult->setText(sDate+"Successful request");
    }
    nomTable = "Achat";//currentTable;/*NOM DA LA TABLE */

    // AFFICHAGE DU HEADER DE LA TABLE
    nbColonnes = 0;
    req = "DESC "+nomTable;
    QSqlQuery query(req);
    while(query.next())
    {
        nbColonnes++;
        ui->tableWidgetRequestResult->setColumnCount(nbColonnes+1);
        nomColonne = query.value(0).toString();
        qDebug()<<nomColonne;

        ui->tableWidgetRequestResult->setHorizontalHeaderItem(nbColonnes,new QTableWidgetItem (nomColonne));
    }
    ui->tableWidgetRequestResult->setHorizontalHeaderItem(0,new QTableWidgetItem (""));

    ui->tableWidgetRequestResult->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // AFFICHAGE DU CONTENU DE LA TABLE
    nbLignes = 0;
    while(query_resultat.next())
    {
        nbLignes++;
        ui->tableWidgetRequestResult->setRowCount(nbLignes);
        ui->tableWidgetRequestResult->setCellWidget(nbLignes-1,0,new QCheckBox);
        for(int i=1;i<=nbColonnes;i++)
        {
            resultat = query_resultat.value(i-1).toString();
            qDebug()<<resultat;
            ui->tableWidgetRequestResult->setItem(nbLignes-1,i,new QTableWidgetItem(resultat));
        }
    }
}
