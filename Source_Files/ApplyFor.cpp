#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������
#include "../Header_Files/ApplyFor.h"
#include "qpushbutton.h"
#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Class_File/CreateKeyPair.h"
#include <QFileDialog>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ApplyFor::ApplyFor(UserClass nowUser,QWidget* parent)
    : QMainWindow(parent)
{

    ui.setupUi(this);

    this->ButtonCreateDoubleKey = ui.ButtonCreateDoubleKey;
    this->ButtonCreateCertificate = ui.ButtonCreateCertificate;
    this->ButtonBackSearch = ui.ButtonBackSearch;
    this->ButtonSelectSavePublicKeyPath = ui.ButtonSelectSavePublicKeyPath;
    this->ButtonSelectPublicKeyPath = ui.ButtonSelectPublicKeyPath;
    this->LabelUserName = ui.LabelUserName;
    this->LabelCertificate = ui.LabelCertificate;
    this->LabelPublic = ui.LabelPublic;
    this->LabelPrivate = ui.LabelPrivate;            
    this->TextEditCertificate = ui.TextEditCertificate;
    this->TextEditPublicKey = ui.TextEditPublicKey;
    this->TextEditPrivateKey = ui.TextEditPrivateKey;
    this->LineEditSelectPath = ui.LineEditSelectPath;
    this->ButtonSave = ui.ButtonSave;

    this->TextEditCertificate->hide();
    this->LabelCertificate->hide();
    this->LabelPrivate->hide();
    this->ButtonCreateCertificate->hide();
    this->ButtonSave->hide();
    this->LabelPrivate->hide();
    this->TextEditPrivateKey->hide();


    connect(ui.ButtonCreateDoubleKey, SIGNAL(clicked()), this, SLOT(ClickCreateDoubleKeyButton()));//����ť�͵���¼���
    connect(ui.ButtonCreateCertificate, SIGNAL(clicked()), this, SLOT(ClickCreateCertificateButton()));//����ť�͵���¼���
    connect(ui.ButtonBackSearch, SIGNAL(clicked()), this, SLOT(ClickBackSearchButton()));
    connect(ui.ButtonSelectSavePublicKeyPath, SIGNAL(clicked()), this, SLOT(ClickSelectSavePublicKeyPathButton()));
    connect(ui.ButtonSelectPublicKeyPath, SIGNAL(clicked()), this, SLOT(ClickSelectPublicKeyPathButton()));

    this->LabelUserName->setText(QString::fromStdString("�û��� " + this->NowUser.getUserName()));

}

void ApplyFor::ClickCreateDoubleKeyButton() {

    string strPath;
    strPath = this->LineEditSelectPath->displayText().toStdString()+"/";
    CreateKeyPair keyPair = CreateKeyPair(strPath,true);

    this->TextEditPrivateKey->show();
    this->ButtonCreateCertificate->show();
    this->LabelPrivate->show();
    this->ButtonSelectPublicKeyPath->hide();
    this->TextEditPrivateKey->setText(QString::fromStdString(keyPair.PrivateKey));
    this->TextEditPublicKey->setText(QString::fromStdString(keyPair.PublicKey));
    
}

void ApplyFor::ClickCreateCertificateButton() {


    this->TextEditCertificate->show();
}

void ApplyFor::ClickBackSearchButton() {


}

void ApplyFor::ClickSelectSavePublicKeyPathButton() {

    QString dirPath= QFileDialog::getExistingDirectory(this, "ѡ��Ŀ¼","", QFileDialog::ShowDirsOnly);
    this->LineEditSelectPath->setText(dirPath);
}

void ApplyFor::ClickSelectPublicKeyPathButton() {


    //�˷���Ϊ���ϲ���-----------------------------------------
    QString file_full, file_name, file_path;
    QFileInfo fi;
    file_full = QFileDialog::getOpenFileName(this);
    fi = QFileInfo(file_full);
    file_name = fi.fileName();
    file_path = fi.absolutePath();
    //fi.fil
    //this->TextEditPublicKey->setText(file_path+'/'+file_name);
    //--------------------------------------------------------
    this->OpenPublicKeyPath = file_path + '/' + file_name;
   

    ifstream infile;
    infile.open(OpenPublicKeyPath.toStdString().data());   //���ļ����������ļ��������� 

    if (infile.is_open()) {

        string s;
        while (getline(infile, s))
        {
            this->ClientPublicKey = this->ClientPublicKey+s;
          }

        infile.close();             //�ر��ļ�������

        this->TextEditPublicKey->setText(QString::fromStdString(this->ClientPublicKey));

        this->ButtonCreateCertificate->show();
    }
    else
    {
        this->TextEditPublicKey->setText("�ļ���ʧ��");
    }


}



