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

void MainWindow::on_pushButton_Supprimer_clicked()
{
    nomColonne = ui->tableWidget_Table->horizontalHeaderItem(1)->text();
    qDebug()<<nomColonne;
    int nbChecked = 0;
    int ligne = ui->tableWidget_Table->rowCount()-1;
    QList<QString> listeSupprimer;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidget_Table->cellWidget(noLigne,0)))->isChecked())
        {
            nbChecked++;
            listeSupprimer.append(ui->tableWidget_Table->item(noLigne,1)->text());
        }
    }



    if(nbChecked>0)
    {
        QString texteMessage = "Do you really want to delete these "+QString::number(nbChecked)+" rows ?";
        if (nbChecked == 1) texteMessage = "Do you really want to delete this row ?";
        if(QMessageBox::warning(this,this->windowTitle(),texteMessage, QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)//Si l'utilisateur clique sur "oui"
        {
            //suppression
            for(int i=listeSupprimer.length()-1;i>=0;i--)
            {
                qDebug()<<listeSupprimer.at(i);
                req = "DELETE FROM "+nomTable+" WHERE "+nomColonne+"="+listeSupprimer.at(i);
                qDebug()<<req;
                 QSqlQuery query(req);
                query.next();
                listeSupprimer.removeLast();
            }
            afficherTableUtilisateur();
            nbChecked = 0;
        }
    }
    else
    {
        ui->textBrowserActionResult->setText("No rows selected !");
    }

}



/*int ligne = ui->tableWidgetLivres->rowCount()-1;
    int nbChecked = 0;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        qDebug()<<"for (int noLigne = 0;noLigne <= ligne;noLigne++)";
        if(((QCheckBox*)(ui->tableWidgetLivres->cellWidget(noLigne,7)))->isChecked())
        {
            qDebug()<<"if(((QCheckBox*)(ui->tableWidgetLivres->cellWidget(noLigne,6)))->isChecked())";
            nbChecked++;
            titre = ui->tableWidgetLivres->item(noLigne,1)->text();

            if (QMessageBox::warning(this,"Livres - Suppression",titre+" - Êtes-vous sûr.e de vouloir supprimer ce livre ?",
                                     QMessageBox::Yes|QMessageBox::No,QMessageBox::No)==QMessageBox::Yes)
            {
                req = "UPDATE Livres SET valide = FALSE WHERE numeroLivres = "+ui->tableWidgetLivres->item(noLigne,0)->text();
                //qDebug()<<req;
                QSqlQuery supprimer(req);
            }
        }
    }
    if(nbChecked == 0)
    {
        ui->statusBar->setStyleSheet("color:rgb(252, 62, 62)");
        ui->statusBar->showMessage("Aucune case cochée !",3000);

    }
*/
