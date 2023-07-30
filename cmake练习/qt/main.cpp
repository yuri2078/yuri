#include <iostream>
#include <QWidget>
#include <QApplication>

int main(int argc, char **argv) {
  QApplication app(argc, argv);
  QWidget wdight;
  wdight.show();

  return app.exec();
}
