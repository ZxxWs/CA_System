#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
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
    str << "普通用户" << "游客" << "管理员";
    ComboBoxUserKind->insertItems(3,str);//填充下拉菜单

    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));//将按钮和点击事件绑定
    connect(ui.ButtonSignIn, SIGNAL(clicked()), this, SLOT(ClickSignInButton()));

}

void CA_System::ClickLogInButton() {

    UserClass LogUser=UserClass();
    SearchClass s=SearchClass("123","username",0);
    int a=s.toSearch();

    LineEditUserName->setText(QString::fromStdString(s.UserClassList[0].getUserPassWord()));

    //如果登录成功，跳转Search界面:0普通用户，1游客，2管理员
    this->hide();
    //Search* searchWin = new Search(LogUser, this);
    //connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
    //searchWin->show();


    ApplyFor* applyForWin =new ApplyFor(LogUser, this);
    connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
    applyForWin->show();

    //CreateKeyPair c = CreateKeyPair();

}

void CA_System::ClickSignInButton() {

    this->hide();
    SignIn* signIn = new SignIn(this);

    connect(signIn, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//将此界面的ReShowWindow（）与signIn界面的sendsignal绑定
    signIn->show();

}


void CA_System::ReShowWindow() {

    this->show();

}
