/********************************************************************************
** Form generated from reading UI file 'calculator2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR2_H
#define UI_CALCULATOR2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calculator2
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLabel *label_2;

    void setupUi(QWidget *calculator2)
    {
        if (calculator2->objectName().isEmpty())
            calculator2->setObjectName(QString::fromUtf8("calculator2"));
        calculator2->resize(576, 417);
        widget = new QWidget(calculator2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 100, 513, 59));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout->addWidget(lineEdit_3);

        label_2 = new QLabel(calculator2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 200, 331, 131));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(calculator2);

        QMetaObject::connectSlotsByName(calculator2);
    } // setupUi

    void retranslateUi(QWidget *calculator2)
    {
        calculator2->setWindowTitle(QCoreApplication::translate("calculator2", "Form", nullptr));
        label->setText(QCoreApplication::translate("calculator2", "+", nullptr));
        pushButton->setText(QCoreApplication::translate("calculator2", "=", nullptr));
        label_2->setText(QCoreApplication::translate("calculator2", "\345\214\227\344\272\254\346\227\266\351\227\264\357\274\232 11\347\202\27111\345\210\20611\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class calculator2: public Ui_calculator2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR2_H
