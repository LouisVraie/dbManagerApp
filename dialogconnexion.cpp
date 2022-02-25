#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"

#include <QDebug>

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

void DialogConnexion::on_pushButtonDialogDelete_clicked()
{
    ui->lineEditDialogUsername->setText("");
    ui->lineEditDialogPassword->setText("");
    ui->lineEditDialogDatabaseName->setText("");
    ui->lineEditDatabaseIP->setText("");

}

void DialogConnexion::on_pushButtonDialogConnection_clicked()
{
    //on recupere les info
    username = ui->lineEditDialogUsername->text();
    qDebug()<<username;
    password = ui->lineEditDialogPassword->text();
    qDebug()<<password;
    databaseName = ui->lineEditDialogDatabaseName->text();
    qDebug()<<databaseName;
    databaseIP = ui->lineEditDatabaseIP->text();
    qDebug()<<databaseIP;
    accept();

}

QString DialogConnexion::getUsername()
{
    return username;
}

QString DialogConnexion::getPassword()
{
    return password;
}

QString DialogConnexion::getDatabaseName()
{
    return databaseName;
}

QString DialogConnexion::getDatabaseIP()
{
    return databaseIP;
}
