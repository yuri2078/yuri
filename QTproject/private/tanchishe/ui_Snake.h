/********************************************************************************
** Form generated from reading UI file 'Snake.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAKE_H
#define UI_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Snake
{
public:
    QWidget *widget;
    QLabel *label_1;
    QLabel *score;
    QPushButton *stop_button;
    QLabel *tips_1;
    QLabel *tips_2;
    QPushButton *over_button;

    void setupUi(QWidget *Snake)
    {
        if (Snake->objectName().isEmpty())
            Snake->setObjectName(QString::fromUtf8("Snake"));
        Snake->resize(1000, 800);
        QFont font;
        font.setPointSize(20);
        Snake->setFont(font);
        Snake->setToolTipDuration(0);
        Snake->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);"));
        widget = new QWidget(Snake);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 800, 800));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);"));
        label_1 = new QLabel(Snake);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(800, 130, 201, 121));
        QFont font1;
        font1.setPointSize(30);
        label_1->setFont(font1);
        label_1->setAlignment(Qt::AlignCenter);
        score = new QLabel(Snake);
        score->setObjectName(QString::fromUtf8("score"));
        score->setGeometry(QRect(800, 250, 191, 91));
        QFont font2;
        font2.setPointSize(50);
        score->setFont(font2);
        score->setAlignment(Qt::AlignCenter);
        stop_button = new QPushButton(Snake);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setGeometry(QRect(820, 450, 161, 61));
        stop_button->setFont(font1);
        stop_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius: 20px;\n"
"	background-color: rgb(35, 193, 238);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	font-size:35px;\n"
"	background-color: rgb(20, 242, 242);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	font-size:32px;\n"
"	\n"
"	background-color: rgb(11, 230, 244);\n"
"}"));
        tips_1 = new QLabel(Snake);
        tips_1->setObjectName(QString::fromUtf8("tips_1"));
        tips_1->setGeometry(QRect(820, 620, 161, 91));
        QFont font3;
        font3.setPointSize(14);
        tips_1->setFont(font3);
        tips_1->setAlignment(Qt::AlignCenter);
        tips_2 = new QLabel(Snake);
        tips_2->setObjectName(QString::fromUtf8("tips_2"));
        tips_2->setGeometry(QRect(820, 700, 171, 71));
        QFont font4;
        font4.setPointSize(15);
        tips_2->setFont(font4);
        tips_2->setAlignment(Qt::AlignCenter);
        over_button = new QPushButton(Snake);
        over_button->setObjectName(QString::fromUtf8("over_button"));
        over_button->setGeometry(QRect(820, 570, 161, 61));
        over_button->setFont(font1);
        over_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	border-radius: 20px;\n"
"	background-color: rgb(35, 193, 238);\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	font-size:35px;\n"
"	background-color: rgb(20, 242, 242);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	font-size:32px;\n"
"	\n"
"	background-color: rgb(11, 230, 244);\n"
"}"));

        retranslateUi(Snake);

        QMetaObject::connectSlotsByName(Snake);
    } // setupUi

    void retranslateUi(QWidget *Snake)
    {
        Snake->setWindowTitle(QCoreApplication::translate("Snake", "Form", nullptr));
        label_1->setText(QCoreApplication::translate("Snake", "\345\275\223\345\211\215\345\210\206\346\225\260", nullptr));
        score->setText(QCoreApplication::translate("Snake", "0", nullptr));
        stop_button->setText(QCoreApplication::translate("Snake", "\346\232\202\345\201\234", nullptr));
        tips_1->setText(QCoreApplication::translate("Snake", "W \357\274\232 \344\270\212     S \357\274\232 \344\270\213", nullptr));
        tips_2->setText(QCoreApplication::translate("Snake", "A \357\274\232 \345\267\246     D \357\274\232 \345\217\263", nullptr));
        over_button->setText(QCoreApplication::translate("Snake", "\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Snake: public Ui_Snake {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAKE_H
