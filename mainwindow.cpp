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

int static global_row; //当前格
int static global_column;
QString static editor_version = "1.1"; //json版本
QString static load_version;

struct save_map //保存东西的结构体
{
    bool has_block = false; //是否有方块
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
    QString content = ""; //内容
    QString note = ""; //备注
}static save_map_class[1000][1000];


void show_reload(Ui::MainWindow *dis,int x,int y) //刷新当前格
{
    if(save_map_class[x][y].has_block) //设置图像
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
    dis->checkBox_hasblock->setChecked(save_map_class[x][y].has_block);
    dis->content_textEdit->setPlainText(save_map_class[x][y].content);
    dis->notes_content_textEdit->setPlainText(save_map_class[x][y].note);
    dis->toward_comboBox->setCurrentIndex(save_map_class[x][y].toward-1);
    dis->type_comboBox->setCurrentIndex(save_map_class[x][y].type-1);
    dis->condition_comboBox->setCurrentIndex(save_map_class[x][y].condition-1);
    dis->redstone_comboBox->setCurrentIndex(save_map_class[x][y].redstone-1);
}
void clear_map(Ui::MainWindow *dis) //清空地图
{
    for (int i=0;i!=10;i++) {
        for (int j=0;j!=10;j++) {
            save_map_class[i][j].has_block = false; //是否有方块
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

    ui->tableWidget->setColumnCount(1000); //设置表格大小
    ui->tableWidget->setRowCount(1000);

    connect(ui->actionoutput,SIGNAL(triggered()),this,SLOT(on_menu_save_clicked())); //导出按钮信号绑定
    connect(ui->actioninput,SIGNAL(triggered()),this,SLOT(on_menu_load_clicked())); //导入按钮信号绑定

    ui->file_lineEdit->setText(qApp->applicationDirPath()+"/json/Untitle.json");

    ui->label_now->setText("编辑器使用json版本："+editor_version);

    ui->tableWidget->scrollToItem(ui->tableWidget->item(500,500));
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
    show_reload(ui,global_row,global_column);
}
/*点击是否有*/
void MainWindow::on_checkBox_hasblock_clicked(bool checked)
{
    save_map_class[global_row][global_column].has_block = checked;
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
            if(save_map_class[x][y].has_block)
            {
                likeObject.insert("x", x);
                likeObject.insert("y", y);
                likeObject.insert("toward",save_map_class[x][y].toward);
                likeObject.insert("type",save_map_class[x][y].type);
                likeObject.insert("condition",save_map_class[x][y].condition);
                likeObject.insert("redstone",save_map_class[x][y].redstone);
                likeObject.insert("content",save_map_class[x][y].content);
                likeObject.insert("note",save_map_class[x][y].note);
                likeArray.append(likeObject);
            }
        }
        ;
    }
    //添加到最外
    QJsonObject rootObject;
    rootObject.insert("command_block", likeArray);
    rootObject.insert("version", editor_version);
    rootObject.insert("author", ui->size_lineEdit_2->text());
    /*写入*/
    QJsonDocument doc; //将object设置为本文档的主要对象
    doc.setObject(rootObject);
    QFile file(ui->file_lineEdit->text());
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
    QFile file(ui->file_lineEdit->text());
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
    QJsonValue likeValue = rootObj.value("command_block");
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
                save_map_class[x.toInt()][y.toInt()].has_block = true;
                global_row = x.toInt();
                global_column = y.toInt();
                show_reload(ui,global_row,global_column);
            }
        }
    }
    ui->size_lineEdit_2->setText(rootObj.value("author").toString());
    load_version = rootObj.value("version").toString();
    ui->label_in->setText("导入的命令组json版本："+load_version);
    if(load_version!=editor_version)
    {
        QMessageBox msgBox;
        msgBox.setText("导入json版本与编辑器版本不同，可能出现bug，建议进行迁移");
        msgBox.exec();
    }
}

