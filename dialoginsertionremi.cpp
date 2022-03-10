#include "dialoginsertionremi.h"
#include "ui_dialoginsertionremi.h"
#include "mainwindow.h"
#include <QLabel>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QLineEdit>
#include <QVector>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSqlError>
#include <QScrollBar>
#include <QMap>

DialogInsertionRemi::DialogInsertionRemi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionRemi)
{
    ui->setupUi(this);
    ui->tableWidgetInsertion->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetInsertion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    createNewLigne();
    setWindowTitle("dbManagerApp - Insert Row");
}

/**
 * @brief Ceci est le destructeur de la fenetre DialogInsertionRemi
 */
DialogInsertionRemi::~DialogInsertionRemi()
{
    delete ui;
}

/**
 * @brief Cette fonction sert a verifier si la ligne de tableWidget contient une case ne contenant rien
 * @param numLigneAVerif : Int contenant le numero de la ligne a verifier
 * @return Retourne un booléen vrai si la ligne contient une case vide
 */
bool DialogInsertionRemi::isVide(int numLigneAVerif)
{
    qDebug()<<"DialogInsertionRemi::isVide(QTableWidget tableau, int numLigneAVerif)";

    int nbrColonne = ui->tableWidgetInsertion->columnCount();
    //on defini un bool vide de base signifiant qu'on considere que l'item n'est pas vide de base
    bool isVide = false;

    //pour chaque colonne du TableWidget
    for (int compteur = 0; compteur < nbrColonne; compteur++ ) {
        //on regarde si la 1ere colonne est vide
        if(ui->tableWidgetInsertion->item(numLigneAVerif, compteur)->text() == "")
        {
            isVide = true;
        }
    }
    return isVide;
}

bool DialogInsertionRemi::quitConfirm()
{
    qDebug()<<"MainWindow::quitConfirm()";
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment quitter cette fenêtre ?", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
    {
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Cette fonction permet d'executer la fonction quitConfirm() quand l'utilisateur cherche a fermer la fenetre
 * @param event
 */
void DialogInsertionRemi::closeEvent(QCloseEvent *event)
{
    qDebug()<<"MainWindow::closeEvent(QCloseEvent *event)";
    if(quitConfirm())
    {
        event->accept();
    }
    else {
        event->ignore();
    }
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
 * @brief Cette fonction permet de rajouter une ligne dans la console.
 * @param commande : QString comportant la ligne à faire afficher dans la console
 */
void DialogInsertionRemi::affichageConsole(QString commande)
{
    qDebug()<<"void DialogInsertionRemi::affichageConsole(QString commande)";

    //on ajoute une ligne dans la Console
    ui->textBrowserResultatError->append(commande);
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

/**
 * @brief Cette fonction sert a executer toutes les taches necessaire a l'enregistrement, de la creation de la requete a la verification des caracteres
 * et gere l'affichage des erreurs post execution
 */
void DialogInsertionRemi::on_pushButtonEnregistrer_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonEnregistrer_clicked";

    //on cree un QVector qui contiendra le numero de la ligne ayant une erreur
    QVector<int> listeErreur;

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

    //on creer un bool pour savoir si il va y avoir une erreur plus tard
    bool ifErrorRequete = false;

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

            valeurItem = MainWindow::gestionSpecialCaractere(valeurItem);

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
            affichageConsole(requeteInsertion + "   : " + envoie.lastError().text());
            ifErrorRequete = true;
            //on ajoute la ligne dans le vector contenant la liste des lignes ou se trouve des erreurs
            listeErreur.append(nombreLigne);
        }

    }
    //si y'il n'y a pas d'erreur lors de l'insertion on ferme la fenetre
    if(!ifErrorRequete)
    {
        close();
    }
    else {
        //si y'a des erreurs
        //on boucle a l'envers pour faciliter la suppression
        for(int compteur = ui->tableWidgetInsertion->rowCount(); compteur >= 0; compteur-- )
        {
            //on supprime les lignes qui n'appartiennent pas a la liste des erreurs
            if(!listeErreur.contains(compteur))
            {
                ui->tableWidgetInsertion->removeRow(compteur);
            }
        }
    }
}

/**
 * @brief Cette fonction permet de reinitialiser le tableWidget quand on clique sur annuler
 */
void DialogInsertionRemi::on_pushButtonAnnuler_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonAnnuler_clicked";

    if(ui->tableWidgetInsertion->rowCount() > 1)
    {
        ui->tableWidgetInsertion->setRowCount(ui->tableWidgetInsertion->rowCount()-1);

    }
    else if (ui->tableWidgetInsertion->rowCount() == 1) {
        ui->tableWidgetInsertion->setRowCount(0);
    }
}

void DialogInsertionRemi::on_pushButtonQuitter_clicked()
{
    qDebug()<<"DialogInsertionRemi::on_pushButtonQuitter_clicked";

    close();
}
