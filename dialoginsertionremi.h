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

private:
    Ui::DialogInsertionRemi *ui;
};

#endif // DIALOGINSERTIONREMI_H
