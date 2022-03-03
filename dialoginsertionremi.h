#ifndef DIALOGINSERTIONREMI_H
#define DIALOGINSERTIONREMI_H

#include <QDialog>

namespace Ui {
class DialogInsertionRemi;
}

class DialogInsertionRemi : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInsertionRemi(QWidget *parent = nullptr);
    ~DialogInsertionRemi();
    QString nomTableSelectionner;

    //creation des lignes
    void createNewLigne();

    //creation des colonnes
    void createColonne(QString nomColonne);
    void createTableColonne(QString nomDeLaTable);   
    void getNomTableSelectionner(QString nomTableChoisi);



private slots:
    void on_pushButtonAddLigne_clicked();

    void on_pushButtonEnregistrer_clicked();

private:
    Ui::DialogInsertionRemi *ui;


};

#endif // DIALOGINSERTIONREMI_H
