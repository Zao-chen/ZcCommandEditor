/********************************************************************************
** Form generated from reading UI file 'miniwindows.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIWINDOWS_H
#define UI_MINIWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_miniwindows
{
public:
    QTableWidget *tableWidget;
    QLabel *label_location;
    QLabel *label_block;
    QLabel *label_toward;
    QLabel *label_type;
    QLabel *label_redstone;
    QLabel *label_condition;
    QLabel *label_execute;
    QLabel *label_delay;
    QLabel *label_delay_2;
    QLabel *label_delay_3;
    QTextEdit *textEdit_notes;
    QTextEdit *textEdit_cmd;

    void setupUi(QWidget *miniwindows)
    {
        if (miniwindows->objectName().isEmpty())
            miniwindows->setObjectName("miniwindows");
        miniwindows->resize(549, 303);
        miniwindows->setStyleSheet(QString::fromUtf8("* {\n"
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
"    font-size: 10px;\n"
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
        tableWidget = new QTableWidget(miniwindows);
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
        tableWidget->setGeometry(QRect(0, 0, 291, 291));
        tableWidget->setMinimumSize(QSize(0, 0));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	padding: 0px;\n"
"	border: 0;\n"
"}"));
        tableWidget->setDragEnabled(false);
        label_location = new QLabel(miniwindows);
        label_location->setObjectName("label_location");
        label_location->setGeometry(QRect(300, 0, 241, 31));
        QFont font;
        font.setPointSize(12);
        label_location->setFont(font);
        label_block = new QLabel(miniwindows);
        label_block->setObjectName("label_block");
        label_block->setGeometry(QRect(300, 40, 241, 21));
        QFont font1;
        font1.setPointSize(10);
        label_block->setFont(font1);
        label_toward = new QLabel(miniwindows);
        label_toward->setObjectName("label_toward");
        label_toward->setGeometry(QRect(300, 60, 111, 21));
        label_toward->setFont(font1);
        label_type = new QLabel(miniwindows);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(410, 60, 131, 21));
        label_type->setFont(font1);
        label_redstone = new QLabel(miniwindows);
        label_redstone->setObjectName("label_redstone");
        label_redstone->setGeometry(QRect(410, 80, 131, 21));
        label_redstone->setFont(font1);
        label_condition = new QLabel(miniwindows);
        label_condition->setObjectName("label_condition");
        label_condition->setGeometry(QRect(300, 80, 111, 21));
        label_condition->setFont(font1);
        label_execute = new QLabel(miniwindows);
        label_execute->setObjectName("label_execute");
        label_execute->setGeometry(QRect(410, 100, 131, 21));
        label_execute->setFont(font1);
        label_delay = new QLabel(miniwindows);
        label_delay->setObjectName("label_delay");
        label_delay->setGeometry(QRect(300, 100, 111, 21));
        label_delay->setFont(font1);
        label_delay_2 = new QLabel(miniwindows);
        label_delay_2->setObjectName("label_delay_2");
        label_delay_2->setGeometry(QRect(300, 130, 41, 21));
        label_delay_2->setFont(font1);
        label_delay_3 = new QLabel(miniwindows);
        label_delay_3->setObjectName("label_delay_3");
        label_delay_3->setGeometry(QRect(300, 210, 41, 21));
        label_delay_3->setFont(font1);
        textEdit_notes = new QTextEdit(miniwindows);
        textEdit_notes->setObjectName("textEdit_notes");
        textEdit_notes->setGeometry(QRect(300, 150, 241, 51));
        textEdit_notes->setReadOnly(true);
        textEdit_cmd = new QTextEdit(miniwindows);
        textEdit_cmd->setObjectName("textEdit_cmd");
        textEdit_cmd->setGeometry(QRect(300, 230, 241, 61));
        textEdit_cmd->setReadOnly(true);

        retranslateUi(miniwindows);

        QMetaObject::connectSlotsByName(miniwindows);
    } // setupUi

    void retranslateUi(QWidget *miniwindows)
    {
        miniwindows->setWindowTitle(QCoreApplication::translate("miniwindows", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("miniwindows", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("miniwindows", "\346\226\260\345\273\272\345\210\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("miniwindows", "\346\226\260\345\273\272\350\241\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("miniwindows", "\346\226\260\345\273\272\350\241\214", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->item(0, 0);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("miniwindows", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->item(0, 1);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("miniwindows", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->item(1, 0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("miniwindows", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->item(1, 1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("miniwindows", "1", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_location->setText(QCoreApplication::translate("miniwindows", "\351\200\211\344\270\255\346\226\271\345\235\227\357\274\232", nullptr));
        label_block->setText(QCoreApplication::translate("miniwindows", "\346\226\271\345\235\227\357\274\232", nullptr));
        label_toward->setText(QCoreApplication::translate("miniwindows", "\346\234\235\345\220\221\357\274\232", nullptr));
        label_type->setText(QCoreApplication::translate("miniwindows", "\347\261\273\345\236\213\357\274\232", nullptr));
        label_redstone->setText(QCoreApplication::translate("miniwindows", "\347\272\242\347\237\263\357\274\232", nullptr));
        label_condition->setText(QCoreApplication::translate("miniwindows", "\346\235\241\344\273\266\357\274\232", nullptr));
        label_execute->setText(QCoreApplication::translate("miniwindows", "\346\211\247\350\241\214\357\274\232", nullptr));
        label_delay->setText(QCoreApplication::translate("miniwindows", "\345\273\266\350\277\237\357\274\232", nullptr));
        label_delay_2->setText(QCoreApplication::translate("miniwindows", "\345\244\207\346\263\250", nullptr));
        label_delay_3->setText(QCoreApplication::translate("miniwindows", "\345\221\275\344\273\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class miniwindows: public Ui_miniwindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIWINDOWS_H
