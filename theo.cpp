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
        ui->textBrowser_ResultatRequete->setText(ui->textBrowser_ResultatRequete->toPlainText()+"\r\n"+sDate+" "+resultatError);
    }
    else {
        ui->textBrowser_ResultatRequete->setText(ui->textBrowser_ResultatRequete->toPlainText()+"\r\n"+sDate+"Successful request");
    }
}

