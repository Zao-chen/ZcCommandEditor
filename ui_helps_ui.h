/********************************************************************************
** Form generated from reading UI file 'helps_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPS_UI_H
#define UI_HELPS_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helps_ui
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helps_ui)
    {
        if (helps_ui->objectName().isEmpty())
            helps_ui->setObjectName("helps_ui");
        helps_ui->resize(433, 386);
        centralwidget = new QWidget(helps_ui);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem10);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(10, 10, 411, 331));
        helps_ui->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helps_ui);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 433, 21));
        helps_ui->setMenuBar(menubar);
        statusbar = new QStatusBar(helps_ui);
        statusbar->setObjectName("statusbar");
        helps_ui->setStatusBar(statusbar);

        retranslateUi(helps_ui);

        QMetaObject::connectSlotsByName(helps_ui);
    } // setupUi

    void retranslateUi(QMainWindow *helps_ui)
    {
        helps_ui->setWindowTitle(QCoreApplication::translate("helps_ui", "MainWindow", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("helps_ui", "\346\214\211\351\224\256", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("helps_ui", "\350\257\264\346\230\216", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("helps_ui", "\346\224\276\347\275\256\347\251\272\346\260\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("helps_ui", "\346\224\276\347\275\256\345\221\275\344\273\244\346\226\271\345\235\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("helps_ui", "\346\224\276\347\275\256\346\231\256\351\200\232\346\226\271\345\235\227", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("helps_ui", "a", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(0, 1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("helps_ui", "air", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("helps_ui", "c", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(1, 1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("helps_ui", "command_block", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(2, 0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("helps_ui", "b", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->item(2, 1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("helps_ui", "block", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class helps_ui: public Ui_helps_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPS_UI_H
