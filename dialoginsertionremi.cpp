#include "dialoginsertionremi.h"
#include "ui_dialoginsertionremi.h"

DialogInsertionRemi::DialogInsertionRemi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogInsertionRemi)
{
    ui->setupUi(this);
}

DialogInsertionRemi::~DialogInsertionRemi()
{
    delete ui;
}
