#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

class mainwindow : public QDialog
{
	Q_OBJECT
public:
	mainwindow(QWidget *parent = nullptr);
	~mainwindow();
public slots:
	//这里写槽函数
private:

signals:

};

#endif
