#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
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
    this->lab = ui.label;   //���ڲ��Ե�label

    NowUser = nowUser;
    this->LabelUserName->setText(QString::fromStdString("�û���" + NowUser.getUserName()));

    QStringList str;
    str << "ͨ��" << "�ο�" << "����Ա";
    ComboBoxSearchKind->insertItems(3, str);//��������˵�



    connect(ui.ButtonToSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));//����ť�͵���¼���
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
