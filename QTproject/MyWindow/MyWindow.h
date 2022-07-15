#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QPushButton>
class MyWindow : public QDialog
{
	Q_OBJECT
	
public:
	MyWindow(QWidget *parent = nullptr);
	~MyWindow();

private:
	QPushButton *button;
};

#endif
