#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������

#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Class_File/DeleteClass.h"
#include "../Header_Files/Search.h"
#include "../Header_Files/ApplyFor.h"
#include "qstring.h"
#include "qpushbutton.h"
#include "../Class_File/InsertClass.h"

using namespace std;


Search::Search(UserClass nowUser,QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ButtonApplyFor = ui.ButtonApplyFor;
    this->ButtonClearnText = ui.ButtonClearnText;
    this->ButtonExit = ui.ButtonExit;
    this->ButtonToSearch = ui.ButtonToSearch;
    this->ButtonDelete = ui.ButtonDelete;
    this->LabelUserName = ui.LabelUserName;
    this->LabelCertState = ui.LabelCertState;
    this->LabelCertCreateTime = ui.LabelCertCreateTime;
    this->LabelCertDieTime = ui.LabelCertDieTime;
    this->LabelCert = ui.LabelCert;
    this->LabelCertID = ui.LabelCertID;
    this->LabelClientName = ui.LabelClientName;
    this->ComboBoxSearchKind = ui.ComboBoxSearchKind;
    this->TextEditSearchContent = ui.TextEditSearchContent;
    this->TextEditCert = ui.TextEditCert;
    this->LineEditCertID = ui.LineEditCertID;
    this->LineEditClientName = ui.LineEditClientName;
    this->LineEditCertCreateTime = ui.LineEditCertCreateTime;
    this->LineEditCertDieTime = ui.LineEditCertDieTime;
    this->LineEditCertState = ui.LineEditCertState;

    HideOrShow(0);

    if (nowUser.UserTag != 0) {//����û�������ͨ�û�������ʾ���밴ť
        this->ButtonApplyFor->hide();
    }

    this->lab = ui.label;   //���ڲ��Ե�label
    
    this->NowUser = nowUser;
    this->LabelUserName->setText(QString::fromStdString("�û���" + NowUser.UserName));

    QStringList str;
    str << "ͨ��֤��Ų�ѯ" << "ͨ��֤���ַ�����ѯ" << "";
    ComboBoxSearchKind->insertItems(3, str);//��������˵�

    connect(ui.ButtonToSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));//����ť�͵���¼���
    connect(ui.ButtonExit, SIGNAL(clicked()), this, SLOT(ClickEixtButton()));
    connect(ui.ButtonApplyFor, SIGNAL(clicked()), this, SLOT(ClickApplyForButton()));
    connect(ui.ButtonClearnText, SIGNAL(clicked()), this, SLOT(ClickClearnTextButton()));
    connect(ui.ButtonDelete, SIGNAL(clicked()), this, SLOT(ClickDeleteButton()));
}


//���ݲ��١�������
void Search::ClickSearchButton() {

    HideOrShow(0);
    string SearchContent = this->TextEditSearchContent->toPlainText().toStdString();
    
    SearchClass Sear = SearchClass(SearchContent, SearchKind[this->ComboBoxSearchKind->currentIndex()], 1);
    Sear.toSearch();


    this->delCert = Sear.certificateTable[0];
    if (delCert.CertID == "") {//��һ����Ϊ��
        Sear.setData(SearchContent, SearchKind[this->ComboBoxSearchKind->currentIndex()], 2);
        Sear.toSearch();
        this->delCert = Sear.dieCertificateTable[0];
        //this->ButtonDelete->show();
    }


    if(delCert.CertID!=""){
        HideOrShow(1);
        this->LineEditCertID->setText(QString::fromStdString(this->delCert.CertID));
        this->TextEditCert->setText(QString::fromStdString(this->delCert.Certificate));
        this->LineEditClientName->setText(QString::fromStdString(this->delCert.ClientName));

        this->LineEditCertCreateTime->setText(QString::fromStdString(shiftTime(this->delCert.CreateTime)));
        this->LineEditCertDieTime->setText(QString::fromStdString(shiftTime(this->delCert.DieTime)));

        string str = shiftTime(this->delCert.DeleteTime);
        if (this->delCert.DeleteTime != "") {
            str += "��ɾ��";
        }
        this->LineEditCertState->setText(QString::fromStdString(str));
    }


    if (this->delCert.DeleteTime == ""&&(this->NowUser.UserName==this->delCert.ClientName||this->NowUser.UserTag==2)) {
        this->ButtonDelete->show();
    }
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

string Search::shiftTime(string tm)
{
    if (tm == "") {
        return "֤��δ����";
    }

    //����Ϊ���ݿ����string���͵�ʱ��
    string returnTm;
    long longTm = atoi(tm.c_str());
    time_t _tTm = time_t(longTm);
    struct tm* stTm = localtime(&_tTm);

    returnTm = to_string(stTm->tm_year + 1900)+"��/";
    returnTm += to_string(stTm->tm_mon + 1) + "��/";
    returnTm += to_string(stTm->tm_mday)+"��  ";
    returnTm += to_string(stTm->tm_hour) + ":";
    returnTm += to_string(stTm->tm_min) + ":";
    returnTm += to_string(stTm->tm_sec);

    return returnTm;
}

void Search::HideOrShow(int tag)
{
    if(tag==0){
    
        this->LabelCert->hide();
        this->LabelCertID->hide();
        this->LabelClientName->hide();
        this->LabelCertCreateTime->hide();
        this->LabelCertDieTime->hide();
        this->LabelCertState->hide();
        this->LineEditCertID->hide();
        this->LineEditClientName->hide();
        this->LineEditCertCreateTime->hide();
        this->LineEditCertDieTime->hide();
        this->LineEditCertState->hide();
        this->TextEditCert->hide();
        this->ButtonDelete->hide();
    
    }
    else
    {
        this->LabelCert->show();
        this->LabelCertID->show();
        this->LabelClientName->show();
        this->LabelCertCreateTime->show();
        this->LabelCertDieTime->show();
        this->LabelCertState->show();
        this->LineEditCertID->show();
        this->LineEditClientName->show();
        this->LineEditCertCreateTime->show();
        this->LineEditCertDieTime->show();
        this->LineEditCertState->show();
        this->TextEditCert->show();
    }
}

void Search::ClickDeleteButton() {


    time_t now;
    time(&now);
    ostringstream os;
    os << now;
    string strDelTime;
    istringstream is(os.str());
    is >> strDelTime;
    this->delCert.DeleteTime = strDelTime;

    DeleteClass Del = DeleteClass(this->delCert);
    InsertClass Ins = InsertClass(this->delCert,1);

}






