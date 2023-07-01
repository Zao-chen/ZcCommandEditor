#include "miniwindows.h"
#include "ui_miniwindows.h"

#include <QMouseEvent>
/*json相关*/
#include <QJsonObject> // { }
#include <QJsonArray> // [ ]
#include <QJsonDocument> // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
#include <QJsonParseError> //Json错误
#include <QNetworkAccessManager>

#include <QMessageBox> //消息框

#include <QFile> //文件

#include <QLabel>

int static global_row; //当前格
int static global_column;
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
}static save_map_class[101][101];

void show_reload(Ui::miniwindows *dis,int x,int y) //刷新当前格
{
    if(save_map_class[x][y].block == "command_block") //设置图像
    {
        QTransform matrix;
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

        label->setPixmap(QPixmap(image).scaled(20,20).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);

    }
    else if(save_map_class[x][y].block == "block")
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        image = ":/image/image/block.png";
        label->setPixmap(QPixmap(image).scaled(20,20).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else
    {
        dis->tableWidget->removeCellWidget(x,y);
    }
}


miniwindows::miniwindows(QWidget *parent) :
    QWidget(parent,Qt::Widget | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint),
    ui(new Ui::miniwindows)
{
    ui->setupUi(this);
    setWindowTitle("游戏悬浮窗");
    /*表格初始化*/
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(20); //设置默认大小
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(20);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可更改
    ui->tableWidget->setColumnCount(100); //设置表格大小
    ui->tableWidget->setRowCount(100);
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
    ui->tableWidget->setFocusPolicy(Qt::NoFocus);

    /*还原界面*/
    QString Filename = qApp->applicationDirPath()+"temp.json";
    QFile file(Filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox msgBox;
        msgBox.setText("打开失败，请检查路径以及读写权限");
        msgBox.exec();
        return;
    }
    // 读取文件的全部内容
    QTextStream stream(&file);
    QString str = stream.readAll();
    file.close();
    // QJsonParseError类用于在JSON解析期间报告错误。
    QJsonParseError jsonError;
    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        QMessageBox msgBox;
        msgBox.setText("json格式错误");
        msgBox.exec();
        return;
    }
    QJsonObject rootObj = doc.object();
    // 根键获取值
    QJsonValue blockValue = rootObj.value("block");
    // 判断类型是否是数组类型
    if (blockValue.type() == QJsonValue::Array) {
        // 转换成数组类型
        QStringList headers;
        for (int i = -50; i <= 50; i++) {
            headers << QString::number(i);
        }
        //重置表格
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(101);
        ui->tableWidget->setColumnCount(101);
        ui->tableWidget->setVerticalHeaderLabels(headers);
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        QTableWidgetItem *item = new QTableWidgetItem("0");
        ui->tableWidget->setItem(50, 50, item);
        ui->tableWidget->scrollToItem(item, QAbstractItemView::PositionAtCenter); //滚动视图到指定单元格
        QJsonArray blockArray = blockValue.toArray();
        // 遍历数组
        for (int i = 0; i < blockArray.count(); i++) {
            // 获取数组的第一个元素，类型是QJsonValue
            QJsonValue blockValueChild = blockArray.at(i);
            // 判断是不是对象类型
            if (blockValueChild.type() == QJsonValue::Object) {
                // 转换成对象类型
                QJsonObject blockObj = blockValueChild.toObject();
                // 最后通过value函数就可以获取到值了，解析成功！
                QJsonValue x = blockObj.value("x");
                QJsonValue y = blockObj.value("y");
                int int_x = x.toInt()+50;
                int int_y = y.toInt()+50;
                QJsonValue condition = blockObj.value("condition");
                QJsonValue content = blockObj.value("content");
                save_map_class[int_x][int_y].content = content.toString();
                QJsonValue note = blockObj.value("note");
                save_map_class[int_x][int_y].note = note.toString();
                QJsonValue redstone = blockObj.value("redstone");
                save_map_class[int_x][int_y].redstone = redstone.toInt();
                QJsonValue toward = blockObj.value("toward");
                save_map_class[int_x][int_y].toward = toward.toInt();
                QJsonValue type = blockObj.value("type");
                save_map_class[int_x][int_y].type = type.toInt();
                QJsonValue block = blockObj.value("block");
                save_map_class[int_x][int_y].block = block.toString();
                QJsonValue delay = blockObj.value("delay");
                save_map_class[int_x][int_y].delay = delay.toInt();
                QJsonValue execute = blockObj.value("execute");
                save_map_class[int_x][int_y].execute = execute.toBool();
                QJsonValue con = blockObj.value("condition");
                save_map_class[int_x][int_y].condition = con.toInt();
                global_row = int_x;
                global_column = int_y;
                show_reload(ui,global_row,global_column);
            }
        }
    }
}

miniwindows::~miniwindows()
{
    delete ui;
}

/*拖动窗口操作*/
void miniwindows::mousePressEvent(QMouseEvent *event)
{
    if( (event->button() == Qt::LeftButton) ){
        mouse_press = true;
        mousePoint = event->globalPos() - this->pos();
    }
    else if(event->button() == Qt::RightButton){
        //如果是右键
        this->close();
    }
}
void miniwindows::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press)
    {
        move(event->globalPos() - mousePoint);
    }
}
void miniwindows::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press = false;
}
