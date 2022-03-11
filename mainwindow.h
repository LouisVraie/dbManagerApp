#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QVector>

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

    //louis.cpp
    void updateWindowTitle();

    //ugo.cpp
    void afficherListeTable();
    void remplirComboBox();

    //remi.cpp
    bool quitConfirm();
    void closeEvent(QCloseEvent *event);
    static QString gestionSpecialCaractere(QString chaine);

private slots:
    //nolann.cpp
    void afficherTableUtilisateur();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_Sauvegarder_clicked();

    //ugo.cpp
    void on_listWidget_Table_itemClicked(QListWidgetItem *item);
    void on_comboBox_Databases_activated(const QString &);
    void on_pushButtonClearRequest_clicked();
    void on_pushButtonClearResult_clicked();

    //theo.cpp
    void on_pushButton_Executer_clicked();
    void afficherTableauUserRequest();
    void on_pushButton_AddTable_clicked();

    //jonathan.cpp
    void on_action_Quiter_triggered();

    //remi.cpp
    void on_pushButton_Ajouter_clicked();
    void on_action_Disconnect_triggered();

    //louis.cpp
    void on_pushButtonFilter_clicked();


private:
    Ui::MainWindow *ui;
    //nolann.cpp
    QString req,nomColonne,resultat;
    int nbColonnes,nbLignes;
    QVector<QVector<QString>> vectUserTable;

    //ugo.cpp
    QString currentTable;

    //louis.cpp
    QString username, password, database, databaseIp;
    QString filter;
};

#endif // MAINWINDOW_H
