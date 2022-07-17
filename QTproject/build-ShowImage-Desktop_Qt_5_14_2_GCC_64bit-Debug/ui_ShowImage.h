/********************************************************************************
** Form generated from reading UI file 'ShowImage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWIMAGE_H
#define UI_SHOWIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowImage
{
public:
    QFrame *frame;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *before;
    QSpacerItem *horizontalSpacer;
    QPushButton *next;

    void setupUi(QWidget *ShowImage)
    {
        if (ShowImage->objectName().isEmpty())
            ShowImage->setObjectName(QString::fromUtf8("ShowImage"));
        ShowImage->resize(777, 554);
        frame = new QFrame(ShowImage);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 761, 441));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        widget = new QWidget(ShowImage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(180, 480, 381, 49));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        before = new QPushButton(widget);
        before->setObjectName(QString::fromUtf8("before"));

        horizontalLayout->addWidget(before);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        next = new QPushButton(widget);
        next->setObjectName(QString::fromUtf8("next"));

        horizontalLayout->addWidget(next);


        retranslateUi(ShowImage);

        QMetaObject::connectSlotsByName(ShowImage);
    } // setupUi

    void retranslateUi(QWidget *ShowImage)
    {
        ShowImage->setWindowTitle(QCoreApplication::translate("ShowImage", "Form", nullptr));
        before->setText(QCoreApplication::translate("ShowImage", "\344\270\212\344\270\200\345\274\240", nullptr));
        next->setText(QCoreApplication::translate("ShowImage", "\344\270\213\344\270\200\345\274\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowImage: public Ui_ShowImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWIMAGE_H
