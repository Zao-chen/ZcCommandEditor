/********************************************************************************
** Form generated from reading UI file 'update_ui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_UI_H
#define UI_UPDATE_UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_update_ui
{
public:
    QLabel *label;
    QLabel *label_ver;
    QLabel *label_con;
    QLabel *label_2;
    QLabel *label_file;
    QLabel *label_3;
    QLabel *label_text;
    QLabel *label_4;
    QLabel *label_ver_old;

    void setupUi(QDialog *update_ui)
    {
        if (update_ui->objectName().isEmpty())
            update_ui->setObjectName("update_ui");
        update_ui->resize(496, 357);
        update_ui->setStyleSheet(QString::fromUtf8("* {\n"
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
        label = new QLabel(update_ui);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 110, 71, 16));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label_ver = new QLabel(update_ui);
        label_ver->setObjectName("label_ver");
        label_ver->setGeometry(QRect(220, 130, 72, 16));
        label_con = new QLabel(update_ui);
        label_con->setObjectName("label_con");
        label_con->setGeometry(QRect(20, 190, 461, 41));
        label_con->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2 = new QLabel(update_ui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 240, 72, 15));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        label_2->setFont(font1);
        label_file = new QLabel(update_ui);
        label_file->setObjectName("label_file");
        label_file->setGeometry(QRect(20, 260, 461, 71));
        label_file->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3 = new QLabel(update_ui);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 170, 72, 15));
        label_3->setFont(font);
        label_text = new QLabel(update_ui);
        label_text->setObjectName("label_text");
        label_text->setGeometry(QRect(40, 10, 401, 51));
        QFont font2;
        font2.setPointSize(15);
        label_text->setFont(font2);
        label_text->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(update_ui);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(220, 110, 71, 16));
        label_4->setFont(font);
        label_ver_old = new QLabel(update_ui);
        label_ver_old->setObjectName("label_ver_old");
        label_ver_old->setGeometry(QRect(20, 130, 72, 21));

        retranslateUi(update_ui);

        QMetaObject::connectSlotsByName(update_ui);
    } // setupUi

    void retranslateUi(QDialog *update_ui)
    {
        update_ui->setWindowTitle(QCoreApplication::translate("update_ui", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("update_ui", "\345\275\223\345\211\215\347\211\210\346\234\254\357\274\232", nullptr));
        label_ver->setText(QCoreApplication::translate("update_ui", "loading", nullptr));
        label_con->setText(QCoreApplication::translate("update_ui", "loading", nullptr));
        label_2->setText(QCoreApplication::translate("update_ui", "\346\226\207\344\273\266\345\210\227\350\241\250\357\274\232", nullptr));
        label_file->setText(QCoreApplication::translate("update_ui", "loading", nullptr));
        label_3->setText(QCoreApplication::translate("update_ui", "\346\233\264\346\226\260\345\206\205\345\256\271", nullptr));
        label_text->setText(QCoreApplication::translate("update_ui", "\345\275\223\345\211\215\345\267\262\346\230\257\346\234\200\346\226\260\347\211\210", nullptr));
        label_4->setText(QCoreApplication::translate("update_ui", "\346\234\200\346\226\260\347\211\210\346\234\254\357\274\232", nullptr));
        label_ver_old->setText(QCoreApplication::translate("update_ui", "loading", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update_ui: public Ui_update_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_UI_H
