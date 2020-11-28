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


    this->LabelUserName->setText(QString::fromStdString("用户： " + this->NowUser.UserName));
    this->certificateTable.ClientName = nowUser.UserName;
    this->tagFunctionAlter = 0;
}

void ApplyFor::ClickCreateKeyPairButton() {

    string strPath;
    strPath = this->LineEditSelectKeyPairPath->displayText().toStdString()+"/";
    CreateKeyPair keyPair = CreateKeyPair(strPath,true);

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


    CreateCertificate Cert = CreateCertificate(savePath,PublicPath);
    Cert.Create();

    //this->x509 = Cert.getCertX509();
    //this->certificateTable = Cert.getCertTable();

    this->TextEditCertificate->show();
    this->LabelCertificate->show();
    
    this->TextEditCertificate->setText(QString::fromStdString(Cert.test));

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

//void ApplyFor::ClickSelectPublicKeyPathButton() {
//
//
//    //此方法为网上查找-----------------------------------------
//    QString file_full, file_name, file_path;
//    QFileInfo fi;
//    file_full = QFileDialog::getOpenFileName(this);
//    fi = QFileInfo(file_full);
//    file_name = fi.fileName();
//    file_path = fi.absolutePath();
//    //fi.fil
//    //this->TextEditPublicKey->setText(file_path+'/'+file_name);
//    //--------------------------------------------------------
//    this->OpenPublicKeyPath = file_path + '/' + file_name;
//   
//
//    ifstream infile;
//    infile.open(OpenPublicKeyPath.toStdString().data());   //将文件流对象与文件连接起来 
//
//    if (infile.is_open()) {
//
//        string s;
//        while (getline(infile, s))
//        {
//            this->ClientPublicKey = this->ClientPublicKey+s;
//          }
//
//        infile.close();             //关闭文件输入流
//
//        this->TextEditPublicKey->setText(QString::fromStdString(this->ClientPublicKey));
//
//        //this->ButtonCreateCertificate->show();
//    }
//    else
//    {
//        this->TextEditPublicKey->setText("文件打开失败");
//    }
//
//
//}


////证书保存按钮（未做验证）
//void ApplyFor::ClickSaveCertificateButton() {
//
//    QString dirPath = QFileDialog::getExistingDirectory(this, "选择目录", "", QFileDialog::ShowDirsOnly);
//    
//    FILE* file;
//    file = fopen((dirPath.toStdString()+"./cert.pem").c_str(), "wb");
//    PEM_write_X509(file,this->x509);
//    fclose(file);
//
//
//}


void ApplyFor::ClickFunctionAlter() {
    if (this->tagFunctionAlter == 0) {//此时按钮点击后切换到生成证书的功能
        this->tagFunctionAlter = 1;
        this->ButtonBackFunctionAlter->setText("生成密钥对功能");

        this->ButtonCreateKeyPair->hide();
        this->LabelPublic->hide();
        this->LabelPrivate->hide();
        this->TextEditPublicKey->hide();
        this->TextEditPrivateKey->hide();
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
       /* this->LabelPublic->show();
        this->LabelPrivate->show();
        this->TextEditPublicKey->show();
        this->TextEditPrivateKey->show();*/
        this->LineEditSelectKeyPairPath->setPlaceholderText("输入密钥对保存路径");
        this->LineEditSelectCertificatePath->hide();
        this->ButtonCreateCertificate->hide();
    }
}



void ApplyFor::ClickBackSearchButton() {

    emit sendsignalApplyFor();//给父界面传递被关闭信息
    this->close();

}

void ApplyFor::closeEvent(QCloseEvent* event) {

    emit sendsignalApplyFor(); // 给父界面传递被关闭信息

}










