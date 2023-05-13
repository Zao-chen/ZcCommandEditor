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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_update_ui
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label_ver;
    QLabel *label_con;
    QLabel *label_2;
    QLabel *label_file;
    QLabel *label_3;

    void setupUi(QDialog *update_ui)
    {
        if (update_ui->objectName().isEmpty())
            update_ui->setObjectName("update_ui");
        update_ui->resize(496, 420);
        label = new QLabel(update_ui);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 221, 41));
        pushButton = new QPushButton(update_ui);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 350, 93, 28));
        pushButton_2 = new QPushButton(update_ui);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 350, 93, 28));
        pushButton_3 = new QPushButton(update_ui);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(260, 350, 93, 28));
        label_ver = new QLabel(update_ui);
        label_ver->setObjectName("label_ver");
        label_ver->setGeometry(QRect(30, 50, 72, 15));
        label_con = new QLabel(update_ui);
        label_con->setObjectName("label_con");
        label_con->setGeometry(QRect(30, 100, 191, 16));
        label_2 = new QLabel(update_ui);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 160, 72, 15));
        label_file = new QLabel(update_ui);
        label_file->setObjectName("label_file");
        label_file->setGeometry(QRect(30, 170, 211, 81));
        label_3 = new QLabel(update_ui);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 80, 72, 15));

        retranslateUi(update_ui);

        QMetaObject::connectSlotsByName(update_ui);
    } // setupUi

    void retranslateUi(QDialog *update_ui)
    {
        update_ui->setWindowTitle(QCoreApplication::translate("update_ui", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("update_ui", "\345\217\221\347\216\260\346\226\260\347\211\210\346\234\254\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("update_ui", "\344\270\213\350\275\275", nullptr));
        pushButton_2->setText(QCoreApplication::translate("update_ui", "\346\237\245\347\234\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("update_ui", "\345\277\275\347\225\245", nullptr));
        label_ver->setText(QCoreApplication::translate("update_ui", "TextLabel", nullptr));
        label_con->setText(QCoreApplication::translate("update_ui", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("update_ui", "\346\226\207\344\273\266\345\210\227\350\241\250\357\274\232", nullptr));
        label_file->setText(QCoreApplication::translate("update_ui", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("update_ui", "\346\233\264\346\226\260\345\206\205\345\256\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class update_ui: public Ui_update_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_UI_H
