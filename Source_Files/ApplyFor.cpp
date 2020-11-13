#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
#include "../Header_Files/ApplyFor.h"
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"

using namespace std;

ApplyFor::ApplyFor(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.ButtonCreateDoubleKey, SIGNAL(clicked()), this, SLOT(ClickCreateDoubleKeyButton()));//将按钮和点击事件绑定
    connect(ui.ButtonCreateCertificate, SIGNAL(clicked()), this, SLOT(ClickCreateCertificateButton()));//将按钮和点击事件绑定
    connect(ui.ButtonBackSearch, SIGNAL(clicked()), this, SLOT(ClickBackSearchButton()));//将按钮和点击事件绑定

}

void ApplyFor::ClickCreateDoubleKeyButton() {


}


void ApplyFor::ClickCreateCertificateButton() {


}
