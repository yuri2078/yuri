#ifndef SYSTEMTIME_H
#define SYSTEMTIME_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTime>

class SystemTime : public QDialog
{
	Q_OBJECT
public:
	SystemTime(QWidget *parent = nullptr);
	~SystemTime();
private:
	QPushButton *getTime;
	QLabel *showTime;
	QVBoxLayout *layout;

signals:
	
};


#endif
