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

#include <strstream>
#include <sstream>
#include <string>
#include <random>
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
    str << "��ͨ�û�" << "�ο�" << "����Ա";
    ComboBoxUserKind->insertItems(3,str);//��������˵�

    connect(ui.ButtonLogIn, SIGNAL(clicked()), this, SLOT(ClickLogInButton()));//����ť�͵���¼���
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
            connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//������ӽ���EixtButton�������������reshow()����-----δ���
            searchWin->show();
            //�����¼�ɹ�����תSearch����:0��ͨ�û���1�οͣ�2����Ա
            this->hide();

        }
        else
        {
            this->LabelTips->setText("�û��������������������");
        }


    }
    else if(t==2)//�ο͵�¼
    {
        Search* searchWin = new Search(NowUser, this);
        connect(searchWin, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//������ӽ���EixtButton�������������reshow()����-----δ���
        searchWin->show();
        //�����¼�ɹ�����תSearch����:0��ͨ�û���1�οͣ�2����Ա
        this->hide();
    }
   

    //ApplyFor* applyForWin =new ApplyFor(LogUser, this);
    //connect(applyForWin, SIGNAL(sendsignal()), this, SLOT(ReShowThis()));//������ӽ���EixtButton�������������reshow()����-----δ���
    //applyForWin->show();

    //CreateKeyPair c = CreateKeyPair();

}

void CA_System::ClickSignInButton() {

    this->hide();
    SignIn* signIn = new SignIn(this);
    connect(signIn, SIGNAL(sendsignal()), this, SLOT(ReShowWindow()));//���˽����ReShowWindow������signIn�����sendsignal��
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
        this->NowUser.UserName = "�ο�";
        this->NowUser.UserPassWord = "";
        return 2;
    }
    else if (this->NowUser.UserName == "" || this->NowUser.UserPassWord == "") {
        this->LabelTips->setText("�û��������벻��Ϊ��");
        return 1;
    }

    return 0;


}



//ͨ����ѯ���ݿ�������һ��CertID
long CreateCertID() {

    string s1, s2;//��ѯ���е�CertID
    long CertID;
    do {

        default_random_engine e(time(0));//���������
        CertID = e();

        //longתstring
        ostringstream os;
        os << CertID;

        string strCertID;
        istringstream is(os.str());
        is >> strCertID;

        SearchClass search1 = SearchClass(strCertID, "CertID", 1);
        SearchClass search2 = SearchClass(strCertID, "CertID", 2);
        search1.toSearch();
        search2.toSearch();
        s1 = search1.certificateTable[0].CertID;
        s2 = search2.certificateTable[0].CertID;


    } while (s1 != "" || s2 != "");

    return CertID;
    //return 12121212;

}



