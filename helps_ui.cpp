#include "helps_ui.h"
#include "ui_helps_ui.h"

helps_ui::helps_ui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helps_ui)
{
    ui->setupUi(this);
    setWindowTitle("快捷方式");
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(150); //设置默认大小
}

helps_ui::~helps_ui()
{
    delete ui;
}
