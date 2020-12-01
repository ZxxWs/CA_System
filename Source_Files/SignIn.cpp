#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
#include "../Header_Files/SignIn.h"
#include "../Class_File/InsertClass.h"
#include "qpushbutton.h"
#include "qstring.h"

using namespace std;

SignIn::SignIn(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->PushButtonSure = ui.PushButtonSure;
    this->PushButtonBack = ui.PushButtonBack;
    this->ComboBoxType = ui.ComboBoxType;
    this->LabelType = ui.LabelType;
    //this->LabelPass = ui.LabelPass;
    //this->LabelSurePass = ui.LabelSuerPass;
    //this->LabelCompany = ui.LabelCompany;
    //this->LabelTEL = ui.LabelTEL;
    //this->LabelMail = ui.LabelMail;
    //this->LabelRemark = ui.LabelRemark;
    this->LabelMessage = ui.LabelMessage;
    this->LineEditName = ui.LineEditName;
    this->LineEditPass = ui.LineEditPass;
    this->LineEditSurePass = ui.LineEditSurePass;
    this->LineEditCompany = ui.LineEditCompany;
    this->LineEditTEL = ui.LineEditTEL;
    this->LineEditMail = ui.LineEditMail;
    this->LineEditRemark = ui.LineEditRemark;
    this->LabelType->hide();
    this->ComboBoxType->hide();

    connect(ui.PushButtonSure, SIGNAL(clicked()), this, SLOT(ClickSureButton()));
    connect(ui.PushButtonBack, SIGNAL(clicked()), this, SLOT(ClickBackButton()));//将按钮和点击事件绑定


    QStringList str;
    str << "普通用户" << "管理员";
    this->ComboBoxType->insertItems(2, str);//填充下拉菜单

}

void SignIn::ClickSureButton() {

    //执行获取数据代码
    if (getData()) {
        
        InsertClass insert;
        insert.Ins(this->signInUser, 0);

        this->LabelMessage ->setText(QString::fromStdString(insert.tips));
    }
    else
    {

    }

}


void SignIn::ClickBackButton() {

    emit sendsignal();//给父界面传递被关闭信息
    this->close();

}


void SignIn::closeEvent(QCloseEvent* event) {
    emit sendsignal(); // 给父界面传递被关闭信息
}


//返回1：密码问题
bool SignIn::getData() {

    string s1, s2;

    s1 = this->LineEditSurePass->displayText().toStdString();

    this->signInUser.UserName = this->LineEditName->displayText().toStdString();
    this->signInUser.UserPassWord = this->LineEditPass->displayText().toStdString();
    this->signInUser.UserCompany = this->LineEditCompany->displayText().toStdString();
    this->signInUser.UserTEL = this->LineEditTEL->displayText().toStdString();
    this->signInUser.UserMail = this->LineEditMail->displayText().toStdString();
    this->signInUser.UserRemark = this->LineEditRemark->displayText().toStdString();

    /*s2 = this->ComboBoxType->currentText().toStdString();
    if (s2 == "普通用户") {
        this->signInUser.UserTag = 0;
    }
    else
    {
        this->signInUser.UserTag = 2;
    }*/

    this->signInUser.UserTag = 0;
    this->signInUser.IsCheck = 0;


    if (s1 != this->signInUser.UserPassWord) {
        this->LabelMessage->setText("请检查密码设置，\n确保两次密码输入相同");
        return false;
    }
    else if (this->signInUser.UserPassWord == "")
    {
        this->LabelMessage->setText("密码不能为空");
        return false;
    }
    else if (this->signInUser.UserCompany == "")
    {
        this->LabelMessage->setText("公司不能为空");
        return false;
    }
    else if (this->signInUser.UserTEL=="")
    {
        this->LabelMessage->setText("电话不能为空");
        return false;
    }
    else if (this->signInUser.UserMail == "")
    {
        this->LabelMessage->setText("邮箱不能为空");
        return false;
    }
    else
    {
        return true;
    }

}



