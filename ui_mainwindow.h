/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioninput;
    QAction *actionoutput;
    QAction *action_help;
    QAction *action_open;
    QWidget *centralwidget;
    QLabel *label;
    QTableWidget *tableWidget;
    QLabel *label_location;
    QComboBox *toward_comboBox;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *type_comboBox;
    QLabel *label_5;
    QComboBox *condition_comboBox;
    QLabel *label_6;
    QTextEdit *content_textEdit;
    QComboBox *redstone_comboBox;
    QLabel *label_7;
    QTextEdit *notes_content_textEdit;
    QPushButton *copy_pushButton;
    QPushButton *delet_pushButton;
    QPushButton *check_delet_pushButton;
    QLabel *label_10;
    QLineEdit *auth_lineEdit;
    QLabel *label_in;
    QLabel *label_now;
    QLabel *label_ver;
    QComboBox *block_comboBox;
    QLabel *label_8;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_9;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QWidget *widget;
    QLabel *label_11;
    QLineEdit *delay_lineEdit_3;
    QLabel *label_12;
    QCheckBox *checkBox;
    QLabel *label_14;
    QLineEdit *vv_lineEdit;
    QLabel *label_15;
    QLineEdit *name_lineEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1456, 688);
        MainWindow->setStyleSheet(QString::fromUtf8("* {\n"
"    background-color: #FFFEF9;\n"
"}\n"
"\n"
"QMenuBar {\n"
"    background-color: #FFFCF3;\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #FFFCF3;\n"
"}\n"
"\n"
"QMenu::item {\n"
"    padding: 5px 20px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #f8b156;\n"
"}\n"
"\n"
"QMenu::separator {\n"
"    height: 1px;\n"
"    background-color: #f7931e;\n"
"    margin: 5px 0px 5px 0px;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 5px 20px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background-color: #f8b156;\n"
"}\n"
"\n"
"QMenuBar::item:pressed {\n"
"    background-color: #c72e1d;\n"
"}\n"
"\n"
"\n"
"QLineEdit {\n"
"    border: 2px solid #f7931e;\n"
"    border-radius: 3px;\n"
"    background-color: #FFFCF3;\n"
"    padding: 2px;\n"
"    font-size: 16px;\n"
"}\n"
"\n"
"\n"
"QTextEdit {\n"
"    border: 2px solid #f7931e;\n"
"    border-radius: 3px;;\n"
"    padding: 5px;\n"
"    font-size: 16px;\n"
"   "
                        " background-color: #FFFCF3;\n"
"}\n"
"\n"
"QTableView {\n"
"    background-color: #FFFCF3;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #FFBC33;\n"
"    color: #ffffff;\n"
"    border: none;\n"
"    border-radius: 2px;\n"
"    padding: 2px 2px;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #f8b156;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #c72e1d;\n"
"}\n"
"\n"
"\n"
"QComboBox {\n"
"    border: none;\n"
"    border-radius: 20px;\n"
"    background-color: #FFBC33;\n"
"    color: #ffffff;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 8px 20px;\n"
"    padding-right: 4px; /* \345\217\263\344\276\247\347\225\231\345\207\272\344\270\200\345\256\232\347\251\272\351\227\264 */\n"
"    selection-background-color: #f8b156; /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"    selection-color: #ffffff; /* \351\200\211\344\270\255\351\241\271\345\211\215\346\231\257\350"
                        "\211\262 */\n"
"    outline: none;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #f8b156;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    width: 0; /* \345\216\273\346\216\211\344\270\213\346\213\211\347\256\255\345\244\264 */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    color: #FFBC33;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding-left: 20px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"}\n"
"\n"
"QCheckBox::indicator::unchecked {\n"
"    border: 2px solid #FFBC33;\n"
"    background-color: #FFFEF9;\n"
"}\n"
"\n"
"QCheckBox::indicator::unchecked:hover {\n"
"    border: 2px solid #f8b156;\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"    border: 2px solid #FFBC33;\n"
"    background-color: #FFBC33;\n"
"}\n"
"\n"
"QCheckBox::indicator::checked:hover {\n"
"    background-color: #f8b156;\n"
"}\n"
""));
        actioninput = new QAction(MainWindow);
        actioninput->setObjectName("actioninput");
        actionoutput = new QAction(MainWindow);
        actionoutput->setObjectName("actionoutput");
        action_help = new QAction(MainWindow);
        action_help->setObjectName("action_help");
        action_open = new QAction(MainWindow);
        action_open->setObjectName("action_open");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(670, 80, 171, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("\351\273\221\344\275\223")});
        font.setPointSize(20);
        label->setFont(font);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(100, 80, 550, 550));
        tableWidget->setMinimumSize(QSize(550, 0));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	padding: 0px;\n"
"	border: 0;\n"
"}"));
        tableWidget->setDragEnabled(false);
        label_location = new QLabel(centralwidget);
        label_location->setObjectName("label_location");
        label_location->setGeometry(QRect(10, 0, 221, 31));
        QFont font1;
        font1.setPointSize(14);
        label_location->setFont(font1);
        toward_comboBox = new QComboBox(centralwidget);
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->setObjectName("toward_comboBox");
        toward_comboBox->setGeometry(QRect(290, 0, 91, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 0, 51, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 40, 51, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 40, 71, 31));
        label_4->setFont(font1);
        type_comboBox = new QComboBox(centralwidget);
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName("type_comboBox");
        type_comboBox->setGeometry(QRect(290, 40, 91, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(390, 0, 51, 31));
        label_5->setFont(font1);
        condition_comboBox = new QComboBox(centralwidget);
        condition_comboBox->addItem(QString());
        condition_comboBox->addItem(QString());
        condition_comboBox->setObjectName("condition_comboBox");
        condition_comboBox->setGeometry(QRect(440, 0, 101, 31));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(670, 120, 51, 31));
        label_6->setFont(font1);
        content_textEdit = new QTextEdit(centralwidget);
        content_textEdit->setObjectName("content_textEdit");
        content_textEdit->setGeometry(QRect(670, 160, 421, 91));
        redstone_comboBox = new QComboBox(centralwidget);
        redstone_comboBox->addItem(QString());
        redstone_comboBox->addItem(QString());
        redstone_comboBox->setObjectName("redstone_comboBox");
        redstone_comboBox->setGeometry(QRect(440, 40, 101, 31));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(390, 40, 51, 31));
        label_7->setFont(font1);
        notes_content_textEdit = new QTextEdit(centralwidget);
        notes_content_textEdit->setObjectName("notes_content_textEdit");
        notes_content_textEdit->setGeometry(QRect(670, 30, 421, 41));
        copy_pushButton = new QPushButton(centralwidget);
        copy_pushButton->setObjectName("copy_pushButton");
        copy_pushButton->setGeometry(QRect(970, 120, 121, 34));
        delet_pushButton = new QPushButton(centralwidget);
        delet_pushButton->setObjectName("delet_pushButton");
        delet_pushButton->setGeometry(QRect(850, 120, 121, 34));
        check_delet_pushButton = new QPushButton(centralwidget);
        check_delet_pushButton->setObjectName("check_delet_pushButton");
        check_delet_pushButton->setGeometry(QRect(730, 120, 121, 34));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(1290, 30, 41, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(12);
        font2.setBold(true);
        label_10->setFont(font2);
        auth_lineEdit = new QLineEdit(centralwidget);
        auth_lineEdit->setObjectName("auth_lineEdit");
        auth_lineEdit->setGeometry(QRect(1340, 30, 111, 31));
        QFont font3;
        auth_lineEdit->setFont(font3);
        label_in = new QLabel(centralwidget);
        label_in->setObjectName("label_in");
        label_in->setGeometry(QRect(10, 630, 131, 16));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font4.setPointSize(6);
        font4.setBold(false);
        font4.setItalic(false);
        label_in->setFont(font4);
        label_now = new QLabel(centralwidget);
        label_now->setObjectName("label_now");
        label_now->setGeometry(QRect(150, 630, 131, 16));
        QFont font5;
        font5.setPointSize(6);
        label_now->setFont(font5);
        label_ver = new QLabel(centralwidget);
        label_ver->setObjectName("label_ver");
        label_ver->setGeometry(QRect(1210, 630, 211, 16));
        label_ver->setFont(font5);
        block_comboBox = new QComboBox(centralwidget);
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->setObjectName("block_comboBox");
        block_comboBox->setGeometry(QRect(130, 40, 101, 31));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(670, 0, 51, 21));
        label_8->setFont(font1);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 80, 91, 551));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 89, 549));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 80, 54, 251));
        scrollArea->setWidget(scrollAreaWidgetContents);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(670, 270, 81, 31));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(760, 270, 331, 31));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(670, 310, 421, 321));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(1120, 120, 81, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1210, 120, 81, 31));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(1120, 150, 331, 461));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(550, 0, 51, 31));
        label_11->setFont(font1);
        delay_lineEdit_3 = new QLineEdit(centralwidget);
        delay_lineEdit_3->setObjectName("delay_lineEdit_3");
        delay_lineEdit_3->setGeometry(QRect(600, 0, 51, 31));
        delay_lineEdit_3->setFont(font3);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(550, 40, 51, 31));
        label_12->setFont(font1);
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(600, 40, 51, 31));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1290, 60, 41, 31));
        label_14->setFont(font2);
        vv_lineEdit = new QLineEdit(centralwidget);
        vv_lineEdit->setObjectName("vv_lineEdit");
        vv_lineEdit->setGeometry(QRect(1340, 60, 111, 31));
        vv_lineEdit->setFont(font3);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(1290, 0, 41, 31));
        label_15->setFont(font2);
        name_lineEdit = new QLineEdit(centralwidget);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setGeometry(QRect(1340, 0, 111, 31));
        name_lineEdit->setFont(font3);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1456, 26));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actioninput);
        menu->addAction(actionoutput);
        menu_2->addAction(action_help);
        menu_4->addAction(action_open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ZcCommandEditor", nullptr));
        actioninput->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        actionoutput->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        action_help->setText(QCoreApplication::translate("MainWindow", "\345\277\253\346\215\267\351\224\256", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "github", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\205\267\344\275\223\350\257\246\346\203\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_location->setText(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\255\346\226\271\345\235\227 \357\274\210\346\234\252\351\200\211\344\270\255\357\274\211", nullptr));
        toward_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\345\214\227\357\274\210\342\206\221\357\274\211", nullptr));
        toward_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\234\357\274\210\342\206\222\357\274\211", nullptr));
        toward_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\215\227\357\274\210\342\206\223\357\274\211", nullptr));
        toward_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\350\245\277\357\274\210\342\206\220\357\274\211", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\235\345\220\221", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\226\271\345\235\227", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        type_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\204\211\345\206\262", nullptr));
        type_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\350\277\236\351\224\201", nullptr));
        type_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\235\241\344\273\266", nullptr));
        condition_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\235\241\344\273\266", nullptr));
        condition_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\234\211\346\235\241\344\273\266", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244", nullptr));
        redstone_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263\346\216\247\345\210\266", nullptr));
        redstone_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\277\235\346\214\201\345\274\200\345\220\257", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263", nullptr));
        copy_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\345\244\215\345\210\266", nullptr));
        delet_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\346\270\205\347\251\272", nullptr));
        check_delet_pushButton->setText(QCoreApplication::translate("MainWindow", "\350\257\255\346\263\225\346\243\200\346\237\245", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\275\234\350\200\205", nullptr));
        auth_lineEdit->setText(QString());
        label_in->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\347\232\204\345\221\275\344\273\244\347\273\204json\347\211\210\346\234\254\357\274\232", nullptr));
        label_now->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\344\275\277\347\224\250json\347\211\210\346\234\254\357\274\232", nullptr));
        label_ver->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\345\231\250\347\211\210\346\234\254\357\274\2320.1   mady by Zao_chen with <3 and bug", nullptr));
        block_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        block_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\221\275\344\273\244\346\226\271\345\235\227", nullptr));
        block_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232\346\226\271\345\235\227", nullptr));
        block_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\344\270\255\347\273\255\345\231\250", nullptr));
        block_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\345\231\250", nullptr));
        block_comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263\345\235\227", nullptr));
        block_comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263\347\201\253\346\212\212", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "\345\244\207\346\263\250", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\267\245</p><p>\345\205\267</p><p>\346\240\217</p><p>\345\274\200</p><p>\345\217\221</p><p>\344\270\255</p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\271\345\235\227", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\347\211\251\345\223\201", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\256\236\344\275\223", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\347\262\222\345\255\220", nullptr));

        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\342\200\246\342\200\246", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\346\217\222\344\273\266", nullptr));

        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\273\266\350\277\237", nullptr));
        delay_lineEdit_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        checkBox->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254", nullptr));
        vv_lineEdit->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        name_lineEdit->setText(QCoreApplication::translate("MainWindow", "Untitle.json", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\217\222\344\273\266", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
