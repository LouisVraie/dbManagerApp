#include "mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QCheckBox>

void MainWindow::afficherTableUtilisateur()
{
    nomTable = currentTable;/*NOM DA LA TABLE */

    // AFFICHAGE DU HEADER DE LA TABLE
    nbColonnes = 0;
    req = "DESC "+nomTable;
    QSqlQuery query(req);
    while(query.next())
    {
        nbColonnes++;
        ui->tableWidget_Table->setColumnCount(nbColonnes+1);
        nomColonne = query.value(0).toString();
        qDebug()<<nomColonne;

        ui->tableWidget_Table->setHorizontalHeaderItem(nbColonnes,new QTableWidgetItem (nomColonne));
    }
    ui->tableWidget_Table->setHorizontalHeaderItem(0,new QTableWidgetItem (""));

    ui->tableWidget_Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // AFFICHAGE DU CONTENU DE LA TABLE
    nbLignes = 0;
    req = "SELECT * FROM "+nomTable;
    QSqlQuery query_resultat(req);
    while(query_resultat.next())
    {
        nbLignes++;
        ui->tableWidget_Table->setRowCount(nbLignes);
        ui->tableWidget_Table->setCellWidget(nbLignes-1,0,new QCheckBox);
        for(int i=1;i<=nbColonnes;i++)
        {
            resultat = query_resultat.value(i-1).toString();
            ui->tableWidget_Table->setItem(nbLignes-1,i,new QTableWidgetItem(resultat));
        }
    }
}
