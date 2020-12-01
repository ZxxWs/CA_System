#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
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
    connect(ui.PushButtonBack, SIGNAL(clicked()), this, SLOT(ClickBackButton()));//����ť�͵���¼���


    QStringList str;
    str << "��ͨ�û�" << "����Ա";
    this->ComboBoxType->insertItems(2, str);//��������˵�

}

void SignIn::ClickSureButton() {

    //ִ�л�ȡ���ݴ���
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

    emit sendsignal();//�������洫�ݱ��ر���Ϣ
    this->close();

}


void SignIn::closeEvent(QCloseEvent* event) {
    emit sendsignal(); // �������洫�ݱ��ر���Ϣ
}


//����1����������
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
    if (s2 == "��ͨ�û�") {
        this->signInUser.UserTag = 0;
    }
    else
    {
        this->signInUser.UserTag = 2;
    }*/

    this->signInUser.UserTag = 0;
    this->signInUser.IsCheck = 0;


    if (s1 != this->signInUser.UserPassWord) {
        this->LabelMessage->setText("�����������ã�\nȷ����������������ͬ");
        return false;
    }
    else if (this->signInUser.UserPassWord == "")
    {
        this->LabelMessage->setText("���벻��Ϊ��");
        return false;
    }
    else if (this->signInUser.UserCompany == "")
    {
        this->LabelMessage->setText("��˾����Ϊ��");
        return false;
    }
    else if (this->signInUser.UserTEL=="")
    {
        this->LabelMessage->setText("�绰����Ϊ��");
        return false;
    }
    else if (this->signInUser.UserMail == "")
    {
        this->LabelMessage->setText("���䲻��Ϊ��");
        return false;
    }
    else
    {
        return true;
    }

}



