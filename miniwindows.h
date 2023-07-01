#ifndef MINIWINDOWS_H
#define MINIWINDOWS_H

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
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPoint mousePoint;
    bool mouse_press;
    Ui::miniwindows *ui;
};

#endif // MINIWINDOWS_H
