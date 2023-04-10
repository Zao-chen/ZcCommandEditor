#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    item->setText("test");
}

