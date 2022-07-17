#include "loginWidget.h"
#include <QMessageBox>

LoginWidget::LoginWidget(QWidget *parent) : 
    QDialog(parent),
    ui(new Ui::loginWidget)
{
    ui->setupUi(this); //设置 布局

    m_username = "yuri2078";
    m_passward = "yuri2078";

    //设置控件默认样式
    ui->loginButton->setEnabled(false);


    connect(ui->loginButton, &QPushButton::clicked, [this]() {
        QString name = ui->username->text();
        QString pass = ui->passward->text();
        if(name == this->m_username && pass == this->m_passward)
        {
            QMessageBox::information(this, "登陆成功", "欢迎光临", QMessageBox::Ok, QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::warning(this, "提示", "密码错误", QMessageBox::Cancel, QMessageBox::Ok);
        }
        
    });

    connect(ui->username, &QLineEdit::textChanged, this, &LoginWidget::checkInput);
    connect(ui->passward, &QLineEdit::textChanged, this, &LoginWidget::checkInput);
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

void LoginWidget::checkInput(void)

{
    QString name = ui->username->text();
    QString pass = ui->passward->text();

    if(name != "" && pass != "")
    {
        this->ui->loginButton->setEnabled(true);
    }
    else
    {
        this->ui->loginButton->setEnabled(false);
    }
}