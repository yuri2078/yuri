#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QDialog>
#include <QDebug>
#include "ui_loginWidget.h"

class LoginWidget : public QDialog
{
    Q_OBJECT
public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private:
    Ui::loginWidget *ui;
    QString m_username;
    QString m_passward;

public slots:

    void checkInput(void);
};

#endif