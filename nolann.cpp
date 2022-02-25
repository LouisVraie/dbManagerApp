#include "mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QDebug>

void MainWindow::afficherTableUtilisateur()
{
    nomTable = "";/*NOM DA LA TABLE */

    // AFFICHAGE DU HEADER DE LA TABLE
    nbColonnes = 0;
    req = "DESC "+nomTable;
    QSqlQuery query(req);
    while(query.next())
    {
        nbColonnes++;
        ui->tableWidget_Table->setColumnCount(nbColonnes);
        nomColonne = query.value(0).toString();
        qDebug()<<nomColonne;

        ui->tableWidget_Table->setHorizontalHeaderItem(nbColonnes-1,new QTableWidgetItem (nomColonne));
    }
    ui->tableWidget_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // AFFICHAGE DU CONTENU DE LA TABLE
    nbLignes = 0;
    req = "SELECT * FROM "+nomTable;
    QSqlQuery query_resultat(req);
    while(query_resultat.next())
    {
        nbLignes++;
        ui->tableWidget_Table->setRowCount(nbLignes);
        for(int i=0;i<=nbColonnes;i++)
        {
            resultat = query_resultat.value(i).toString();
            ui->tableWidget_Table->setItem(nbLignes-1,i,new QTableWidgetItem(resultat));
        }
    }
}
