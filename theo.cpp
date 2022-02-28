#include "mainwindow.h"

#include <QSqlQuery>
#include <QDebug>
/**
 * @brief MainWindow::pushButton_Executer
 * Fonction de récupération de la requete utilisateur
 * depuis le plainTextEdit_RequeteSQL.
 * Puis Execute la commande dans la base de donnée.
 */
void MainWindow::pushButton_Executer(){
    //Déclaration d'une variable de récupération de la requete SQL
    QString requeteSQL;
    requeteSQL=ui->plainTextEdit_RequeteSQL->toPlainText();
    //Execute la commande sur la base de donnée
    QSqlQuery query_resultat(requeteSQL);
    while(query_resultat.next())
    {

            int compteurNbrColonne;
            int compteurNbrColonneMax;
            QString nomColonne="select count(COLUMN_NAME) from INFORMATION_SCHEMA.COLUMNS where table_name='livre';";
            QSqlQuery query_resultat2(nomColonne);
            QString resultatDef;
            while(query_resultat2.next()){
                compteurNbrColonneMax=query_resultat2.value(0).toInt();
                qDebug()<<compteurNbrColonneMax;
                for (compteurNbrColonne=0;compteurNbrColonne<compteurNbrColonneMax;compteurNbrColonne++) {
                    qDebug()<<"resultatDef"<<resultatDef;
                    resultatDef=resultatDef+" "+query_resultat.value(compteurNbrColonne).toString();

                }
                ui->textBrowser_ResultatRequete->setText(resultatDef);
            }




     }

}
