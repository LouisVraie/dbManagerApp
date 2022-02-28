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
 * @return bool
 */
bool MainWindow::connection()
{
    DialogConnexion connexion;

    if(connexion.exec()==QDialog::Accepted) {
        //récupération des informations de connexion
        username = connexion.getUsername();
        password = connexion.getPassword();
        database = connexion.getDatabaseName();
        databaseIp = connexion.getDatabaseIP();

        //setWindowTitle("dbManagerApp - "+databaseName+" - "+databaseIp+" - "+databaseUser);

        remplirComboBox();
        afficherListeTable();
        return true;
    } else {
        return false;
    }
}
