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
    this->LabelCertState = ui.LabelCertState;
    this->LabelCert = ui.LabelCert;
    this->LabelCertID = ui.LabelCertID;
    this->LabelClientName = ui.LabelClientName;
    this->ComboBoxSearchKind = ui.ComboBoxSearchKind;
    this->TextEditSearchContent = ui.TextEditSearchContent;
    this->TextEditCert = ui.TextEditCert;
    this->LineEditCertID = ui.LineEditCertID;
    this->LineEditClientName = ui.LineEditClientName;
    this->LineEditCertState = ui.LineEditCertState;

    this->LabelCert->hide();
    this->LabelCertID->hide();
    this->LabelClientName->hide();
    this->LabelCertState->hide();
    this->LineEditCertID->hide();
    this->LineEditClientName->hide();
    this->LineEditCertState->hide();
    this->TextEditCert->hide();


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
}


//���ݲ��١�������
void Search::ClickSearchButton() {

    string SearchContent = this->TextEditSearchContent->toPlainText().toStdString();
    

    SearchClass Sear1 = SearchClass(SearchContent, SearchKind[this->ComboBoxSearchKind->currentIndex()], 1);
    //SearchClass Sear2 = SearchClass(SearchContent, "CertID", 1);
    Sear1.toSearch();


    this->LabelCert->show();
    this->LabelCertID->show();
    this->LabelClientName->show();
    this->LabelCertState->show();
    this->LineEditCertID->show();
    this->LineEditClientName->show();
    this->LineEditCertState->show();
    this->TextEditCert->show();


    this->LineEditCertID->setText(QString::fromStdString(Sear1.certificateTable[0].CertID));

    this->TextEditCert->setText(QString::fromStdString(Sear1.certificateTable[0].Certificate));

    this->LineEditClientName->setText(QString::fromStdString(Sear1.certificateTable[0].ClientName)); 

    
    //this->LineEditCertState->setText(QString::fromStdString(Sear1.certificateTable[0].CertID));


    //}





    this->lab->setText(this->TextEditSearchContent->toPlainText());

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



