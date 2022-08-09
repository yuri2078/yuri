#pragma once
#include <QMainWindow>

class test : public QMainWindow {
    Q_OBJECT

public:
    test(QWidget* parent = nullptr);
    ~test();
};