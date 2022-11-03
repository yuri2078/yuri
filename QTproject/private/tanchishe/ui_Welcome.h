/********************************************************************************
** Form generated from reading UI file 'Welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QPushButton *start_button;
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->resize(921, 787);
        Welcome->setCursor(QCursor(Qt::ArrowCursor));
        Welcome->setStyleSheet(QString::fromUtf8(""));
        start_button = new QPushButton(Welcome);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        start_button->setGeometry(QRect(320, 470, 281, 81));
        start_button->setCursor(QCursor(Qt::PointingHandCursor));
        start_button->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    width: 200px;\n"
"    height: 70px;\n"
"    /*\345\255\227\344\275\223\344\270\272\345\276\256\350\275\257\351\233\205\351\273\221*/\n"
"    font-family:Microsoft Yahei;\n"
"    /*\345\255\227\344\275\223\345\244\247\345\260\217\344\270\27220\347\202\271*/\n"
"    font-size:40pt;\n"
"    /*\345\255\227\344\275\223\351\242\234\350\211\262\344\270\272\347\231\275\350\211\262*/    \n"
"    color:black;\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:mistyrose;\n"
"    /*\350\276\271\346\241\206\345\234\206\350\247\222\345\215\212\345\276\204\344\270\2728\345\203\217\347\264\240*/ \n"
"    border-radius:14px;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\345\201\234\347\225\231\346\200\201*/\n"
"QPushButton:hover\n"
"{\n"
"    /*\350\203\214\346\231\257\351\242\234\350\211\262*/  \n"
"    background-color:LightPink;\n"
"}\n"
"\n"
"/*\346\214\211\351\222\256\346\214\211\344\270\213\346\200\201*/\n"
" QPushButton:pressed \n"
"{\n"
"    /*\350\203\214\346\231"
                        "\257\351\242\234\350\211\262*/  \n"
"    background-color:rgb(14 , 135 , 228);\n"
"    /*\345\267\246\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\345\217\263\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-left:3px;\n"
"    /*\344\270\212\345\206\205\350\276\271\350\267\235\344\270\2723\345\203\217\347\264\240\357\274\214\350\256\251\346\214\211\344\270\213\346\227\266\345\255\227\345\220\221\344\270\213\347\247\273\345\212\2503\345\203\217\347\264\240*/  \n"
"    padding-top:3px;\n"
"}"));
        start_button->setInputMethodHints(Qt::ImhNone);
        start_button->setIconSize(QSize(32, 16));
        start_button->setAutoDefault(false);
        label = new QLabel(Welcome);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 90, 791, 131));
        QFont font;
        font.setPointSize(60);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setMouseTracking(true);
        label->setFocusPolicy(Qt::NoFocus);
        label->setFrameShape(QFrame::NoFrame);
        label->setLineWidth(1);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        widget = new QWidget(Welcome);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(250, 610, 291, 111));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QFont font2;
        font2.setPointSize(16);
        horizontalSlider->setFont(font2);
        horizontalSlider->setMinimum(100);
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setSingleStep(50);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setFont(font2);
        spinBox->setSingleStep(50);

        horizontalLayout->addWidget(spinBox);


        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QCoreApplication::translate("Welcome", "Form", nullptr));
        start_button->setText(QCoreApplication::translate("Welcome", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
#if QT_CONFIG(shortcut)
        start_button->setShortcut(QString());
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("Welcome", "\346\254\242\350\277\216\346\235\245\345\210\260\350\264\252\345\220\203\350\233\207\346\270\270\346\210\217!", nullptr));
        label_2->setText(QCoreApplication::translate("Welcome", "\351\200\237\345\272\246\357\274\232 ms", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
