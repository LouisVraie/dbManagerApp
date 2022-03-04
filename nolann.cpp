#include "mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <QCheckBox>

void MainWindow::afficherTableUtilisateur()
{
    qDebug()<<"void MainWindow::afficherTableUtilisateur()";

    // AFFICHAGE DU HEADER DE LA TABLE
    nbColonnes = 0;
    req = "DESC "+currentTable;
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
    /*if(filter != "")
        req = "SELECT * FROM "+currentTable+" WHERE "+filter;
    else*/
        req = "SELECT * FROM "+currentTable;
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

// MÉTHODE SUPPRIMER
void MainWindow::on_pushButton_Supprimer_clicked()
{
    qDebug()<<"void MainWindow::on_pushButton_Supprimer_clicked()";
    int nbChecked = 0;
    int ligne = ui->tableWidget_Table->rowCount()-1;
    QList<int>listeSupprimer;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidget_Table->cellWidget(noLigne,0)))->isChecked())
        {
            nbChecked++;
            listeSupprimer.append(noLigne);
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
                req = "DELETE FROM "+currentTable+" WHERE "+ui->tableWidget_Table->horizontalHeaderItem(1)->text()+"='"+ui->tableWidget_Table->item(listeSupprimer.at(i),1)->text()+"'";
                //qDebug()<<listeSupprimer.at(i);
                for(int j=1;j<=nbColonnes;j++)
                {
                    req += " AND "+ui->tableWidget_Table->horizontalHeaderItem(j)->text()+"='"+ui->tableWidget_Table->item(listeSupprimer.at(i),j)->text()+"'";
                }
                qDebug()<<req;
                QSqlQuery query(req);
                QString errorMessage=query.lastError().text();
                ui->textBrowserRequestResult->setText(errorMessage);
                listeSupprimer.removeLast();
            }
            afficherTableUtilisateur();
            nbChecked = 0;
        }
    }
    else
    {
        ui->textBrowserRequestResult->setText("No rows selected !");
    }
}

