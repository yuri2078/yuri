#ifndef MOUSEENENT_H
#define MOUSEEVENT_H

#include <QDialog>
#include <QMouseEvent>
class mouseEvent : public QDialog
{
	Q_OBJECT
public:
	mouseEvent(QWidget *parent = nullptr);
	~mouseEvent();
	void mouseMoveEvent(QMouseEvent *ev);
	void mousePressEvent(QMouseEvent *event); 

private:
	bool is_left;
	QPoint *click_pos;
	QPoint *widget_pos;

	QWidget *square;

public slots:
signals:
};

#endif
