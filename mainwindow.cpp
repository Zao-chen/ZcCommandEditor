/*头文件相关*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
/*调试相关*/
#include <QDebug>
#include <QtDebug>
/*json相关*/
#include <QJsonObject> // { }
#include <QJsonArray> // [ ]
#include <QJsonDocument> // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
#include <QJsonParseError> //Json错误
#include <QNetworkAccessManager>
/*其他窗口*/
#include <update_ui.h> //检查更新窗口
#include <helps_ui.h> //帮助窗口
#include <miniwindows.h> //悬浮窗
#include <QFileDialog> //文件框
#include <QMessageBox> //消息框
#include <QWebEngineView> //网页框
/*网络相关*/
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
/*功能性*/
#include <QClipboard> //剪贴板
#include <QFile> //文件
#include <QString> //字符串
#include <QDesktopServices>
#include <QUrl> //网页
#include <QList> //列表

/*
 * 主窗口
*/

/*全局变量*/
int static global_row; //当前格
int static global_column;
QString json_version = "1.4"; //json版本
QString editor_version = "v0.7.2-alpha";
QString load_version; //加载版本
int now_input = 0; //当前添加数量
QString file_name = "Untitle"; //文件名

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

void show_reload(Ui::MainWindow *dis,int x,int y) //刷新当前格
{
    if(save_map_class[x][y].block == "command_block") //如果是命令方块
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        /*设置图像*/
        if(save_map_class[x][y].type == 1) //命令方块类型
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
        /*设置图像*/
        label->setPixmap(QPixmap(image).scaled(40,40).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);

    }
    else if(save_map_class[x][y].block == "block") //如果是方块
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        image = ":/image/image/block.png";
        label->setPixmap(QPixmap(image).scaled(40,40).transformed(matrix, Qt::SmoothTransformation));
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
        label->setPixmap(QPixmap(image).scaled(40,40).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else if(save_map_class[x][y].block == "redstone_torch") //如果是方块
    {
        QTransform matrix;
        QLabel *label = new QLabel("");
        QString image;
        image = ":/image/image/hshb.png";
        label->setPixmap(QPixmap(image).scaled(40,40).transformed(matrix, Qt::SmoothTransformation));
        dis->tableWidget->setCellWidget(x,y,label);
    }
    else //什么也不是
    {
        dis->tableWidget->removeCellWidget(x,y);
    }
    /*设置内容*/
    dis->content_textEdit->setPlainText(save_map_class[x][y].content);
    dis->notes_content_textEdit->setPlainText(save_map_class[x][y].note);
    dis->toward_comboBox->setCurrentIndex(save_map_class[x][y].toward-1);
    dis->type_comboBox->setCurrentIndex(save_map_class[x][y].type-1);
    dis->condition_comboBox->setCurrentIndex(save_map_class[x][y].condition-1);
    dis->redstone_comboBox->setCurrentIndex(save_map_class[x][y].redstone-1);
    dis->delay_lineEdit_3->setText(QString::number(save_map_class[x][y].delay));
    dis->checkBox->setChecked(save_map_class[x][y].execute);
    if(save_map_class[x][y].block == "air"){ dis->block_comboBox->setCurrentIndex(0); }
    else if(save_map_class[x][y].block == "command_block"){ dis->block_comboBox->setCurrentIndex(1); }
    else if(save_map_class[x][y].block == "block"){ dis->block_comboBox->setCurrentIndex(2); }
    else if(save_map_class[x][y].block == "redstone_comparator"){ dis->block_comboBox->setCurrentIndex(3); }
    else if(save_map_class[x][y].block == "redstone_torch"){ dis->block_comboBox->setCurrentIndex(4); }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*初始化*/
    ui->setupUi(this);
    /*相关测试*/
    setWindowTitle("ZcCommandEditor");
    ui->label_now->setText("编辑器使用json版本："+json_version);
    /*表格初始化*/
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(40); //设置默认大小
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(40);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可更改
    ui->tableWidget->setColumnCount(100); //设置表格大小
    ui->tableWidget->setRowCount(100);
    QStringList headers; //表头设置
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
    /*信号初始化*/
    connect(ui->actionoutput,SIGNAL(triggered()),this,SLOT(on_menu_save_clicked())); //导出按钮信号绑定
    connect(ui->actioninput,SIGNAL(triggered()),this,SLOT(on_menu_load_clicked())); //导入按钮信号绑定
    connect(ui->action_help,SIGNAL(triggered()),this,SLOT(on_menu_help_clicked())); //导入按钮信号绑定
    connect(ui->action_open,SIGNAL(triggered()),this,SLOT(on_menu_github_clicked())); //github信号绑定
    connect(ui->action_updata,SIGNAL(triggered()),this,SLOT(on_menu_updata_clicked())); //检查更新信号绑定
    /*提示初始化*/
    ui->label_ver->setText("编译器版本："+editor_version+"   mady by Zao_chen with <3 and bug");
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
    ui->label_location_2->setText(" ( " + QString::number(global_row-50) + " , " + QString::number(global_column-50)+" )");
    show_reload(ui,global_row,global_column);
}
/*修改方块类型*/
void MainWindow::on_type_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].type = index+1;
    show_reload(ui,global_row,global_column);
}
/*修改方向*/
void MainWindow::on_toward_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].toward = index+1;
    show_reload(ui,global_row,global_column);
}
/*修改方块条件*/
void MainWindow::on_condition_comboBox_activated(int index)
{
    save_map_class[global_row][global_column].condition = index+1;
    show_reload(ui,global_row,global_column);
}
/*修改指令*/
void MainWindow::on_content_textEdit_textChanged()
{
    save_map_class[global_row][global_column].content = ui->content_textEdit->toPlainText();
    /*提示文本*/
    QStringList input_cmd_List = ui->content_textEdit->toPlainText().split(" ");
    if(input_cmd_List.length()==1) //如果在输主指令
    {
        ui->cmd_lineEdit->setText(input_cmd_List[0]); //修改查询对象
    }
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
    /*遍历方块消息*/
    QJsonObject blockObject;
    QJsonArray blockArray;
    for (int x = 0;x != ui->tableWidget->columnCount(); x++)
    {
        for (int y = 0;y != ui->tableWidget->rowCount(); y++)
        {
            if(save_map_class[x][y].block != "air") //插入元素
            {
                blockObject.insert("x", x-50);
                blockObject.insert("y", y-50);
                blockObject.insert("z", 0);
                blockObject.insert("id",save_map_class[x][y].block);
                blockObject.insert("toward",save_map_class[x][y].toward);
                blockObject.insert("type",save_map_class[x][y].type);
                blockObject.insert("conditionMet",save_map_class[x][y].condition);
                blockObject.insert("auto",save_map_class[x][y].redstone);
                blockObject.insert("command",save_map_class[x][y].content);
                blockObject.insert("note",save_map_class[x][y].note);
                blockObject.insert("tick_delay",save_map_class[x][y].delay);
                blockObject.insert("execute_on_first_tick",save_map_class[x][y].execute);
                blockArray.append(blockObject);
            }
        }
        ;
    }
    //添加到最外
    QJsonObject rootObject;
    /*其他消息导入*/
    rootObject.insert("content", blockArray);
    rootObject.insert("jsonversion", json_version);
    rootObject.insert("mcversion", ui->vv_lineEdit->text());
    rootObject.insert("author", ui->auth_lineEdit->text());
    /*写入*/
    QJsonDocument doc; //将object设置为本文档的主要对象
    doc.setObject(rootObject);
    /*文件对话框*/
    QString Filename = QFileDialog::getSaveFileName(this,"导出到",qApp->applicationDirPath()+"/"+file_name+".json","*.json");
    QFile file(Filename);
    if(!file.open(QIODevice::WriteOnly)) //打开失败
    {
        QMessageBox msgBox;
        msgBox.setText("导出失败，请检查路径以及读写权限");
        msgBox.exec();
    }
    QTextStream stream(&file);
    stream << doc.toJson(); //写入文件
    file.close();
}
/*导入json*/
void MainWindow::on_menu_load_clicked(void)
{
    /*文件对话框*/
    QString Filename = QFileDialog::getOpenFileName(this,"选择这里组",qApp->applicationDirPath(),"*.json");
    QFile file(Filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox msgBox;
        msgBox.setText("打开失败，请检查路径以及读写权限");
        msgBox.exec();
        return;
    }
    ui->name_lineEdit->setText(Filename.split("/")[Filename.split("/").length()-1].replace(".json",""));
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
            }
        }
    }
    ui->auth_lineEdit->setText(rootObj.value("author").toString());
    load_version = rootObj.value("jsonversion").toString();
    ui->label_in->setText("导入的命令组json版本："+load_version);
    ui->vv_lineEdit->setText(rootObj.value("mcversion").toString());
    if(load_version!=json_version)
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
    else if(index==2) save_map_class[global_row][global_column].block = "block";
    else if(index==3) save_map_class[global_row][global_column].block = "redstone_comparator";
    else if(index==4) save_map_class[global_row][global_column].block = "redstone_torch";
    show_reload(ui,global_row,global_column);
}
/*修改延迟*/
void MainWindow::on_delay_lineEdit_3_textChanged(const QString &arg1)
{
    save_map_class[global_row][global_column].delay = arg1.toInt();
}
/*执行一个已知项*/
void MainWindow::on_checkBox_clicked(bool checked)
{
    save_map_class[global_row][global_column].execute = checked;
}
/*文件位置*/
void MainWindow::on_name_lineEdit_textChanged(const QString &arg1)
{
    file_name = qApp->applicationDirPath()+"\\"+arg1;
}
/*键盘按下事件*/
void MainWindow::keyPressEvent(QKeyEvent * event)
{
    // 普通键
    switch (event->key())
    {
    // ESC键
    case Qt::Key_C:
        save_map_class[global_row][global_column].block = "command_block";
        show_reload(ui,global_row,global_column);
    break;
    case Qt::Key_B:
        save_map_class[global_row][global_column].block = "block";
        show_reload(ui,global_row,global_column);
    break;
    case Qt::Key_A:
        save_map_class[global_row][global_column].block = "air";
        show_reload(ui,global_row,global_column);
    break;
    }
}
/*打开帮助*/
void MainWindow::on_menu_help_clicked(void){
    helps_ui *hpwindows = new helps_ui;
    hpwindows->show();
}
/*打开github*/
void MainWindow::on_menu_github_clicked(void){
    QDesktopServices::openUrl(QUrl("https://github.com/Zao-chen/ZcCommandEditor", QUrl::TolerantMode));
}
/*检查更新*/
void MainWindow::on_menu_updata_clicked(void)
{
    update_ui *upwindows = new update_ui;
    upwindows->show();
}
/*百科搜索*/
void MainWindow::on_pushButton_search_clicked()
{
    //获取搜索内容
    QString URLSTR;
    if(ui->cmd_comboBox->currentIndex()==0)
    {
        URLSTR = "https://minecraft.fandom.com/zh/wiki/%E5%91%BD%E4%BB%A4/"+ui->cmd_lineEdit->text();
        //储存网页代码的文件
        const QString FILE_NAME = "test.text";
        QUrl url(URLSTR);
        QNetworkAccessManager manager;
        QEventLoop loop;
        //发出请求
        QNetworkReply *reply = manager.get(QNetworkRequest(url));
        //请求结束并下载完成后，退出子事件循环
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        //开启子事件循环
        loop.exec();
        //将读到的信息写入文件
        code = reply->readAll();
        QRegularExpression re1("<meta name=\"description\" content=\"(.)*/>");
        QRegularExpressionMatch match=re1.match(code);
        QString matched = match.captured(0).replace("<meta name=\"description\" content=\"","").replace("/>","");
        ui->label_command->setText(ui->cmd_lineEdit->text()); //指令显示
        QList<QString> matched_list = matched.split(" ");
        ui->label_des->setText(matched_list[0]); //描述显示
        QRegularExpression re2("<h2><span id=\".E8.AF.AD.E6.B3.95\">([\\s\\S]*)</dd></dl>");
        match=re2.match(code); //详细显示
        ui->textBrowser_des->setText("<style type=\"text/css\">body {zoom:0.5;}</style>"+match.captured());
    }
    else if(ui->cmd_comboBox->currentIndex()==1||2||3)
    {
        URLSTR = "https://minecraft.fandom.com/zh/wiki/"+ui->cmd_lineEdit->text();
        //储存网页代码的文件
        const QString FILE_NAME = "test.text";
        QUrl url(URLSTR);
        QNetworkAccessManager manager;
        QEventLoop loop;
        //发出请求
        QNetworkReply *reply = manager.get(QNetworkRequest(url));
        //请求结束并下载完成后，退出子事件循环
        QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        //开启子事件循环
        loop.exec();
        //将读到的信息写入文件
        code = reply->readAll();
        QRegularExpression re1("<meta name=\"description\" content=\"(.)*/>");
        QRegularExpressionMatch match=re1.match(code);
        QString matched = match.captured(0).replace("<meta name=\"description\" content=\"","").replace("/>","");
        ui->label_command->setText(ui->cmd_lineEdit->text());
        ui->label_des->setText(matched);

    }
}

/*一键清空*/
void MainWindow::on_delet_pushButton_clicked()
{
    ui->content_textEdit->clear();
}
/*一键复制*/
void MainWindow::on_copy_pushButton_clicked()
{
    QClipboard* clip = QApplication::clipboard();
    clip->setText(ui->content_textEdit->toPlainText());
}
/*打开迷你窗口*/
void MainWindow::on_openminiwin_pushButton_clicked()
{
    /*遍历元素*/
    QJsonObject blockObject;
    QJsonArray blockArray;
    for (int x = 0;x != ui->tableWidget->columnCount(); x++)
    {
        for (int y = 0;y != ui->tableWidget->rowCount(); y++)
        {
            if(save_map_class[x][y].block != "air")
            {
                blockObject.insert("x", x-50);
                blockObject.insert("y", y-50);
                blockObject.insert("z", 0);
                blockObject.insert("id",save_map_class[x][y].block);
                blockObject.insert("toward",save_map_class[x][y].toward);
                blockObject.insert("type",save_map_class[x][y].type);
                blockObject.insert("conditionMet",save_map_class[x][y].condition);
                blockObject.insert("auto",save_map_class[x][y].redstone);
                blockObject.insert("content",save_map_class[x][y].content);
                blockObject.insert("note",save_map_class[x][y].note);
                blockObject.insert("tick_delay",save_map_class[x][y].delay);
                blockObject.insert("execute_on_first_tick",save_map_class[x][y].execute);
                blockArray.append(blockObject);
            }
        }
        ;
    }
    //添加到最外
    QJsonObject rootObject;
    rootObject.insert("block", blockArray);
    rootObject.insert("jsonversion", json_version);
    rootObject.insert("mcversion", ui->vv_lineEdit->text());
    rootObject.insert("author", ui->auth_lineEdit->text());
    /*写入*/
    QJsonDocument doc; //将object设置为本文档的主要对象
    doc.setObject(rootObject);
    /*文件对话框*/
    QString Filename = qApp->applicationDirPath()+"temp.json";
    QFile file(Filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox msgBox;
        msgBox.setText("导出失败，请检查路径以及读写权限");
        msgBox.exec();
    }
    QTextStream stream(&file);
    stream << doc.toJson(); //写入文件
    file.close();
    miniwindows *miniwindow = new miniwindows();

    /*打开悬浮窗*/
    miniwindow->setWindowFlags(miniwindow->windowFlags() |Qt::Dialog);
    miniwindow->setWindowModality(Qt::ApplicationModal);
    miniwindow->show();
}

