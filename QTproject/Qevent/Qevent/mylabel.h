#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    void enterEvent(QEnterEvent *event); //鼠标进入
    void leaveEvent(QEvent *event); //鼠标离开
    // virtual void changeEvent(QEvent *ev) ;
    // virtual void contextMenuEvent(QContextMenuEvent *ev) ;
    // virtual bool event(QEvent *e) override;
    // virtual void focusInEvent(QFocusEvent *ev) override;
    // virtual bool focusNextPrevChild(bool next) override;
    // virtual void focusOutEvent(QFocusEvent *ev) override;
    // virtual void keyPressEvent(QKeyEvent *ev) override;
    virtual void mouseMoveEvent(QMouseEvent *ev) override; //鼠标移动
    virtual void mousePressEvent(QMouseEvent *ev) override; //鼠标按下
    virtual void mouseReleaseEvent(QMouseEvent *ev) override; //鼠标释放
    // virtual void paintEvent(QPaintEvent *) override;
    void clean_log();
    bool event(QEvent *e); //拦截用户的事件

signals:

};

#endif // MYLABEL_H
