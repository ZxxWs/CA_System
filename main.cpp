//#include "CA_System.h"
#include "Header_Files/CA_System.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CA_System w;
    w.show();
    return a.exec();
}
