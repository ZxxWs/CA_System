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

    //��������˵�--------------------------------
    QStringList str;//QStringList����
    str << "��ͨ�û�" << "�ο�" << "����Ա";
    ComboBoxUserKind->insertItems(3,str);
    //��������˵�--------------------------------


    //����ť�͵���¼���-------------------------
    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));
    connect(ui.ButtonSignIn, SIGNAL(clicked()), this, SLOT(ClickSignInButton()));
    //UI�İ�ť���ʹ˽���ĵ��������
    //����ť�͵���¼���-------------------------


}

void CA_System::ClickLogInButton() {


    int t = getInputDate();//����getInputDate��ȡ��������
    if ( t== 0) {

        UserClass LogUser = UserClass();

        SearchClass s = SearchClass(NowUser.UserName, "username", 0);
        s.toSearch();//ִ�в�ѯ

        if (NowUser.UserPassWord == s.UserClassList[0].UserPassWord&& NowUser.UserTag == s.UserClassList[0].UserTag) {


            this->LabelTips->setText("");

            NowUser = s.UserClassList[0];//δ�ñ���
            Search* searchWin = new Search(s.UserClassList[0], this);
            connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//���ع��ܰ󶨣��¸����淵��sendsignal���˽���searchWin��ִ��ReShowWindow
            searchWin->show();
            this->hide();

        }
        else
        {
            this->LabelTips->setText("�û��������������������");
        }


    }
    else if(t==2)
    {
        Search* searchWin = new Search(NowUser,this);//thisָ��ǰ����
        connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//��searchWin���桢searchWin�����sendsignal��Ϣ��ReShowWindow������
        searchWin->show();
        this->hide();//���ص�ǰ����
    }
   
}

void CA_System::ClickSignInButton() {

    this->hide();
    SignIn* signIn = new SignIn(this);
    connect(signIn, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//���˽����ReShowWindow������signIn�����sendsignal()��
    signIn->show();

}


void CA_System::ReShowWindow() {
    this->show();
}

int CA_System::getInputDate() {

    //���õ�ǰUser������Ϊ��ȡ������-----------------------------
    this->NowUser.UserName = this->LineEditUserName->displayText().toStdString();
    this->NowUser.UserPassWord = this->LineEditUserPassWord->displayText().toStdString();
    this->NowUser.UserTag= this->ComboBoxUserKind->currentIndex();
    //���õ�ǰUser������Ϊ��ȡ������-------------------------------

    //���ѡ����ǡ��ο͡�
    if (this->NowUser.UserTag == 1) {
        this->NowUser.UserName = "�ο�";
        this->NowUser.UserTag = 1;
        return 2;
    }
    //��������п�
    else if (this->NowUser.UserName == "" || this->NowUser.UserPassWord == "") {
        this->LabelTips->setText("�û��������벻��Ϊ��");
        return 1;
    }

    return 0;

}


