#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Header_Files/Search.h"
#include "../Header_Files/ApplyFor.h"
#include "qstring.h"

using namespace std;


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
    this->NowUser = nowUser;

    this->LabelUserName->setText(QString::fromStdString("�û���" + NowUser.UserName));

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



void Search::ClickApplyForButton() {

    this->hide();
    //UserClass u=this->NowUser;
    ApplyFor* applyForWin = new ApplyFor(this->NowUser,this);
    connect(applyForWin, SIGNAL(sendsignalApplyFor()), this, SLOT(ReShowWindow()));//������ӽ���EixtButton�������������ReShowWindow()����
    applyForWin->show();

}


void Search::ClickClearnTextButton() {
    this->TextEditSearchContent->setText("");
}


void Search::ReShowWindow() {
    this->show();
}

void Search::ClickEixtButton() {

    emit sendsignal();//�������洫�ݱ��ر���Ϣ
    this->close();
}


void Search::closeEvent(QCloseEvent* event) {

    emit sendsignal(); // �������洫�ݱ��ر���Ϣ

}



