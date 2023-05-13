#ifndef HELPS_UI_H
#define HELPS_UI_H

#include <QMainWindow>

namespace Ui {
class helps_ui;
}

class helps_ui : public QMainWindow
{
    Q_OBJECT

public:
    explicit helps_ui(QWidget *parent = nullptr);
    ~helps_ui();

private:
    Ui::helps_ui *ui;
};

#endif // HELPS_UI_H
