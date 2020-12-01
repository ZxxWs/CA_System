#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "../Header_Files/ApplyFor.h"
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Class_File/CreateKeyPair.h"
#include "../Class_File/CreateCertificate.h"
#include <QFileDialog>
#include <iostream>
#include <string>
#include <fstream>
#include "../Class_File/InsertClass.h"


using namespace std;

ApplyFor::ApplyFor(UserClass nowUser,QWidget* parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);

    this->ButtonCreateKeyPair = ui.ButtonCreateKeyPair;
    this->ButtonCreateCertificate = ui.ButtonCreateCertificate;
    this->ButtonSelectKeyPairPath = ui.ButtonSelectKeyPairPath;
    this->ButtonSelectCertificatePath = ui.ButtonSelectCertificatePath;
    this->ButtonBackSearch = ui.ButtonBackSearch;
    this->ButtonBackFunctionAlter = ui.ButtonBackFunctionAlter;

    this->LabelUserName = ui.LabelUserName;
    this->LabelCertificate = ui.LabelCertificate;
    this->LabelPublic = ui.LabelPublic;
    this->LabelPrivate = ui.LabelPrivate;

    this->TextEditCertificate = ui.TextEditCertificate;
    this->TextEditPublicKey = ui.TextEditPublicKey;
    this->TextEditPrivateKey = ui.TextEditPrivateKey;

    this->LineEditSelectKeyPairPath = ui.LineEditSelectKeyPairPath;
    this->LineEditSelectCertificatePath = ui.LineEditSelectCertificatePath;


    this->LineEditSelectCertificatePath->hide();
    this->ButtonCreateCertificate->hide();
    this->ButtonSelectCertificatePath->hide();
    this->TextEditCertificate->hide();

    this->LabelCertificate->hide();
    this->LabelPublic->hide();
    this->LabelPrivate->hide();
    this->TextEditPrivateKey->hide();
    this->TextEditPublicKey->hide();

    connect(ui.ButtonCreateKeyPair, SIGNAL(clicked()), this, SLOT(ClickCreateKeyPairButton()));
    connect(ui.ButtonCreateCertificate, SIGNAL(clicked()), this, SLOT(ClickCreateCertificateButton()));
    connect(ui.ButtonSelectKeyPairPath, SIGNAL(clicked()), this, SLOT(ClickSelectKeyPairPathButton()));
    connect(ui.ButtonSelectCertificatePath, SIGNAL(clicked()), this, SLOT(ClickSelectCertificatePathButton()));
    connect(ui.ButtonBackSearch, SIGNAL(clicked()), this, SLOT(ClickBackSearchButton()));
    connect(ui.ButtonBackFunctionAlter, SIGNAL(clicked()), this, SLOT(ClickFunctionAlter()));

    NowUser = nowUser;
    this->LabelUserName->setText(QString::fromStdString("�û��� " + this->NowUser.UserName));
    this->certificateTable.ClientName = NowUser.UserName;
    this->tagFunctionAlter = 0;
}

void ApplyFor::ClickCreateKeyPairButton() {

    string strPath;
    strPath = this->LineEditSelectKeyPairPath->displayText().toStdString()+"/";
    CreateKeyPair keyPair = CreateKeyPair(strPath);

    this->TextEditPublicKey->show();
    this->TextEditPrivateKey->show();
    this->LabelPublic->show();
    this->LabelPrivate->show();

    this->TextEditPrivateKey->setText(QString::fromStdString(keyPair.PrivateKey));
    this->TextEditPublicKey->setText(QString::fromStdString(keyPair.PublicKey));
    
}

void ApplyFor::ClickCreateCertificateButton() {

    string PublicPath = this->LineEditSelectKeyPairPath->displayText().toStdString();
    string savePath = this->LineEditSelectCertificatePath->displayText().toStdString();


    CreateCertificate Cert = CreateCertificate(savePath,PublicPath,this->NowUser.UserName);
    Cert.Create();

    InsertClass  ins;
    ins.Ins(Cert.getCertTable(), 0);



    this->TextEditCertificate->show();
    this->LabelCertificate->show();

    this->TextEditCertificate->setText(QString::fromStdString(Cert.getCertString()));
    //this->TextEditCertificate->setText(QString::fromStdString(Ins.tips));
}

void ApplyFor::ClickSelectKeyPairPathButton() {

    if (this->tagFunctionAlter == 0) {
        QString dirPath = QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼", "", QFileDialog::ShowDirsOnly);
        this->LineEditSelectKeyPairPath->setText(dirPath);
    }
    else
    {
        //�˷���Ϊ���ϲ���-----------------------------------------
        QString file_full, file_name, file_path;
        QFileInfo fi;
        file_full = QFileDialog::getOpenFileName(this);
        fi = QFileInfo(file_full);
        file_name = fi.fileName();
        file_path = fi.absolutePath();
        //--------------------------------------------------------
        this->LineEditSelectKeyPairPath->setText(file_path + '/' + file_name);

    }

   
}

void ApplyFor::ClickSelectCertificatePathButton()
{
    QString dirPath = QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼", "", QFileDialog::ShowDirsOnly);
    this->LineEditSelectCertificatePath->setText(dirPath);
}



void ApplyFor::ClickFunctionAlter() {
    if (this->tagFunctionAlter == 0) {//��ʱ��ť������л�������֤��Ĺ���
        this->tagFunctionAlter = 1;
        this->ButtonBackFunctionAlter->setText("������Կ�Թ���");

        this->ButtonCreateKeyPair->hide();
        this->LabelPublic->hide();
        this->LabelPrivate->hide();
        this->TextEditPublicKey->hide();
        this->TextEditPublicKey->setText("");
        this->TextEditPrivateKey->hide();
        this->TextEditPrivateKey->setText("");
        this->LineEditSelectKeyPairPath->setPlaceholderText("���빫Կ·��");
        this->LineEditSelectKeyPairPath->setText("");
        this->LineEditSelectCertificatePath->show();
        this->ButtonCreateCertificate->show();
        this->ButtonSelectCertificatePath->show();
    }
    else
    {
        this->tagFunctionAlter = 0;
        this->ButtonBackFunctionAlter->setText("����֤�鹦��");


        this->ButtonCreateKeyPair->show();
        this->LineEditSelectKeyPairPath->setPlaceholderText("������Կ�Ա���·��");
        this->LineEditSelectCertificatePath->hide();
        this->LineEditSelectCertificatePath->setText("");
        this->ButtonCreateCertificate->hide();
        this->ButtonSelectCertificatePath->hide();
        this->TextEditCertificate->hide();
        this->TextEditCertificate->setText("");
        this->LabelCertificate->hide();

    }
}

void ApplyFor::ClickBackSearchButton() {

    emit sendsignalApplyFor();//�������洫�ݱ��ر���Ϣ
    this->close();

}

void ApplyFor::closeEvent(QCloseEvent* event) {

    emit sendsignalApplyFor(); // �������洫�ݱ��ر���Ϣ

}





