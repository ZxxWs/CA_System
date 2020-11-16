#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "../Header_Files/CA_System.h"
#include "../Header_Files/ApplyFor.h"
#include "../Header_Files/Search.h"
#include "../Header_Files/SignIn.h"
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Class_File/CreateKeyPair.h"

using namespace std;

CA_System::CA_System(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ButtonLogIn = ui.ButtonLogIn;
    this->ButtonSignIn = ui.ButtonSignIn;
    this->LineEditUserName = ui.LineEditUserName;
    this->LineEditUserPassWord = ui.LineEditUserPassWord;
    this->ComboBoxUserKind = ui.ComboBoxUserKind;

    QStringList str;
    str << "��ͨ�û�" << "�ο�" << "����Ա";
    ComboBoxUserKind->insertItems(3,str);//��������˵�

    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));//����ť�͵���¼���
    connect(ui.ButtonSignIn, SIGNAL(clicked()), this, SLOT(ClickSignInButton()));

}

void CA_System::ClickLogInButton() {

    UserClass LogUser=UserClass();
    SearchClass s=SearchClass("123","username",0);
    int a=s.toSearch();

    LineEditUserName->setText(QString::fromStdString(s.UserClassList[0].getUserPassWord()));

    //�����¼�ɹ�����תSearch����:0��ͨ�û���1�οͣ�2����Ա
    this->hide();
    //Search* searchWin = new Search(LogUser, this);
    //connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//������ӽ���EixtButton�������������reshow()����-----δ���
    //searchWin->show();


    ApplyFor* applyForWin =new ApplyFor(LogUser, this);
    connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//������ӽ���EixtButton�������������reshow()����-----δ���
    applyForWin->show();

    //CreateKeyPair c = CreateKeyPair();

}

void CA_System::ClickSignInButton() {

    this->hide();
    SignIn* signIn = new SignIn(this);

    connect(signIn, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//���˽����ReShowWindow������signIn�����sendsignal��
    signIn->show();

}


void CA_System::ReShowWindow() {

    this->show();

}
