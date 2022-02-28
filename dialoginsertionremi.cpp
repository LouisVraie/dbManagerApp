#include "dialoginsertionremi.h"
#include "ui_dialoginsertionremi.h"
#include <QLabel>
#include <QLineEdit>

DialogInsertionRemi::DialogInsertionRemi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionRemi)
{
    ui->setupUi(this);
    for(int cpt=0;cpt<5;cpt++)
    {
        ui->
    }
}

DialogInsertionRemi::~DialogInsertionRemi()
{
    delete ui;
}
