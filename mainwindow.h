#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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
    void afficherListeTable();

    //remi.cpp
    bool quitConfirm();
    void closeEvent(QCloseEvent *event);

private slots:
    //nolann.cpp
    void afficherTableUtilisateur();

    //ugo.cpp
    void on_listWidget_Table_itemClicked(QListWidgetItem *item);

    //theo.cpp
    void pushButton_Executer();

private:
    Ui::MainWindow *ui;
    //nolann.cpp
    QString nomTable,req,nomColonne,resultat;
    int nbColonnes,nbLignes;

    //ugo.cpp
    QString currentTable;
};

#endif // MAINWINDOW_H
