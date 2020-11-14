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
    //connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
    applyForWin->show();
 
    return a.exec();
}
