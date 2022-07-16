#include <QApplication>
#include "SystemTime.h"

int main(int argc, char **argv)
{
	QApplication app(argc,argv);
	
	SystemTime time;
	time.show();

	return app.exec();
}
