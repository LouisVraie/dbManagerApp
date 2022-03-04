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

    bool connection();
    void initInputs();

    //ugo.cpp
    void afficherListeTable();
    void remplirComboBox();

    //remi.cpp
    bool quitConfirm();
    void closeEvent(QCloseEvent *event);
    QString gestionSpecialCaractere(QString chaine);

private slots:
    //nolann.cpp
    void afficherTableUtilisateur();
    void on_pushButton_Supprimer_clicked();

    //ugo.cpp
    void on_listWidget_Table_itemClicked(QListWidgetItem *item);
    void on_comboBox_Databases_activated(const QString &);
    void on_pushButtonClearRequest_clicked();
    void on_pushButtonClearResult_clicked();

    //theo.cpp
    void on_pushButton_Executer_clicked();
    void afficherTableauUserRequest();

    //jonathan.cpp
    void on_action_Quiter_triggered();

    //remi.cpp
    void on_pushButton_Ajouter_clicked();
    void on_action_Disconnect_triggered();

    void on_pushButtonFilter_clicked();

private:
    Ui::MainWindow *ui;
    //nolann.cpp
    QString nomTable,req,nomColonne,resultat;
    int nbColonnes,nbLignes;

    //ugo.cpp
    QString currentTable;

    //louis.cpp
    QString username, password, database, databaseIp;
    QString filter;
};

#endif // MAINWINDOW_H
