#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconnexion.h"
#include "theo.cpp"
#include "ugo.cpp"
#include "remi.cpp"
#include "nolann.cpp"
#include "jonathan.cpp"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
