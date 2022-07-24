#include "Tetris.h"

Tetris::Tetris(QWidget *parent, int spead) : QDialog(parent)
{
    this->spead = spead;

    ui = new Ui::Tetris;
    ui->setupUi(this);

    setMap();
    Square *temp = new Square(this, 1,25,25);
}

void Tetris::setMap(void)
{
    square = new Square** [ ui->main_widget->height()/Square(this).height()];
    for (int i = 0; i < ui->main_widget->height()/Square(this).height();i++)
    {
        square[i] = new Square *[ui->main_widget->width()/Square(this).width()];
        for (int j = 0; j < ui->main_widget->width()/Square(this).width(); j++)
        {
            square[i][j] = new Square(this);
            square[i][j]->move(j * Square(this).width(), i * Square(this).height());
        }
    }
    
}

Tetris::~Tetris()
{
    delete ui;
}
