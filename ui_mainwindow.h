/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actioninput;
    QAction *actionoutput;
    QAction *action_help;
    QAction *action_open;
    QAction *action1;
    QAction *action_updata;
    QWidget *centralwidget;
    QLabel *label_in;
    QLabel *label_now;
    QLabel *label_ver;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QTextEdit *notes_content_textEdit;
    QFormLayout *formLayout;
    QLabel *label_15;
    QLabel *label_10;
    QLabel *label_14;
    QLineEdit *name_lineEdit;
    QLineEdit *auth_lineEdit;
    QLineEdit *vv_lineEdit;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QPushButton *check_delet_pushButton;
    QPushButton *delet_pushButton;
    QPushButton *copy_pushButton;
    QTextEdit *content_textEdit;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmd_comboBox;
    QLineEdit *cmd_lineEdit;
    QPushButton *pushButton_search;
    QWidget *widget;
    QLabel *label_13;
    QLabel *label_command;
    QLabel *label_des;
    QTextBrowser *textBrowser_des;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_location_2;
    QLabel *label_7;
    QLineEdit *delay_lineEdit_3;
    QLabel *label_11;
    QLabel *label_location;
    QComboBox *type_comboBox;
    QCheckBox *checkBox;
    QLabel *label_12;
    QLabel *label_2;
    QComboBox *condition_comboBox;
    QLabel *label_3;
    QComboBox *redstone_comboBox;
    QLabel *label_5;
    QLabel *label_4;
    QComboBox *block_comboBox;
    QComboBox *toward_comboBox;
    QGroupBox *groupBox_3;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *openminiwin_pushButton;
    QTableWidget *tableWidget;
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
        MainWindow->resize(1483, 735);
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
"    background-color: #DAA520;\n"
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
"    background-color: 	#DAA520;\n"
"}\n"
"\n"
"\n"
"QComboBox {\n"
"    border: none;\n"
"    background-color: #FFBC33;\n"
"    color: #ffffff;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    selection-background-color: #f8b156; /* \351\200\211\344\270\255\351\241\271\350\203\214\346\231\257\350\211\262 */\n"
"    selection-color: #ffffff; /* \351\200\211\344\270\255\351\241\271\345\211\215\346\231\257\350\211\262 */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: #f8b156;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    width: 0; /* \345\216\273\346\216\211\344\270\213\346\213\211"
                        "\347\256\255\345\244\264 */\n"
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
        action1 = new QAction(MainWindow);
        action1->setObjectName("action1");
        action_updata = new QAction(MainWindow);
        action_updata->setObjectName("action_updata");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_in = new QLabel(centralwidget);
        label_in->setObjectName("label_in");
        label_in->setGeometry(QRect(10, 670, 131, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(6);
        font.setBold(false);
        font.setItalic(false);
        label_in->setFont(font);
        label_now = new QLabel(centralwidget);
        label_now->setObjectName("label_now");
        label_now->setGeometry(QRect(320, 670, 131, 16));
        QFont font1;
        font1.setPointSize(6);
        label_now->setFont(font1);
        label_ver = new QLabel(centralwidget);
        label_ver->setObjectName("label_ver");
        label_ver->setGeometry(QRect(1180, 670, 291, 16));
        label_ver->setFont(font1);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(690, 0, 781, 671));
        verticalLayoutWidget_3 = new QWidget(groupBox_2);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 30, 761, 631));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_8 = new QLabel(verticalLayoutWidget_3);
        label_8->setObjectName("label_8");
        label_8->setMinimumSize(QSize(600, 0));
        label_8->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(14);
        label_8->setFont(font2);

        verticalLayout->addWidget(label_8);

        notes_content_textEdit = new QTextEdit(verticalLayoutWidget_3);
        notes_content_textEdit->setObjectName("notes_content_textEdit");
        notes_content_textEdit->setMaximumSize(QSize(16777215, 50));

        verticalLayout->addWidget(notes_content_textEdit);


        horizontalLayout_5->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_15 = new QLabel(verticalLayoutWidget_3);
        label_15->setObjectName("label_15");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(12);
        font3.setBold(true);
        label_15->setFont(font3);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_15);

        label_10 = new QLabel(verticalLayoutWidget_3);
        label_10->setObjectName("label_10");
        label_10->setFont(font3);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        label_14 = new QLabel(verticalLayoutWidget_3);
        label_14->setObjectName("label_14");
        label_14->setFont(font3);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_14);

        name_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        name_lineEdit->setObjectName("name_lineEdit");
        name_lineEdit->setMaximumSize(QSize(16777215, 23));
        QFont font4;
        name_lineEdit->setFont(font4);

        formLayout->setWidget(0, QFormLayout::FieldRole, name_lineEdit);

        auth_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        auth_lineEdit->setObjectName("auth_lineEdit");
        auth_lineEdit->setMaximumSize(QSize(16777215, 23));
        auth_lineEdit->setFont(font4);

        formLayout->setWidget(1, QFormLayout::FieldRole, auth_lineEdit);

        vv_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        vv_lineEdit->setObjectName("vv_lineEdit");
        vv_lineEdit->setMinimumSize(QSize(0, 10));
        vv_lineEdit->setMaximumSize(QSize(16777215, 23));
        vv_lineEdit->setFont(font4);

        formLayout->setWidget(2, QFormLayout::FieldRole, vv_lineEdit);


        horizontalLayout_5->addLayout(formLayout);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName("label_6");
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        check_delet_pushButton = new QPushButton(verticalLayoutWidget_3);
        check_delet_pushButton->setObjectName("check_delet_pushButton");

        horizontalLayout->addWidget(check_delet_pushButton);

        delet_pushButton = new QPushButton(verticalLayoutWidget_3);
        delet_pushButton->setObjectName("delet_pushButton");

        horizontalLayout->addWidget(delet_pushButton);

        copy_pushButton = new QPushButton(verticalLayoutWidget_3);
        copy_pushButton->setObjectName("copy_pushButton");

        horizontalLayout->addWidget(copy_pushButton);


        verticalLayout_4->addLayout(horizontalLayout);

        content_textEdit = new QTextEdit(verticalLayoutWidget_3);
        content_textEdit->setObjectName("content_textEdit");

        verticalLayout_4->addWidget(content_textEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        cmd_comboBox = new QComboBox(verticalLayoutWidget_3);
        cmd_comboBox->addItem(QString());
        cmd_comboBox->addItem(QString());
        cmd_comboBox->addItem(QString());
        cmd_comboBox->addItem(QString());
        cmd_comboBox->setObjectName("cmd_comboBox");
        cmd_comboBox->setMinimumSize(QSize(60, 28));

        horizontalLayout_2->addWidget(cmd_comboBox);

        cmd_lineEdit = new QLineEdit(verticalLayoutWidget_3);
        cmd_lineEdit->setObjectName("cmd_lineEdit");

        horizontalLayout_2->addWidget(cmd_lineEdit);

        pushButton_search = new QPushButton(verticalLayoutWidget_3);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setMinimumSize(QSize(50, 28));

        horizontalLayout_2->addWidget(pushButton_search);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout_4);

        widget = new QWidget(verticalLayoutWidget_3);
        widget->setObjectName("widget");
        widget->setMinimumSize(QSize(350, 0));
        label_13 = new QLabel(widget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 10, 191, 21));
        QFont font5;
        font5.setPointSize(15);
        label_13->setFont(font5);
        label_command = new QLabel(widget);
        label_command->setObjectName("label_command");
        label_command->setGeometry(QRect(10, 40, 191, 21));
        QFont font6;
        font6.setPointSize(12);
        label_command->setFont(font6);
        label_des = new QLabel(widget);
        label_des->setObjectName("label_des");
        label_des->setGeometry(QRect(10, 70, 381, 61));
        QFont font7;
        font7.setPointSize(10);
        label_des->setFont(font7);
        label_des->setWordWrap(true);

        horizontalLayout_4->addWidget(widget);


        verticalLayout_5->addLayout(horizontalLayout_4);

        textBrowser_des = new QTextBrowser(verticalLayoutWidget_3);
        textBrowser_des->setObjectName("textBrowser_des");
        textBrowser_des->setMinimumSize(QSize(0, 300));
        QFont font8;
        font8.setBold(false);
        font8.setStrikeOut(false);
        textBrowser_des->setFont(font8);

        verticalLayout_5->addWidget(textBrowser_des);

        verticalLayoutWidget_4 = new QWidget(centralwidget);
        verticalLayoutWidget_4->setObjectName("verticalLayoutWidget_4");
        verticalLayoutWidget_4->setGeometry(QRect(10, 0, 671, 671));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget_4);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(16777215, 120));
        gridLayoutWidget = new QWidget(groupBox);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 30, 641, 78));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_location_2 = new QLabel(gridLayoutWidget);
        label_location_2->setObjectName("label_location_2");
        label_location_2->setFont(font2);

        gridLayout->addWidget(label_location_2, 0, 1, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName("label_7");
        label_7->setFont(font2);

        gridLayout->addWidget(label_7, 1, 4, 1, 1);

        delay_lineEdit_3 = new QLineEdit(gridLayoutWidget);
        delay_lineEdit_3->setObjectName("delay_lineEdit_3");
        delay_lineEdit_3->setFont(font4);

        gridLayout->addWidget(delay_lineEdit_3, 0, 7, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        gridLayout->addWidget(label_11, 0, 6, 1, 1);

        label_location = new QLabel(gridLayoutWidget);
        label_location->setObjectName("label_location");
        label_location->setFont(font2);

        gridLayout->addWidget(label_location, 0, 0, 1, 1);

        type_comboBox = new QComboBox(gridLayoutWidget);
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->addItem(QString());
        type_comboBox->setObjectName("type_comboBox");
        type_comboBox->setMinimumSize(QSize(0, 28));

        gridLayout->addWidget(type_comboBox, 1, 3, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 7, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName("label_12");
        label_12->setFont(font2);

        gridLayout->addWidget(label_12, 1, 6, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        condition_comboBox = new QComboBox(gridLayoutWidget);
        condition_comboBox->addItem(QString());
        condition_comboBox->addItem(QString());
        condition_comboBox->setObjectName("condition_comboBox");
        condition_comboBox->setMinimumSize(QSize(90, 28));

        gridLayout->addWidget(condition_comboBox, 0, 5, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        redstone_comboBox = new QComboBox(gridLayoutWidget);
        redstone_comboBox->addItem(QString());
        redstone_comboBox->addItem(QString());
        redstone_comboBox->setObjectName("redstone_comboBox");
        redstone_comboBox->setMinimumSize(QSize(0, 28));

        gridLayout->addWidget(redstone_comboBox, 1, 5, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setFont(font2);

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 1, 2, 1, 1);

        block_comboBox = new QComboBox(gridLayoutWidget);
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->addItem(QString());
        block_comboBox->setObjectName("block_comboBox");
        block_comboBox->setMinimumSize(QSize(80, 28));

        gridLayout->addWidget(block_comboBox, 1, 1, 1, 1);

        toward_comboBox = new QComboBox(gridLayoutWidget);
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->addItem(QString());
        toward_comboBox->setObjectName("toward_comboBox");
        toward_comboBox->setMinimumSize(QSize(80, 28));

        gridLayout->addWidget(toward_comboBox, 0, 3, 1, 1);


        verticalLayout_6->addWidget(groupBox);

        groupBox_3 = new QGroupBox(verticalLayoutWidget_4);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayoutWidget_5 = new QWidget(groupBox_3);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(10, 20, 651, 511));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(horizontalLayoutWidget_5);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMaximumSize(QSize(90, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 88, 507));
        openminiwin_pushButton = new QPushButton(scrollAreaWidgetContents);
        openminiwin_pushButton->setObjectName("openminiwin_pushButton");
        openminiwin_pushButton->setGeometry(QRect(10, 430, 71, 71));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_6->addWidget(scrollArea);

        tableWidget = new QTableWidget(horizontalLayoutWidget_5);
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
        tableWidget->setMinimumSize(QSize(550, 0));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	padding: 0px;\n"
"	border: 0;\n"
"}"));
        tableWidget->setDragEnabled(false);

        horizontalLayout_6->addWidget(tableWidget);


        verticalLayout_6->addWidget(groupBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1483, 26));
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
#if QT_CONFIG(shortcut)
        label_8->setBuddy(notes_content_textEdit);
        label_15->setBuddy(name_lineEdit);
        label_10->setBuddy(auth_lineEdit);
        label_14->setBuddy(vv_lineEdit);
        label_6->setBuddy(content_textEdit);
        label_7->setBuddy(redstone_comboBox);
        label_11->setBuddy(delay_lineEdit_3);
        label_12->setBuddy(checkBox);
        label_2->setBuddy(toward_comboBox);
        label_3->setBuddy(block_comboBox);
        label_5->setBuddy(condition_comboBox);
        label_4->setBuddy(type_comboBox);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(toward_comboBox, condition_comboBox);
        QWidget::setTabOrder(condition_comboBox, delay_lineEdit_3);
        QWidget::setTabOrder(delay_lineEdit_3, block_comboBox);
        QWidget::setTabOrder(block_comboBox, type_comboBox);
        QWidget::setTabOrder(type_comboBox, redstone_comboBox);
        QWidget::setTabOrder(redstone_comboBox, checkBox);
        QWidget::setTabOrder(checkBox, notes_content_textEdit);
        QWidget::setTabOrder(notes_content_textEdit, name_lineEdit);
        QWidget::setTabOrder(name_lineEdit, auth_lineEdit);
        QWidget::setTabOrder(auth_lineEdit, vv_lineEdit);
        QWidget::setTabOrder(vv_lineEdit, check_delet_pushButton);
        QWidget::setTabOrder(check_delet_pushButton, delet_pushButton);
        QWidget::setTabOrder(delet_pushButton, copy_pushButton);
        QWidget::setTabOrder(copy_pushButton, content_textEdit);
        QWidget::setTabOrder(content_textEdit, cmd_comboBox);
        QWidget::setTabOrder(cmd_comboBox, cmd_lineEdit);
        QWidget::setTabOrder(cmd_lineEdit, pushButton_search);
        QWidget::setTabOrder(pushButton_search, textBrowser_des);
        QWidget::setTabOrder(textBrowser_des, scrollArea);
        QWidget::setTabOrder(scrollArea, tableWidget);
        QWidget::setTabOrder(tableWidget, openminiwin_pushButton);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actioninput);
        menu->addAction(actionoutput);
        menu_2->addAction(action_help);
        menu_3->addAction(action1);
        menu_4->addAction(action_updata);
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
        action1->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\217\222\344\273\266", nullptr));
        action_updata->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254", nullptr));
        label_in->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\347\232\204\345\221\275\344\273\244\347\273\204json\347\211\210\346\234\254\357\274\232", nullptr));
        label_now->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250\344\275\277\347\224\250json\347\211\210\346\234\254\357\274\232", nullptr));
        label_ver->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\257\221\345\231\250\347\211\210\346\234\254\357\274\2320.1   mady by Zao_chen with <3 and bug", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244\350\256\276\347\275\256", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\244\207\346\263\250(&B)", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\344\275\234\350\200\205", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254", nullptr));
        name_lineEdit->setText(QCoreApplication::translate("MainWindow", "Untitle", nullptr));
        auth_lineEdit->setText(QString());
        vv_lineEdit->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244(&Z)", nullptr));
        check_delet_pushButton->setText(QCoreApplication::translate("MainWindow", "\350\257\255\346\263\225\346\243\200\346\237\245", nullptr));
        delet_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\346\270\205\347\251\272", nullptr));
        copy_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\200\351\224\256\345\244\215\345\210\266", nullptr));
        cmd_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\214\207\344\273\244", nullptr));
        cmd_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\271\345\235\227", nullptr));
        cmd_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\347\211\251\345\223\201", nullptr));
        cmd_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\256\236\344\275\223", nullptr));

        cmd_lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\342\200\246\342\200\246", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\344\277\241\346\201\257\357\274\210\347\210\254\350\207\252wiki\357\274\211", nullptr));
        label_command->setText(QCoreApplication::translate("MainWindow", "\342\200\246\342\200\246", nullptr));
        label_des->setText(QCoreApplication::translate("MainWindow", "\342\200\246\342\200\246", nullptr));
        textBrowser_des->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:16px; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\226\271\345\235\227\350\256\276\347\275\256", nullptr));
        label_location_2->setText(QCoreApplication::translate("MainWindow", "(x,y,z)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263(&H)", nullptr));
        delay_lineEdit_3->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\345\273\266\350\277\237(&Y)", nullptr));
        label_location->setText(QCoreApplication::translate("MainWindow", "\351\200\211\344\270\255\346\226\271\345\235\227 ", nullptr));
        type_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\350\204\211\345\206\262", nullptr));
        type_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\350\277\236\351\224\201", nullptr));
        type_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\276\252\347\216\257", nullptr));

        checkBox->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "\346\211\247\350\241\214(&X)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\235\345\220\221(&C)", nullptr));
        condition_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240\346\235\241\344\273\266", nullptr));
        condition_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\234\211\346\235\241\344\273\266", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\226\271\345\235\227(&F)", nullptr));
        redstone_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263\346\216\247\345\210\266", nullptr));
        redstone_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\277\235\346\214\201\345\274\200\345\220\257", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "\346\235\241\344\273\266(&T)", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213(&L)", nullptr));
        block_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        block_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\345\221\275\344\273\244\346\226\271\345\235\227", nullptr));
        block_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\231\256\351\200\232\346\226\271\345\235\227", nullptr));
        block_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\345\231\250", nullptr));
        block_comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\347\272\242\347\237\263\347\201\253\346\212\212", nullptr));

        toward_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\345\214\227\357\274\210\342\206\221\357\274\211", nullptr));
        toward_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\234\357\274\210\342\206\222\357\274\211", nullptr));
        toward_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\345\215\227\357\274\210\342\206\223\357\274\211", nullptr));
        toward_comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\350\245\277\357\274\210\342\206\220\357\274\211", nullptr));

        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\234\260\345\233\276\347\274\226\350\276\221", nullptr));
        openminiwin_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\n"
"\346\202\254\346\265\256\347\252\227", nullptr));
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
