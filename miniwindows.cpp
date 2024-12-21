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
#include <Windows.h>
#include <thread>

/*
 * 悬浮窗窗口
*/

int static global_row=50; //当前格
int static global_column=50;
int static global_player_row=0; //玩家格
int static global_player_column=0;

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
    bool execute = false; //执行一个已知项
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

        label->setPixmap(QPixmap(image).scaled(23,23).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);

    }
    else if(save_map_class[x][y].block == "block")
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        image = ":/image/image/block.png";
        label->setPixmap(QPixmap(image).scaled(23,23).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else if(save_map_class[x][y].block == "redstone_comparator") //如果是命令方块
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        if(save_map_class[x][y].condition == 1) image = ":/image/image/bjq.png";
        /*设置朝向*/
        if(save_map_class[x][y].toward == 1) matrix.rotate(-90);
        else if(save_map_class[x][y].toward == 2) matrix.rotate(0);
        else if(save_map_class[x][y].toward == 3) matrix.rotate(90);
        else if(save_map_class[x][y].toward == 4) matrix.rotate(180);
        /*设置图像*/
        label->setPixmap(QPixmap(image).scaled(23,23).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else if(save_map_class[x][y].block == "redstone_torch") //如果是方块
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        image = ":/image/image/hshb.png";
        label->setPixmap(QPixmap(image).scaled(23,23).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else
    {
        dis->tableWidget->removeCellWidget(x,y);
    }
}

/*窗口打开*/
miniwindows::miniwindows(QWidget *parent) :
    QWidget(parent,Qt::Widget | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint),
    ui(new Ui::miniwindows)
{
    ui->setupUi(this);
    setWindowTitle("游戏悬浮窗");

    hook.installHook();
    qRegisterMetaType<Hook::Type>("Type");//为了信号中能传递自定义枚举类型，如果传递常规参数，可省略该行
    connect(&hook,SIGNAL(sendKeyType(Type)),this,SLOT(checkType(Type)));


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
    QString Filename = qApp->applicationDirPath()+"/temp.json";
    qDebug()<<"读取："<<qApp->applicationDirPath()+"/temp.json";
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
    qDebug()<<str;
    file.close();
    // QJsonParseError类用于在JSON解析期间报告错误。
    QJsonParseError jsonError;
    // 将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。
    // 如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError);
    // 判断是否解析失败
    // 判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
        QMessageBox msgBox;
        msgBox.setText("json格式错误");
        msgBox.exec();
        return;
    }
    QJsonObject rootObj = doc.object();
    // 根键获取值
    QJsonValue blockValue = rootObj.value("content");
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
                QJsonValue content = blockObj.value("command");
                save_map_class[int_x][int_y].content = content.toString();
                QJsonValue note = blockObj.value("note");
                save_map_class[int_x][int_y].note = note.toString();
                QJsonValue redstone = blockObj.value("auto");
                save_map_class[int_x][int_y].redstone = redstone.toInt();
                QJsonValue toward = blockObj.value("toward");
                save_map_class[int_x][int_y].toward = toward.toInt();
                QJsonValue type = blockObj.value("type");
                save_map_class[int_x][int_y].type = type.toInt();
                QJsonValue block = blockObj.value("id");
                save_map_class[int_x][int_y].block = block.toString();
                QJsonValue delay = blockObj.value("tick_delay");
                save_map_class[int_x][int_y].delay = delay.toInt();
                QJsonValue execute = blockObj.value("execute_on_first_tick");
                save_map_class[int_x][int_y].execute = execute.toBool();
                QJsonValue con = blockObj.value("conditionMet");
                save_map_class[int_x][int_y].condition = con.toInt();
                global_row = int_x;
                global_column = int_y;
                show_reload(ui,global_row,global_column);
                qDebug()<<"刷新方块";
            }
        }
    }
}

/*关闭窗口*/
miniwindows::~miniwindows()
{
    delete ui;
    hook.unInstallHook(); //移除钩子
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
        hook.unInstallHook(); //移除钩子
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

/*点击单元格*/
void miniwindows::on_tableWidget_cellClicked(int row, int column)
{
    global_row = row;
    global_column = column;
    ui->label_location->setText("选中方块 ( " + QString::number(global_row-50) + " , " + QString::number(global_column-50)+" )");
    show_reload(ui,global_row,global_column);
}

/*按键监听*/
void miniwindows::checkType(Hook::Type type){
    switch (type) {
    case Hook::T:
        if(global_column>0) global_column-=1;
        break;
    case Hook::G:
        if(global_column<100) global_column+=1;
        break;
    case Hook::F:
        if(global_row>0) global_row-=1;
        break;
    case Hook::H:
        if(global_row<100) global_row+=1;
        break;
    default:
        break;
    }
    /*移动单元格*/
    QTableWidgetItem *item = new QTableWidgetItem();
    ui->tableWidget->setItem(global_column, global_row, item);
    ui->tableWidget->scrollToItem(item, QAbstractItemView::PositionAtCenter);
    /*刷新单元格内容*/
    ui->label_location->setText("选中方块 ( " + QString::number(global_column-50) + " , " + QString::number(global_row-50)+" )");
    ui->label_block->setText("方块："+save_map_class[global_column][global_row].block);
    if(save_map_class[global_column][global_row].condition==1) ui->label_condition->setText("条件：无条件");
    else ui->label_condition->setText("条件：有条件");
    ui->label_delay->setText("延迟："+QString::number(save_map_class[global_column][global_row].delay));
    if(save_map_class[global_column][global_row].execute) ui->label_execute->setText("执行：√");
    else ui->label_execute->setText("执行：×");
    if(save_map_class[global_column][global_row].redstone==1) ui->label_redstone->setText("红石：红石控制");
    else ui->label_redstone->setText("红石：保持开启");
    if(save_map_class[global_column][global_row].toward==1) ui->label_toward->setText("方向：北↑");
    else if(save_map_class[global_column][global_row].toward==2) ui->label_toward->setText("方向：东→");
    else if(save_map_class[global_column][global_row].toward==3) ui->label_toward->setText("方向：南↓");
    else if(save_map_class[global_column][global_row].toward==4) ui->label_toward->setText("方向：西←");
    if(save_map_class[global_column][global_row].type==1) ui->label_toward->setText("类型：脉冲");
    else if(save_map_class[global_column][global_row].type==2) ui->label_toward->setText("类型：连锁");
    else if(save_map_class[global_column][global_row].type==3) ui->label_toward->setText("类型：循环");
    ui->textEdit_notes->setText(save_map_class[global_column][global_row].note);
    ui->textEdit_cmd->setText(save_map_class[global_column][global_row].content);
}

void simulateMouseClick(const QPoint& screenPos,bool isLeft) {
    // 设置鼠标位置
    SetCursorPos(screenPos.x(), screenPos.y());
    // 创建输入事件数组
    INPUT inputs[2] = {};
    if(isLeft)
    {
        // 模拟鼠标按下
        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        // 模拟鼠标释放
        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }

    else
    {
        // 模拟鼠标按下
        inputs[0].type = INPUT_MOUSE;
        inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        // 模拟鼠标释放
        inputs[1].type = INPUT_MOUSE;
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    }

    // 注入输入事件
    SendInput(2, inputs, sizeof(INPUT));
}
void simulateTyping(QString text) {
    for (char c : text.toStdString()) {
        // 将字符转换为虚拟键码
        SHORT vk = VkKeyScanA(c);
        if (vk == -1) {
            qWarning("无法处理字符: %c", c);
            continue;
        }
        // 检查是否需要 Shift 键
        bool shiftRequired = (vk & 0x0100) != 0;

        INPUT inputs[4] = {};
        int inputIndex = 0;
        // 如果需要 Shift 键，先按下
        if (shiftRequired) {
            inputs[inputIndex].type = INPUT_KEYBOARD;
            inputs[inputIndex].ki.wVk = VK_SHIFT;
            ++inputIndex;
        }
        // 按下字符键
        inputs[inputIndex].type = INPUT_KEYBOARD;
        inputs[inputIndex].ki.wVk = vk & 0xFF; // 提取虚拟键码
        ++inputIndex;
        // 释放字符键
        inputs[inputIndex].type = INPUT_KEYBOARD;
        inputs[inputIndex].ki.wVk = vk & 0xFF;
        inputs[inputIndex].ki.dwFlags = KEYEVENTF_KEYUP;
        ++inputIndex;
        // 如果需要 Shift 键，释放它
        if (shiftRequired) {
            inputs[inputIndex].type = INPUT_KEYBOARD;
            inputs[inputIndex].ki.wVk = VK_SHIFT;
            inputs[inputIndex].ki.dwFlags = KEYEVENTF_KEYUP;
            ++inputIndex;
        }
        // 注入输入事件
        SendInput(inputIndex, inputs, sizeof(INPUT));
    }
}
void TypingOneWord(WORD word)
{
    // 创建输入事件数组
    INPUT inputs[2] = {};
    // 按下 ESC 键
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = word;
    // 释放 ESC 键
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = word;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;
    // 注入 ESC 键的事件
    SendInput(2, inputs, sizeof(INPUT));
}
void typetp(int x,int y)
{
    simulateTyping("tp ~"+QString::number(y-50-global_player_row)+" ~ ~"+QString::number(x-50-global_player_column));
    global_player_row = y-50;
    global_player_column = x-50;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    TypingOneWord(VK_RETURN);
}
void setblock(int x,int y)
{
    qDebug()<<save_map_class[x][y].toward;
    int temp_face;
    if(save_map_class[x][y].toward==1) temp_face = 2;
    if(save_map_class[x][y].toward==2) temp_face = 5;
    if(save_map_class[x][y].toward==3) temp_face = 3;
    if(save_map_class[x][y].toward==4) temp_face = 4;
    QString temp_condition;
    if(save_map_class[x][y].condition==1) temp_condition = "false";
    if(save_map_class[x][y].condition==2) temp_condition = "true";
    QString temp_type;
    if(save_map_class[x][y].type==1) temp_type = "command_block";
    if(save_map_class[x][y].type==2) temp_type = "chain_command_block";
    if(save_map_class[x][y].type==3) temp_type = "repeating_command_block";
    simulateTyping("setblock ~ ~-1 ~ "+temp_type+"[\"facing_direction\"="+QString::number(temp_face)+",\"conditional_bit\"="+temp_condition+"]");
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    TypingOneWord(VK_RETURN);
}
void miniwindows::on_pushButton_start_clicked()
{
    int delay = 150;
    global_player_row = 0;
    global_player_column = 0;
    qDebug()<<"开始导入";
    simulateMouseClick(QPoint(500, 100),1); // 模拟点击屏幕坐标
    TypingOneWord(VK_ESCAPE);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    for (int x = 0;x != ui->tableWidget->columnCount(); x++)
    {
        for (int y = 0;y != ui->tableWidget->rowCount(); y++)
        {
            if(save_map_class[x][y].block != "air") //插入元素
            {
                TypingOneWord(VK_OEM_2);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                typetp(x,y);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                TypingOneWord(VK_OEM_2);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                setblock(x,y);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                simulateMouseClick(QPoint(0,0),0); // 模拟点击屏幕坐标
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                simulateTyping(save_map_class[x][y].content);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                TypingOneWord(VK_ESCAPE);
                if(save_map_class[x][y].redstone==2)
                {
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_LEFT);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_DOWN);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_DOWN);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_DOWN);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_RETURN);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                    TypingOneWord(VK_RETURN);
                    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
                }
                TypingOneWord(VK_ESCAPE);
                std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            }
        }
        ;
    }
}



void miniwindows::on_pushButton_clicked()
{
    qDebug()<<QCursor::pos();
}

