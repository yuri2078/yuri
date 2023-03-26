/********************************************************************************
** Form generated from reading UI file 'Tetris.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRIS_H
#define UI_TETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    QWidget *main_widget;
    QPushButton *start_button;
    QPushButton *stop_button;
    QWidget *show_next;
    QLabel *score_label;
    QLabel *tips_label;

    void setupUi(QWidget *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName(QString::fromUtf8("Tetris"));
        Tetris->resize(1200, 800);
        Tetris->setStyleSheet(QString::fromUtf8("background-color: rgb(214, 153, 198);"));
        main_widget = new QWidget(Tetris);
        main_widget->setObjectName(QString::fromUtf8("main_widget"));
        main_widget->setGeometry(QRect(0, 0, 800, 800));
        main_widget->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);"));
        start_button = new QPushButton(Tetris);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(900, 600, 211, 81));
        QFont font;
        font.setPointSize(30);
        start_button->setFont(font);
        start_button->setCursor(QCursor(Qt::PointingHandCursor));
        start_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        stop_button = new QPushButton(Tetris);
        stop_button->setObjectName(QString::fromUtf8("stop_button"));
        stop_button->setGeometry(QRect(890, 710, 231, 81));
        stop_button->setFont(font);
        stop_button->setCursor(QCursor(Qt::PointingHandCursor));
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
        show_next = new QWidget(Tetris);
        show_next->setObjectName(QString::fromUtf8("show_next"));
        show_next->setGeometry(QRect(810, 50, 381, 281));
        QFont font1;
        font1.setStyleStrategy(QFont::NoAntialias);
        show_next->setFont(font1);
        show_next->setStyleSheet(QString::fromUtf8("background-color: rgb(98, 160, 234);\n"
"border-radius: 30px;"));
        score_label = new QLabel(show_next);
        score_label->setObjectName(QString::fromUtf8("score_label"));
        score_label->setGeometry(QRect(50, 90, 281, 101));
        QFont font2;
        font2.setPointSize(40);
        score_label->setFont(font2);
        tips_label = new QLabel(Tetris);
        tips_label->setObjectName(QString::fromUtf8("tips_label"));
        tips_label->setGeometry(QRect(860, 410, 281, 151));
        QFont font3;
        font3.setPointSize(15);
        tips_label->setFont(font3);
        tips_label->setFrameShape(QFrame::Box);
        tips_label->setFrameShadow(QFrame::Raised);
        tips_label->setAlignment(Qt::AlignCenter);

        retranslateUi(Tetris);

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QWidget *Tetris)
    {
        Tetris->setWindowTitle(QCoreApplication::translate("Tetris", "Form", nullptr));
        start_button->setText(QCoreApplication::translate("Tetris", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        stop_button->setText(QCoreApplication::translate("Tetris", "\346\232\202\345\201\234", nullptr));
        score_label->setText(QCoreApplication::translate("Tetris", "\345\276\227\345\210\206\357\274\232 0  \345\210\206", nullptr));
        tips_label->setText(QCoreApplication::translate("Tetris", "\346\214\211 sad \351\224\256\347\247\273\345\212\250  W \351\224\256\346\227\213\350\275\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRIS_H
