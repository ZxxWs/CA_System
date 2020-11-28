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
    this->LabelTips = ui.LabelTips;
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


    int t = getInputDate();
    if ( t== 0) {


        UserClass LogUser = UserClass();
        SearchClass s = SearchClass(NowUser.UserName, "username", 0);

        if (NowUser.UserPassWord == s.UserClassList[0].UserPassWord) {

            NowUser = s.UserClassList[0];
            Search* searchWin = new Search(NowUser, this);
            connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
            searchWin->show();
            //如果登录成功，跳转Search界面:0普通用户，1游客，2管理员
            this->hide();

        }
        else
        {
            this->LabelTips->setText("用户名或密码错误，请检查输入");
        }


    }
    else if(t==2)//游客登录
    {
        Search* searchWin = new Search(NowUser, this);
        connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
        searchWin->show();
        //如果登录成功，跳转Search界面:0普通用户，1游客，2管理员
        this->hide();
    }
   

    //ApplyFor* applyForWin =new ApplyFor(LogUser, this);
    //connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//当点击子界面EixtButton，调用主界面的reshow()函数-----未完成
    //applyForWin->show();

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

int CA_System::getInputDate() {

    this->NowUser.UserName = this->LineEditUserName->displayText().toStdString();
    this->NowUser.UserPassWord = this->LineEditUserPassWord->displayText().toStdString();
    this->NowUser.UserTag= this->ComboBoxUserKind->currentIndex();

    if (this->NowUser.UserTag == 1) {
        this->NowUser.UserName = "游客";
        this->NowUser.UserPassWord = "";
        return 2;
    }
    else if (this->NowUser.UserName == "" || this->NowUser.UserPassWord == "") {
        this->LabelTips->setText("用户名或密码不能为空");
        return 1;
    }

    return 0;


}

