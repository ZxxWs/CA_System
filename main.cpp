#include "Header_Files/CA_System.h"
#include "Class_File/UserClass.h"
#include "Header_Files/ApplyFor.h"
#include <QtWidgets/QApplication>
extern "C"
{
#include <openssl/applink.c>
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //CA_System w;
    //w.show();
    UserClass us = UserClass();

    /*ApplyFor ap = ApplyFor(us);
    ap.show();*/
    ApplyFor* applyForWin = new ApplyFor(us);
    //connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//������ӽ���EixtButton�������������reshow()����-----δ���
    applyForWin->show();
 
    return a.exec();
}
