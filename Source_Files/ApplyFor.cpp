#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
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

    connect(ui.ButtonCreateDoubleKey, SIGNAL(clicked()), this, SLOT(ClickCreateDoubleKeyButton()));//����ť�͵���¼���
    connect(ui.ButtonCreateCertificate, SIGNAL(clicked()), this, SLOT(ClickCreateCertificateButton()));//����ť�͵���¼���
    connect(ui.ButtonBackSearch, SIGNAL(clicked()), this, SLOT(ClickBackSearchButton()));//����ť�͵���¼���

}

void ApplyFor::ClickCreateDoubleKeyButton() {


}


void ApplyFor::ClickCreateCertificateButton() {


}
