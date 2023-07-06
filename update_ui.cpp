#include "update_ui.h"
#include "ui_update_ui.h"
#include <QJsonObject> // { }
#include <QJsonArray> // [ ]
#include <QJsonDocument> // 解析Json
#include <QJsonValue> // int float double bool null { } [ ]
#include <QJsonParseError> //Json错误

#include <QCoreApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

/*
 * 检查更新窗口
*/

update_ui::update_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::update_ui)
{
    extern QString editor_version;
    ui->setupUi(this);
    ui->label_ver_old->setText(editor_version);
    /*请求网络*/
    QNetworkAccessManager* networkManager = new QNetworkAccessManager(this); //创建QNetworkAccessManager对象
    QUrl url("https://api.github.com/repos/Zao-chen/ZcCommandEditor/releases/latest"); //设置URL
    QNetworkReply* reply = networkManager->get(QNetworkRequest(url)); //发送HTTP GET请求
    while (!reply->isFinished()) //等待网络响应
    {
       qApp->processEvents();
    }
    QByteArray response = reply->readAll(); //获取服务器返回的数据
    QTextStream stream(response); //读取文件的全部内容
    QString str = stream.readAll(); //QJsonParseError类用于在JSON解析期间报告错误。
    QJsonParseError jsonError; //将json解析为UTF-8编码的json文档，并从中创建一个QJsonDocument。如果解析成功，返回QJsonDocument对象，否则返回null
    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8(), &jsonError); //判断是否解析失败
    if (jsonError.error != QJsonParseError::NoError && !doc.isNull()) {
       qDebug() << "Json格式错误！" << jsonError.error;
       return;
    }
    QJsonObject rootObj = doc.object();
    QJsonValue conValue = rootObj.value("body");
    ui->label_con->setText(conValue.toString());
    QJsonValue verValue = rootObj.value("tag_name");
    ui->label_ver->setText(verValue.toString());
    if(editor_version.contains("alpha")) ui->label_text->setText("正在使用预发布版，请积极反馈issue");
    else if(editor_version.replace("-beta","")==verValue.toString()) ui->label_text->setText("当前已是最新版");
    else ui->label_text->setText("有新版可以更新");
    QJsonValue likeValue = rootObj.value("assets"); //根键获取值
    // 判断类型是否是数组类型
    if (likeValue.type() == QJsonValue::Array) {
        // 转换成数组类型
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
               QJsonValue gameLikeValue = likeObj.value("name");
               QJsonValue priceLikeValue1 = likeObj.value("size");
               ui->label_file->setText(gameLikeValue.toString()+"  大小："+QString::number(priceLikeValue1.toDouble()));
           }
       }
    }
}

update_ui::~update_ui()
{
    delete ui;
}
