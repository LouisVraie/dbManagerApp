#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"

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
