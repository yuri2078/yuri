#include <QApplication>
#include "ui_calculator2.h"
#include <QDialog>
int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	QDialog dialog;
	dialog.resize(800,800);
	Ui::calculator2 ui;
	ui.setupUi(&dialog);
	
	dialog.show();
	return app.exec();
}
