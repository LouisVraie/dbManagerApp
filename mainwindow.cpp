#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconnexion.h"
#include "jonathan.cpp"
#include "remi.cpp"
#include "nolann.cpp"
#include "ugo.cpp"
#include "theo.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowTitle("dbManagerApp - "+databaseName+" - "+databaseIp+" - "+databaseUser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

