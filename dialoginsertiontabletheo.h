#ifndef DIALOGINSERTIONTABLETHEO_H
#define DIALOGINSERTIONTABLETHEO_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class DialogInsertionTableTheo;
}

class DialogInsertionTableTheo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogInsertionTableTheo(QWidget *parent = nullptr);
    ~DialogInsertionTableTheo();
    QString nomTableSelectionner;

    //creation des lignes
    void createNewLigne();

    //creation des colonnes
    void createColonne(QString nomColonne);
    void getNomTableSelectionner(QString nomTableChoisi);


    //affichage console
    void affichageConsole(QString commande);

    //confirmation exit
    bool quitConfirm();




private slots:
    void on_pushButtonAddLigne_clicked();

    void on_pushButtonEnregistrer_clicked();

    void on_pushButtonAnnuler_clicked();

    //fonction qui recupere le nom de la table
    QString takeNameTable();

    void on_lineEditDatabaseName_textEdited(const QString &arg1);
    void activeDesactiveSize();

private:
    Ui::DialogInsertionTableTheo *ui;
    QComboBox* type;
    QLineEdit* size;
};

#endif // DIALOGINSERTIONTABLETHEO_H
