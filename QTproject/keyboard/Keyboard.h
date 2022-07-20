#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QDebug>

class Keyboard : public QDialog
{
    Q_OBJECT
private:
    QLabel *label;

public:
    Keyboard(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *);
    ~Keyboard();
};




#endif
