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

    //填充下拉菜单--------------------------------
    QStringList str;
    str << "普通用户" << "游客" << "管理员";
    ComboBoxUserKind->insertItems(3,str);
    //填充下拉菜单--------------------------------


    //将按钮和点击事件绑定-------------------------
    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));
    connect(ui.ButtonSignIn, SIGNAL(clicked()), this, SLOT(ClickSignInButton()));
    //将按钮和点击事件绑定-------------------------


}

void CA_System::ClickLogInButton() {


    int t = getInputDate();//获取输入内容
    if ( t== 0) {

        UserClass LogUser = UserClass();

        SearchClass s = SearchClass(NowUser.UserName, "username", 0);
        s.toSearch();

        if (NowUser.UserPassWord == s.UserClassList[0].UserPassWord&& NowUser.UserTag == s.UserClassList[0].UserTag) {


            this->LabelTips->setText("");
            NowUser = s.UserClassList[0];
            Search* searchWin = new Search(s.UserClassList[0], this);
            connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//返回功能绑定，下个界面返回sendsignal，此界面searchWin，执行ReShowWindow
            searchWin->show();
            //////如果登录成功，跳转Search界面:0普通用户，1游客，2管理员
            this->hide();

        }
        else
        {
            this->LabelTips->setText("用户名或密码错误，请检查输入");
        }


    }
    else if(t==2)
    {
        Search* searchWin = new Search(NowUser, this);
        connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));
        searchWin->show();
        this->hide();
    }
   

    

}

void CA_System::ClickSignInButton() {

    this->hide();
    SignIn* signIn = new SignIn(this);
    connect(signIn, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//将此界面的ReShowWindow（）与signIn界面的sendsignal()绑定
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
        this->NowUser.UserTag = 1;
        return 2;
    }
    else if (this->NowUser.UserName == "" || this->NowUser.UserPassWord == "") {
        this->LabelTips->setText("用户名或密码不能为空");
        return 1;
    }

    return 0;


}


