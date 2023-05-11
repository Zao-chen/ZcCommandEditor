#ifndef UPDATE_UI_H
#define UPDATE_UI_H

#include <QDialog>

namespace Ui {
class update_ui;
}

class update_ui : public QDialog
{
    Q_OBJECT

public:
    explicit update_ui(QWidget *parent = nullptr);
    ~update_ui();

private:
    Ui::update_ui *ui;
};

#endif // UPDATE_UI_H
