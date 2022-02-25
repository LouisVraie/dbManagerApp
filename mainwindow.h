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

private slots:
    //Nolann
    void afficherTableUtilisateur();

private:
    Ui::MainWindow *ui;
    //Nolann
    QString nomTable,req,nomColonne,resultat;
    int nbColonnes,nbLignes;
};

#endif // MAINWINDOW_H
