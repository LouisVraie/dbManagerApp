#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = nullptr);
    ~DialogConnexion();
/*
    QString getUsername();

    QString getPassword();

    QString getDatabaseName();

    QString getDatabaseIP();
*/
private slots:
    void on_pushButtonDialogDelete_clicked();

    void on_pushButtonDialogConnection_clicked();


private:
    Ui::DialogConnexion *ui;

    QString username, password, databaseName, databaseIP;
};

#endif // DIALOGCONNEXION_H
