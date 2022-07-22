#include "Welcome.h"


Welcome::Welcome(QWidget *parent) :  QDialog(parent)
{
    ui = new Ui::Welcome;
    ui->setupUi(this);

    connect(ui->start_button, &QPushButton::clicked, [this]() {
        Snake *snake = new Snake;
        snake->show();
        this->close();
    });
}

void Welcome::paintEvent(QPaintEvent *ev)
{
    QImage img(":/images/wallhaven-9m1jx8_3840x2400 (1).png");
    QPainter painer(this);
    this->resize(img.size() / 2.5);
    this->move((QApplication::desktop()->width() - this->width()) / 2, (QApplication::desktop()->height() - this->height()) / 2);
    this->ui->start_button->move((this->width() - ui->start_button->width()) / 2, (this->height() - ui->start_button->height()) / 2);
    painer.drawImage(this->rect(), img);
}

Welcome::~Welcome()
{
    delete ui;
}