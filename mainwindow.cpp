#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialoginsertionremi.h"
#include "jonathan.cpp"
#include "remi.cpp"
#include "nolann.cpp"
#include "ugo.cpp"
#include "theo.cpp"
#include "louis.cpp"

/**
 * @brief MainWindow::MainWindow
 * Constructeur de la MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow
 * Destructeur de la MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::connection
 * Méthode publique de la classe MainWindow qui affiche la fenêtre de connexion et initialise la MainWindow
 * @return bool Booléen
 */
bool MainWindow::connection()
{
    qDebug()<<"bool MainWindow::connection()";
    DialogConnexion connexion;

    if(connexion.exec()==QDialog::Accepted) {
        //initialisation des champs et des propriétés
        initInputs();

        //récupération des informations de connexion et initialisation des champs
        username = connexion.getUsername();
        password = connexion.getPassword();
        database = connexion.getDatabaseName();
        databaseIp = connexion.getDatabaseIP();

        setWindowTitle("dbManagerApp - "+database+" - "+username+"@"+databaseIp);

        remplirComboBox();
        afficherListeTable();
        return true;
    } else {
        return false;
    }
}

/**
 * @brief MainWindow::initInputs
 * Méthode publique de la classe MainWindow qui initialise les propriétés et les inputs
 */
void MainWindow::initInputs()
{
    qDebug()<<"void MainWindow::initInputs()";
    //nolann.cpp
    nomTable = "";
    req = "";
    nomColonne = "";
    resultat = "";
    nbColonnes = 0;
    nbLignes = 0;

    //ugo.cpp
    currentTable = "";

    //louis.cpp
    username = "";
    password = "";
    database = "";
    databaseIp = "";
    filter = "";

    //user table
    ui->lineEditFilter->setText("");
    ui->textBrowserActionResult->setText("");

    //user request
    on_pushButtonClearRequest_clicked();
    on_pushButtonClearResult_clicked();
}

/**
 * @brief MainWindow::on_pushButtonFilter_clicked
 * Méthode private slots
 */
void MainWindow::on_pushButtonFilter_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonFilter_clicked()";
}
