#include <QApplication>
#include <QDialog>
#include <QPushButton>
int main(int argc,char **argv)
{
	QApplication app(argc,argv);

	QDialog dialog;
	
	QPushButton *button = new QPushButton("这是按钮",&dialog);
	dialog.resize(800,800);
	button->resize(200,30);
	button->move(300,300);
	QDialog::connect(button,&QPushButton::clicked,[&](){
			dialog.close();
		});


	dialog.show();
	return app.exec();
}
