#include "Gurdual.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Gurdual w;
	w.show();
	return a.exec();
}
