#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Header_Files/Search.h"
#include "../Header_Files/ApplyFor.h"
#include "qstring.h"

using namespace std;

UserClass NowUser;

Search::Search(UserClass nowUser,QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ButtonApplyFor = ui.ButtonApplyFor;
    this->ButtonClearnText = ui.ButtonClearnText;
    this->ButtonExit = ui.ButtonExit;
    this->ButtonToSearch = ui.ButtonToSearch;
    this->LabelUserName = ui.LabelUserName;
    this->ComboBoxSearchKind = ui.ComboBoxSearchKind;
    this->TextEditSearchContent = ui.TextEditSearchContent;
    this->lab = ui.label;   //用于测试的label

    NowUser = nowUser;
    this->LabelUserName->setText(QString::fromStdString("用户：" + NowUser.getUserName()));

    QStringList str;
    str << "通过" << "游客" << "管理员";
    ComboBoxSearchKind->insertItems(3, str);//填充下拉菜单



    connect(ui.ButtonToSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));//将按钮和点击事件绑定
    connect(ui.ButtonExit, SIGNAL(clicked()), this, SLOT(ClickEixtButton()));
    connect(ui.ButtonApplyFor, SIGNAL(clicked()), this, SLOT(ClickApplyForButton()));
    connect(ui.ButtonClearnText, SIGNAL(clicked()), this, SLOT(ClickClearnTextButton()));
}

void Search::ClickSearchButton() {

    QString QSearchContent = this->TextEditSearchContent->toPlainText();
    this->lab->setText(QSearchContent);

}

void Search::ClickEixtButton() {

}


void Search::ClickApplyForButton() {


}


void Search::ClickClearnTextButton() {
    this->TextEditSearchContent->setText("");
}
