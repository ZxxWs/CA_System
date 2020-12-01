#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
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
    this->LabelUserName->setText(QString::fromStdString("用户： " + this->NowUser.UserName));
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
        QString dirPath = QFileDialog::getExistingDirectory(this, "选择目录", "", QFileDialog::ShowDirsOnly);
        this->LineEditSelectKeyPairPath->setText(dirPath);
    }
    else
    {
        //此方法为网上查找-----------------------------------------
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
    QString dirPath = QFileDialog::getExistingDirectory(this, "选择目录", "", QFileDialog::ShowDirsOnly);
    this->LineEditSelectCertificatePath->setText(dirPath);
}



void ApplyFor::ClickFunctionAlter() {
    if (this->tagFunctionAlter == 0) {//此时按钮点击后切换到生成证书的功能
        this->tagFunctionAlter = 1;
        this->ButtonBackFunctionAlter->setText("生成密钥对功能");

        this->ButtonCreateKeyPair->hide();
        this->LabelPublic->hide();
        this->LabelPrivate->hide();
        this->TextEditPublicKey->hide();
        this->TextEditPublicKey->setText("");
        this->TextEditPrivateKey->hide();
        this->TextEditPrivateKey->setText("");
        this->LineEditSelectKeyPairPath->setPlaceholderText("输入公钥路径");
        this->LineEditSelectKeyPairPath->setText("");
        this->LineEditSelectCertificatePath->show();
        this->ButtonCreateCertificate->show();
        this->ButtonSelectCertificatePath->show();
    }
    else
    {
        this->tagFunctionAlter = 0;
        this->ButtonBackFunctionAlter->setText("生成证书功能");


        this->ButtonCreateKeyPair->show();
        this->LineEditSelectKeyPairPath->setPlaceholderText("输入密钥对保存路径");
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

    emit sendsignalApplyFor();//给父界面传递被关闭信息
    this->close();

}

void ApplyFor::closeEvent(QCloseEvent* event) {

    emit sendsignalApplyFor(); // 给父界面传递被关闭信息

}





