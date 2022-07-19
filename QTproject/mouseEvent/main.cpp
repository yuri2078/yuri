#include <QApplication>
#include "mouseEvent.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	mouseEvent mouseevent;
	mouseevent.show();

	
	return app.exec();
}
