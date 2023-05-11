#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QJsonObject> // { }
#include <QJsonArray> // [ ]
#include <QJsonDocument> // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
#include <QJsonParseError> //Json错误
#include <QFile> //文件
#include <QMessageBox> //消息框
#include <QString>

#include <update_ui.h>

#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

int static global_row; //当前格
int static global_column;
QString static editor_version = "1.1"; //json版本
QString static load_version;
QString static file_place = qApp->applicationDirPath()+"Untitle.json";

struct save_map //保存东西的结构体
{
    QString block = "air"; //当前方块东西
    int toward = 1;
    /*
     * 朝向
     * 1=上 2=右 3=下 4=左
    */
    int type = 1;
    /*
     * 类型
     * 1=脉冲 2=连锁 3=循环
    */
    int condition = 1;
    /*
     * 条件
     * 1=无条件 2=有条件
    */
    int redstone = 1;
    /*
     * 条件
     * 1=红石控制 2=保持开启
    */
    int delay = 0; //延迟
    bool execute = false;
    QString note = ""; //备注
    QString content = ""; //内容
}static save_map_class[100][100];


void show_reload(Ui::MainWindow *dis,int x,int y) //刷新当前格
{
    if(save_map_class[x][y].block == "command_block") //设置图像
    {
        QMatrix matrix;
        QLabel *label = new QLabel("");
        QString image;
        /*设置图像*/
        if(save_map_class[x][y].type == 1) //类型
        {
            /*条件*/
            if(save_map_class[x][y].condition == 1) image = ":/image/image/mc-wtj.png";
            else if(save_map_class[x][y].condition == 2) image = ":/image/mc-ytj.png";
        }
        else if (save_map_class[x][y].type == 2)
        {
            if(save_map_class[x][y].condition == 1) image = ":/image/image/ls-wtj.png";
            else if(save_map_class[x][y].condition == 2) image = ":/image/image/ls-ytj.png";
        }
        else if (save_map_class[x][y].type == 3)
        {
            if(save_map_class[x][y].condition == 1) image = ":/image/image/xh-wtj.png";
            else if(save_map_class[x][y].condition == 2) image = ":/image/image/xh-ytj.png";
        }
        /*设置朝向*/
        if(save_map_class[x][y].toward == 1) matrix.rotate(-90);
        else if(save_map_class[x][y].toward == 2) matrix.rotate(0);
        else if(save_map_class[x][y].toward == 3) matrix.rotate(90);
        else if(save_map_class[x][y].toward == 4) matrix.rotate(180);

        label->setPixmap(QPixmap(image).scaled(40,40).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else
    {
        dis->tableWidget->removeCellWidget(x,y);
    }
    dis->content_textEdit->setPlainText(save_map_class[x][y].content);
    dis->notes_content_textEdit->setPlainText(save_map_class[x][y].note);
    dis->toward_comboBox->setCurrentIndex(save_map_class[x][y].toward-1);
    dis->type_comboBox->setCurrentIndex(save_map_class[x][y].type-1);
    dis->condition_comboBox->setCurrentIndex(save_map_class[x][y].condition-1);
    dis->redstone_comboBox->setCurrentIndex(save_map_class[x][y].redstone-1);
    dis->delay_lineEdit_3->setText(QString::number(save_map_class[x][y].delay));
    dis->checkBox->setChecked(save_map_class[x][y].execute);
}
void clear_map(Ui::MainWindow *dis) //清空地图
{
    for (int i=0;i!=100;i++) {
        for (int j=0;j!=100;j++) {
            save_map_class[i][j].block = "air"; //是否有方块
            save_map_class[i][j].toward = 1;
            save_map_class[i][j].type = 1;
            save_map_class[i][j].condition = 1;
            save_map_class[i][j].redstone = 1;
            save_map_class[i][j].delay = 0; //延迟
            QString content = ""; //内容
            QString note = ""; //备注
            show_reload(dis,i,j);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*初始化*/
    ui->setupUi(this);



    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(40); //设置默认大小
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可更改

    ui->tableWidget->setColumnCount(100); //设置表格大小
    ui->tableWidget->setRowCount(100);

    connect(ui->actionoutput,SIGNAL(triggered()),this,SLOT(on_menu_save_clicked())); //导出按钮信号绑定
    connect(ui->actioninput,SIGNAL(triggered()),this,SLOT(on_menu_load_clicked())); //导入按钮信号绑定

    setWindowTitle("ZcCommandEditor");

    ui->label_now->setText("编辑器使用json版本："+editor_version);

    QStringList headers;
    for (int i = -50; i <= 50; i++) {
        headers << QString::number(i);
    }

    ui->tableWidget->setRowCount(101);
    ui->tableWidget->setColumnCount(101);
    ui->tableWidget->setVerticalHeaderLabels(headers);
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    QTableWidgetItem *item = new QTableWidgetItem("0");
    ui->tableWidget->setItem(50, 50, item);
    ui->tableWidget->scrollToItem(item, QAbstractItemView::PositionAtCenter); //滚动视图到指定单元格

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
    ui->label_location->setText("选中方块 ( " + QString::number(row+1) + " , " + QString::number(column+1)+" )");
    show_reload(ui,global_row,global_column);
}

/*方块类型*/
void MainWindow::on_type_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].type = index+1;
    show_reload(ui,global_row,global_column);
}
/*切换方向*/
void MainWindow::on_toward_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].toward = index+1;
    show_reload(ui,global_row,global_column);
}
/*方块条件*/
void MainWindow::on_condition_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].condition = index+1;
    show_reload(ui,global_row,global_column);
}
/*修改文本*/
void MainWindow::on_content_textEdit_textChanged()
{
    save_map_class[global_row][global_column].content = ui->content_textEdit->toPlainText();
}
/*修改备注*/
void MainWindow::on_notes_content_textEdit_textChanged()
{
    save_map_class[global_row][global_column].note = ui->notes_content_textEdit->toPlainText();
}
/*修改红石*/
void MainWindow::on_redstone_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].redstone = index+1;
    show_reload(ui,global_row,global_column);
}

/*导出json*/
void MainWindow::on_menu_save_clicked(void)
{
    /*遍历元素*/
    QJsonObject likeObject;
    QJsonArray likeArray;
    for (int x = 0;x != ui->tableWidget->columnCount(); x++)
    {
        for (int y = 0;y != ui->tableWidget->rowCount(); y++)
        {
            if(save_map_class[x][y].block != "air")
            {
                likeObject.insert("x", x);
                likeObject.insert("y", y);
                likeObject.insert("z", 0);
                likeObject.insert("block",save_map_class[x][y].block);
                likeObject.insert("toward",save_map_class[x][y].toward);
                likeObject.insert("type",save_map_class[x][y].type);
                likeObject.insert("condition",save_map_class[x][y].condition);
                likeObject.insert("redstone",save_map_class[x][y].redstone);
                likeObject.insert("content",save_map_class[x][y].content);
                likeObject.insert("note",save_map_class[x][y].note);
                likeObject.insert("delay",save_map_class[x][y].delay);
                likeObject.insert("execute",save_map_class[x][y].execute);
                likeArray.append(likeObject);
            }
        }
        ;
    }
    //添加到最外
    QJsonObject rootObject;
    rootObject.insert("block", likeArray);
    rootObject.insert("jsonversion", editor_version);
    rootObject.insert("mcversion", ui->vv_lineEdit->text());
    rootObject.insert("author", ui->auth_lineEdit->text());
    /*写入*/
    QJsonDocument doc; //将object设置为本文档的主要对象
    doc.setObject(rootObject);
    QFile file(file_place);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox msgBox;
        msgBox.setText("导出失败，请检查路径以及读写权限");
        msgBox.exec();
    }
    QTextStream stream(&file);
    stream.setCodec("UTF-8"); //设置写入编码是UTF8
    stream << doc.toJson(); //写入文件
    file.close();
}
/*导入json*/
void MainWindow::on_menu_load_clicked(void)
{
    QFile file(file_place);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "can't open error!";
        return;
    }
    // 读取文件的全部内容
    QTextStream stream(&file);
    stream.setCodec("UTF-8");		// 设置读取编码是UTF8
    QString str = stream.readAll();
    file.close();
    // QJsonParseError类用于在JSON解析期间报告错误。
    QJsonParseError jsonError;
    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        qDebug() << "Json格式错误！" << jsonError.error;
        return;
    }
    QJsonObject rootObj = doc.object();

    // 根键获取值
    QJsonValue likeValue = rootObj.value("block");
    // 判断类型是否是数组类型
    if (likeValue.type() == QJsonValue::Array) {
        // 转换成数组类型
        clear_map(ui);
        QJsonArray likeArray = likeValue.toArray();
        // 遍历数组
        for (int i = 0; i < likeArray.count(); i++) {
            // 获取数组的第一个元素，类型是QJsonValue
            QJsonValue likeValueChild = likeArray.at(i);
            // 判断是不是对象类型
            if (likeValueChild.type() == QJsonValue::Object) {
                // 转换成对象类型
                QJsonObject likeObj = likeValueChild.toObject();
                // 最后通过value函数就可以获取到值了，解析成功！
                QJsonValue x = likeObj.value("x");
                QJsonValue y = likeObj.value("y");
                QJsonValue condition = likeObj.value("condition");
                QJsonValue content = likeObj.value("content");
                save_map_class[x.toInt()][y.toInt()].content = content.toString();
                QJsonValue note = likeObj.value("note");
                save_map_class[x.toInt()][y.toInt()].note = note.toString();
                QJsonValue redstone = likeObj.value("redstone");
                save_map_class[x.toInt()][y.toInt()].redstone = redstone.toInt();
                QJsonValue toward = likeObj.value("toward");
                save_map_class[x.toInt()][y.toInt()].toward = toward.toInt();
                QJsonValue type = likeObj.value("type");
                save_map_class[x.toInt()][y.toInt()].type = type.toInt();
                QJsonValue block = likeObj.value("block");
                save_map_class[x.toInt()][y.toInt()].block = block.toString();
                QJsonValue delay = likeObj.value("delay");
                save_map_class[x.toInt()][y.toInt()].delay = delay.toInt();
                QJsonValue execute = likeObj.value("execute");
                save_map_class[x.toInt()][y.toInt()].execute = execute.toBool();
                QJsonValue con = likeObj.value("condition");
                save_map_class[x.toInt()][y.toInt()].condition = con.toInt();
                global_row = x.toInt();
                global_column = y.toInt();
                show_reload(ui,global_row,global_column);
            }
        }
    }
    ui->auth_lineEdit->setText(rootObj.value("author").toString());
    load_version = rootObj.value("jsonversion").toString();
    ui->label_in->setText("导入的命令组json版本："+load_version);
    ui->vv_lineEdit->setText(rootObj.value("mcversion").toString());
    if(load_version!=editor_version)
    {
        QMessageBox msgBox;
        msgBox.setText("导入json版本与编辑器版本不同，可能出现bug，建议进行迁移");
        msgBox.exec();
    }
}

/*修改方块*/
void MainWindow::on_block_comboBox_activated(int index)
{
    if(index==0) save_map_class[global_row][global_column].block = "air";
    else if(index==1) save_map_class[global_row][global_column].block = "command_block";
    show_reload(ui,global_row,global_column);
}

/*修改延迟*/
void MainWindow::on_delay_lineEdit_3_textChanged(const QString &arg1)
{
    save_map_class[global_row][global_column].delay = arg1.toInt();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    save_map_class[global_row][global_column].execute = checked;
}

void MainWindow::on_name_lineEdit_textChanged(const QString &arg1)
{
    file_place = qApp->applicationDirPath()+"\\"+arg1;
}

void MainWindow::on_pushButton_updata_clicked()
{
    update_ui upwindows;
    upwindows.exec();
}
