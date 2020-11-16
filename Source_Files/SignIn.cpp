#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "../Header_Files/SignIn.h"
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
    this->LabelPass = ui.LabelPass;
    this->LabelSurePass = ui.LabelSuerPass;
    this->LabelCompany = ui.LabelCompany;
    this->LabelTEL = ui.LabelTEL;
    this->LabelMail = ui.LabelMail;
    this->LabelRemark = ui.LabelRemark;
    this->LabelMessage = ui.LabelMessage;
    this->LineEditPass = ui.LineEditPass;
    this->LineEditSurePass = ui.LineEditSurePass;
    this->LineEditCompany = ui.LineEditCompany;
    this->LineEditTEL = ui.LineEditTEL;
    this->LineEditMail = ui.LineEditMail;
    this->LineEditRemark = ui.LineEditRemark;

    connect(ui.PushButtonSure, SIGNAL(clicked()), this, SLOT(ClickSureButton()));
    connect(ui.PushButtonBack, SIGNAL(clicked()), this, SLOT(ClickBackButton()));//����ť�͵���¼���


    QStringList str;
    str << "��ͨ�û�" << "����Ա";
    this->ComboBoxType->insertItems(2, str);//��������˵�

}

void SignIn::ClickSureButton() {

    //ִ�л�ȡ���ݴ���
    if (getData()) {



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
    this->signInUser.UserPassWord = this->LineEditPass->displayText().toStdString();
    s1 = this->LineEditSurePass->displayText().toStdString();

    if (s1 != this->signInUser.UserPassWord) {
        this->LabelMessage->setText("�����������ã�ȷ����������������ͬ");
        return 1;
    }
    this->signInUser.UserCompany = this->LineEditCompany->displayText().toStdString();
    this->signInUser.UserTEL = this->LineEditTEL->displayText().toStdString();
    this->signInUser.UserMail = this->LineEditMail->displayText().toStdString();
    this->signInUser.UserRemark = this->LineEditRemark->displayText().toStdString();
    s2 = this->ComboBoxType->currentText().toStdString();
    if (s2 == "��ͨ�û�") {
        this->signInUser.UserTag = 0;
    }
    else
    {
        this->signInUser.UserTag = 2;
    }

    return 0;
}

