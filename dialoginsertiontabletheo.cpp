#include "dialoginsertiontabletheo.h"
#include "ui_dialoginsertiontabletheo.h"
#include <QLabel>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QLineEdit>
#include <QVector>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSqlError>
#include <QScrollBar>
#include <QComboBox>
#include <QCheckBox>

DialogInsertionTableTheo::DialogInsertionTableTheo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionTableTheo)
{
    ui->setupUi(this);
    ui->tableWidgetInsertion->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetInsertion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    createNewLigne();
}

DialogInsertionTableTheo::~DialogInsertionTableTheo()
{
    delete ui;
}

/**
 * @brief insertion d'une nouvelle ligne dans le TableWidget
 */
void DialogInsertionTableTheo::createNewLigne()
{
    qDebug()<<"DialogInsertionRemi::createLigne";
    //compte le nombre de ligne existant et créé la suivante
    ui->tableWidgetInsertion->insertRow(ui->tableWidgetInsertion->rowCount());
    QComboBox* myComboBox = new QComboBox();
    int ligne = ui->tableWidgetInsertion->rowCount()-1;
    qDebug()<<ligne;
    ui->tableWidgetInsertion->setCellWidget(ligne,1,myComboBox);
    ui->tableWidgetInsertion->setCellWidget(ligne,3,new QCheckBox);
}
/**
 * @brief Cette fonction permet de recuperer le nom de la table contenu dans le QListWidget de la mainWindow
 * @param nomTableChoisi : QString contenant le nom de la table selectionnée
 */
void DialogInsertionTableTheo::getNomTableSelectionner(QString nomTableChoisi)
{
    qDebug()<<"DialogInsertionRemi::getNomTableSelectionner()";

    //on recupere la valeur et on la met dans la variable privé de la classe DialogInsertionRemi
    nomTableSelectionner = nomTableChoisi;
    qDebug()<<"nomTableSelectionner"<<nomTableSelectionner;
}

/**
 * @brief Cette fonction permet de rajouter une ligne dans la console.
 * @param commande : QString comportant la ligne à faire afficher dans la console
 */
void DialogInsertionTableTheo::affichageConsole(QString commande)
{
    qDebug()<<"void DialogInsertionRemi::affichageConsole(QString commande)";

    //on ajoute une ligne dans la Console
    ui->textBrowserResultatError->append(commande);
}

/**
 * @brief Cette fonction permet de faire appel a la fonction createNewLigne pour ajouter une ligne au QTableWidget
 */
void DialogInsertionTableTheo::on_pushButtonAddLigne_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonAddLigne_clicked";

    //creation d'une nouvelle ligne
    createNewLigne();
}


void DialogInsertionTableTheo::on_pushButtonEnregistrer_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonEnregistrer_clicked";

    //requete sql pour avoir les types de valeurs des champs
    QString requeteTypeChamp = "DESC "+nomTableSelectionner;
    qDebug()<<"requeteTypeChamp = "<<requeteTypeChamp;

    QSqlQuery query(requeteTypeChamp);

    //on créé le vector
    QVector<QString> listeTypeChamps;

    //tant qu'il existe une requete suivante
    while (query.next())
    {
        //on push les types des champsdans un vector
        listeTypeChamps.push_back( query.value(1).toString() );
    }

    //pour chaque ligne du QTableWidget
    for (int nombreLigne = 0; nombreLigne < ui->tableWidgetInsertion->rowCount(); nombreLigne++)
    {
        //declaration de la requete d'insertion
        QString requeteInsertion = "INSERT INTO " + nomTableSelectionner + " VALUES (";

        //pour chaque colonne
        for (int nombreColonne = 0; nombreColonne < ui->tableWidgetInsertion->columnCount(); nombreColonne++ )
        {
            //on créé une variable string qui contient la valeur de l'item selectionné
            QString valeurItem = ui->tableWidgetInsertion->item(nombreLigne, nombreColonne)->text();

            qDebug()<<"vector = "<<listeTypeChamps;
            //si le champ est un varchar
            if (listeTypeChamps[nombreColonne].left(7) =="varchar" || listeTypeChamps[nombreColonne].left(4) == "date" || listeTypeChamps[nombreColonne].left(4) == "time")
            {
                requeteInsertion += "'" + valeurItem + "', ";
            }
            else {
                requeteInsertion += valeurItem + ", ";
            }
        }
        //on complete la requete pour qu'elle insere
        //supprime les 2 derniers caracteres pour enlever ", "
        requeteInsertion = requeteInsertion.remove(requeteInsertion.size()-2, 2);
        requeteInsertion += ");";

        //on execute la requete
        QSqlQuery envoie(requeteInsertion);
        qDebug()<<"requeteInsertion"<<requeteInsertion;

        //on affiche si la requete a reussi, ou le message d'erreur en cas d'echec
        if(envoie.lastError().text() == " "){
            affichageConsole(requeteInsertion + " : " + "The request was successful");
        }
        else {
            affichageConsole(requeteInsertion + " : " + envoie.lastError().text());
        }

    }
}

/**
 * @brief Cette fonction permet de reinitialiser le tableWidget quand on clique sur annuler
 */
void DialogInsertionTableTheo::on_pushButtonAnnuler_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonAnnuler_clicked";

    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment Annuler ? Cela entrainera la réinitialisation de tous vos champs", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        if(ui->tableWidgetInsertion->rowCount() > 1)
        {
            ui->tableWidgetInsertion->setRowCount(ui->tableWidgetInsertion->rowCount()-1);

        }
        else if (ui->tableWidgetInsertion->rowCount() == 1) {
            ui->tableWidgetInsertion->setRowCount(0);
        }
    }
}

QString DialogInsertionTableTheo::takeNameTable()
{
    QString nomeTable;
    nomeTable=ui->lineEditDatabaseName->text();
    return nomeTable;
}

void DialogInsertionTableTheo::on_lineEditDatabaseName_textEdited(const QString &arg1)
{
    QString nomeTable;
    nomeTable=arg1;
    ui->label_Requetefinal->setText(nomeTable);
}
