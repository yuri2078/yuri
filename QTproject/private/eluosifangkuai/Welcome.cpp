#include "Welcome.h"

Welcome::Welcome(QWidget *parent) :  QDialog(parent)
{
    ui = new Ui::Welcome;
    ui->setupUi(this);

    ui->spinBox->setRange(100, 1000);
    ui->horizontalSlider->setValue(300);
    ui->spinBox->setValue(300);

    connect(ui->start_button, &QPushButton::clicked, [this]() {
        tetris = new Tetris(nullptr,ui->spinBox->value());
        this->tetris->show();
        this->close();
    });

    
    QImage img(":/images/wallhaven-9m1jx8_3840x2400 (1).png");
    this->resize(img.size() / 2.5);
    this->ui->widget->move((this->width() - this->ui->widget->width()) / 2, this->ui->start_button->y() + 300);
    this->move((QApplication::desktop()->width() - this->width()) / 2, (QApplication::desktop()->height() - this->height()) / 2);
    this->ui->start_button->move((this->width() - ui->start_button->width()) / 2 , (this->height() - ui->start_button->height()) / 2 + 200);
    this->ui->label->move((this->width() - this->ui->label->width()) / 2, this->ui->start_button->y() - 200);

    connect(ui->horizontalSlider, &QSlider::valueChanged, [this]() {
        ui->spinBox->setValue(ui->horizontalSlider->value());
    });

    connect(ui->spinBox, QOverload<int>::of(&QSpinBox::valueChanged), [this]() {
        ui->horizontalSlider->setValue(ui->spinBox->value());
    });

}

void Welcome::paintEvent(QPaintEvent *ev)
{
    QImage img(":/images/wallhaven-9m1jx8_3840x2400 (1).png");
    QPainter painer(this);
    painer.drawImage(this->rect(), img);
}

Welcome::~Welcome()
{
    delete ui;
}

