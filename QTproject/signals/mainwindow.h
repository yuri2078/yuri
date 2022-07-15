#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>

class mainwindow : public QDialog
{
	Q_OBJECT
public:
	mainwindow(QWidget *parent = nullptr);
	~mainwindow();
	void myClose();
private:	
	
signals:
	void laugh(); //定义信号
};

#endif
