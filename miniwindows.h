#ifndef MINIWINDOWS_H
#define MINIWINDOWS_H

#include "hook.h"

#include <QWidget>

namespace Ui {
class miniwindows;
}

class miniwindows : public QWidget
{
    Q_OBJECT

public:
    explicit miniwindows(QWidget *parent = nullptr);
    ~miniwindows();

protected:
    /*鼠标相关事件*/
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event); //键盘按下事件
private slots:
    void on_tableWidget_cellClicked(int row, int column);
    void checkType(Hook::Type);

private:
    /*鼠标相关参数*/
    QPoint mousePoint;
    bool mouse_press;
    Ui::miniwindows *ui;
    Hook hook;//钩子对象
};

#endif // MINIWINDOWS_H
