#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString txtAfficheTable ="SHOW TABLES;";//Ligne de code sql en string
    QSqlQuery reqAfficheTable(txtAfficheTable);//Convertit la requête en Sql
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_Table_itemClicked(QListWidgetItem *item)
{
    QString currentTable;//Variable pour connaitre quel table est cliqué
    currentTable=ui->listWidget_Table->currentItem()->text();//Met à jour la variable
    qDebug()<<currentTable;
}
