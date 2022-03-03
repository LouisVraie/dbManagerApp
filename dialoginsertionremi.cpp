#include "dialoginsertionremi.h"
#include "ui_dialoginsertionremi.h"
#include <QLabel>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QLineEdit>

DialogInsertionRemi::DialogInsertionRemi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionRemi)
{
    ui->setupUi(this);
    createTableColonne(nomTableSelectionner);
}

/**
 * @brief Ceci est le destructeur de la fenetre DialogInsertionRemi
 */
DialogInsertionRemi::~DialogInsertionRemi()
{
    delete ui;
}

/**
 * @brief insertion d'une nouvelle ligne dans le TableWidget
 */
void DialogInsertionRemi::createNewLigne()
{
    qDebug()<<"DialogInsertionRemi::createLigne";
    //compte le nombre de ligne existant et créé la suivante
    ui->tableWidgetInsertion->insertRow(ui->tableWidgetInsertion->rowCount());
}

/**
 * @brief Insertion d'une colonne dans le TableWidget et modifie son nom
 * @param nomColonne : Contient le nom de la colonne a mettre dans la colonne qui va etre créé
 */
void DialogInsertionRemi::createColonne(QString nomColonne)
{
    qDebug()<<"DialogInsertionRemi::createColonne";

    //insert une nouvelle colonne
    ui->tableWidgetInsertion->insertColumn(ui->tableWidgetInsertion->columnCount());

    //modifie le nom de la colonne
    ui->tableWidgetInsertion->setHorizontalHeaderItem(ui->tableWidgetInsertion->columnCount()-1, new QTableWidgetItem (nomColonne));
}

/**
 * @brief Cette fonction permet de creer le nombre de colonne adequat pouvant contenir tous les champs de la table
 * passé en parametre, et les renommes
 * @param nomDeLaTable : QString contenant le nom de la table dont on souhaite creer les colonnes
 */
void DialogInsertionRemi::createTableColonne(QString nomDeLaTable)
{
    qDebug()<<"DialogInsertionRemi::createTableColonne(QString nomDeLaTable)";

    QString requeteColonne = "DESC "+nomDeLaTable;
    qDebug()<<"requeteColonne = "<<requeteColonne;

    QSqlQuery query(requeteColonne);

    //tant qu'il existe une requete suivante
    while (query.next())
    {
        //on utilise la fonction createColonne et on donne le titre de la colonne a atribué
        createColonne(query.value(0).toString());
    }
}

/**
 * @brief Cette fonction permet de recuperer le nom de la table contenu dans le QListWidget de la mainWindow
 * @param nomTableChoisi : QString contenant le nom de la table selectionnée
 */
void DialogInsertionRemi::getNomTableSelectionner(QString nomTableChoisi)
{
    qDebug()<<"DialogInsertionRemi::getNomTableSelectionner()";

    //on recupere la valeur et on la met dans la variable privé de la classe DialogInsertionRemi
    nomTableSelectionner = nomTableChoisi;
    qDebug()<<"nomTableSelectionner"<<nomTableSelectionner;
}

/**
 * @brief Cette fonction permet de faire appel a la fonction createNewLigne pour ajouter une ligne au QTableWidget
 */
void DialogInsertionRemi::on_pushButtonAddLigne_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonAddLigne_clicked";

    //creation d'une nouvelle ligne
    createNewLigne();
}


void DialogInsertionRemi::on_pushButtonEnregistrer_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonEnregistrer_clicked";

    //pour chaque ligne du QTableWidget
    for (int nombreLigne = 0; nombreLigne < ui->tableWidgetInsertion->rowCount(); nombreLigne++)
    {
        //pour chaque colonne
            //on recupere l'informations de l'item corespondant
            //on push tout dans un vecteur

       //
    }
}
