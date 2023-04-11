#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

int global_row;
int global_column;

struct save_map //保存东西的结构体
{
    bool has_block = false; //是否有方块
}save_map_class[10][10];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*初始化*/
    ui->setupUi(this);

    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(40); //设置默认大小
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可更改

    ui->tableWidget->setColumnCount(10); //设置表格内容
    ui->tableWidget->setRowCount(10);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*点击单元格槽*/
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    global_row = row;
    global_column = column;
    ui->label_location->setText("选中方块：( " + QString::number(row+1) + " , " + QString::number(column+1)+" )");
    ui->checkBox_hasblock->setChecked(save_map_class[row][column].has_block);
    //ui->tableWidget->setEditTriggers(QAbstractItemView::CurrentChanged); //设置可更改
    //ui->tableWidget->item(row,column)->setText("O");
    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可更改
}

void MainWindow::on_checkBox_hasblock_clicked(bool checked)
{
    save_map_class[global_row][global_column].has_block = checked;
}
