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
      QLabel * nouveauLabel=new QLabel(this);
      nouveauLabel->setText("ploum"+QString::number(cpt));
      QLineEdit * nouvelleZoneDeSaisie= new QLineEdit(this);
      ui->formLayout->addRow(nouveauLabel, nouvelleZoneDeSaisie);
    }
}

DialogInsertionRemi::~DialogInsertionRemi()
{
    delete ui;
}
