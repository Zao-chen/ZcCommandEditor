#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString code; //网页源代码
    QByteArray InitGetRequest(QString url, QString obj);
    QStringList strl;


private slots:

    void on_tableWidget_cellClicked(int row, int column);

    void on_type_comboBox_activated(int index);

    void on_toward_comboBox_activated(int index);

    void on_condition_comboBox_activated(int index);

    /*菜单操作*/
    void on_menu_save_clicked();
    void on_menu_load_clicked();
    void on_menu_help_clicked();
    void on_menu_github_clicked();
    void on_menu_updata_clicked();

    void on_content_textEdit_textChanged();

    void on_redstone_comboBox_activated(int index);

    void on_notes_content_textEdit_textChanged();

    void on_block_comboBox_activated(int index);

    void on_delay_lineEdit_3_textChanged(const QString &arg1);

    void on_checkBox_clicked(bool checked);

    void on_name_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_search_clicked();

    void on_delet_pushButton_clicked();

    void on_copy_pushButton_clicked();

    void on_openminiwin_pushButton_clicked();

protected:
    void keyPressEvent(QKeyEvent *event); //键盘按下事件

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
