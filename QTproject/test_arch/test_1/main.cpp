#include <QApplication>
#include <QDialog>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  
  QDialog dialog;
  dialog.show();
  dialog.resize(800,800);


  return app.exec();
}
