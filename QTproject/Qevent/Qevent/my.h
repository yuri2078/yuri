#ifndef MY_H
#define MY_H

#include <QObject>
#include <QLabel>
#include <Qevent>
#include <QWidget>

class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
};

#endif