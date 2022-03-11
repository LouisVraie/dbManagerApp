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
#include <QFile>
#include <QVector>

DialogInsertionTableTheo::DialogInsertionTableTheo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionTableTheo)
{
    ui->setupUi(this);

    ui->tableWidgetInsertion->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetInsertion->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    qDebug()<<"connect";

    createNewLigne();
    activeDesactiveSize();
    connect(type,SIGNAL(currentTextChanged(QString)),this,SLOT(activeDesactiveSize()));
    qDebug()<<"apres connect";
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
    int ligne = ui->tableWidgetInsertion->rowCount()-1;
    qDebug()<<ligne;
    type= new QComboBox(ui->tableWidgetInsertion);
    size=new QLineEdit(ui->tableWidgetInsertion);
    QFile file("../dbManagerApp/dataTypes.txt");
    QVector <QString> strings;
    int ligneType =0;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd()) {
            strings.append(in.readLine().split(" ").toVector());

            QString Type=strings[ligneType];
            ligneType++;
            type->addItem(Type);
            qDebug()<<"Types :"<<type;
        }
    }
    ui->tableWidgetInsertion->setCellWidget(ligne,1,type);
    ui->tableWidgetInsertion->setCellWidget(ligne,2,size);
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
    QString nom = ui->tableWidgetInsertion->item(0,0)->text();
    bool key = ui->tableWidgetInsertion->item(0,3);
    QString Prymarykey;
    if(key==true){Prymarykey="Primary Key";}
    else{Prymarykey="";}
    //declaration de la requete de creation de table
    QString txtRequeteCreationTable = "CREATE TABLE "+takeNameTable()+"( "+nom+" "+type->currentText()+" "+size->text()+" "+Prymarykey+"";
    qDebug()<<txtRequeteCreationTable;
    //pour chaque ligne du QTableWidget
    for (int nombreLigne = 1; nombreLigne < ui->tableWidgetInsertion->rowCount(); nombreLigne++)
    {

        txtRequeteCreationTable +=","+nom+" "+type->currentText()+" "+size->text()+" "+Prymarykey+"";
        //on complete la requete pour qu'elle insere
        //on execute la requete
        /*QSqlQuery envoie(requeteInsertion);
        qDebug()<<"requeteInsertion"<<requeteInsertion;

        //on affiche si la requete a reussi, ou le message d'erreur en cas d'echec
        if(envoie.lastError().text() == " "){
            affichageConsole(requeteInsertion + " : " + "The request was successful");
        }
        else {
            affichageConsole(requeteInsertion + " : " + envoie.lastError().text());
        }*/

    }
    txtRequeteCreationTable += ");";
    qDebug()<<"Requete Finit"<<txtRequeteCreationTable;
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

void DialogInsertionTableTheo::activeDesactiveSize()
{
    QString typ=type->currentText();
    qDebug()<<"Type Selectionne :"<<type;
    bool active= typ=="VARCHAR"|| typ=="NUMERIC" ||typ=="SET" || typ== "ENUM" || typ== "TINYTEXT" || typ=="TEXT" || typ=="MEDIUMTEXT" || typ=="LONGTEXT" || typ=="INT" || typ=="INTEGER" || typ=="FLOAT";
    size->setEnabled(active);
}
