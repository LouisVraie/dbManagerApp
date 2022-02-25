#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //ugo.cpp
    void AfficherTable();

private slots:
    //nolann.cpp
    void afficherTableUtilisateur();

    //ugo.cpp
    void on_listWidget_Table_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
    //nolann.cpp
    QString nomTable,req,nomColonne,resultat;
    int nbColonnes,nbLignes;

    //ugo.cpp
    QString currentTable;
};

#endif // MAINWINDOW_H
