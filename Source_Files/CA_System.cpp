#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "../Header_Files/CA_System.h"
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"

using namespace std;

CA_System::CA_System(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ButtonLogIn = ui.ButtonLogIn;
    this->ButtonLogUp = ui.ButtonLogUp;
    this->LineEditUserName = ui.LineEditUserName;
    this->LineEditUserPassWord = ui.LineEditUserPassWord;
    this->ComboBoxUserKind = ui.ComboBoxUserKind;

    QStringList str;
    str << "��ͨ�û�" << "�ο�" << "����Ա";
    ComboBoxUserKind->insertItems(3,str);//��������˵�

    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));//����ť�͵���¼���

}

void CA_System::ClickLogInButton() {

    //LogerClass l;
    //l.setUserName("asd");
    SearchClass s=SearchClass("123","username",0);
    int a=s.toSearch();

    LineEditUserName->setText(QString::fromStdString(s.UserClassList[0].getUserPassWord()));

}
