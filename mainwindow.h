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
    void remplirComboBox();

    //remi.cpp
    bool quitConfirm();
    void closeEvent(QCloseEvent *event);

    //louis.cpp
    bool connection();

private slots:
    //nolann.cpp
    void afficherTableUtilisateur();

    //ugo.cpp
    void on_listWidget_Table_itemClicked(QListWidgetItem *item);
    void on_comboBox_Databases_activated(const QString &);

    //theo.cpp
    void on_pushButton_Executer_clicked();

    //jonathan.cpp
    void on_action_Quiter_triggered();

    //remi.cpp
    void on_pushButton_Ajouter_clicked();

    void on_action_Disconnect_triggered();

private:
    Ui::MainWindow *ui;
    //nolann.cpp
    QString nomTable,req,nomColonne,resultat;
    int nbColonnes,nbLignes;

    //ugo.cpp
    QString currentTable;

    //louis.cpp
    QString username, password, database, databaseIp;
};

#endif // MAINWINDOW_H
