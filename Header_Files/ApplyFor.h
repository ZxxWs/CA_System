#pragma once
#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_ApplyFor.h"
#include "qpushbutton.h"
#include "../Class_File/CreateKeyPair.h"
#include "../Class_File/CertificateTable.h"
#include "../Class_File/UserClass.h"
#include <stdio.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")
#include "openssl/rsa.h"
#include "openssl/pem.h"
class ApplyFor : public QMainWindow
{
    Q_OBJECT

public:

    ApplyFor(UserClass nowUser, QWidget* parent = Q_NULLPTR);
    QPushButton* ButtonCreateDoubleKey;
    QPushButton* ButtonCreateCertificate;
    QPushButton* ButtonBackSearch;
    QPushButton* ButtonSelectSaveKeyPairPath;
    QPushButton* ButtonSelectPublicKeyPath;
    QPushButton* ButtonSaveCertificate;
    QLabel* LabelUserName;
    QLabel* LabelCertificate;
    QLabel* LabelPrivate;
    QLabel* LabelPublic;
    QTextEdit* TextEditPublicKey;
    QTextEdit* TextEditPrivateKey;
    QTextEdit* TextEditCertificate;
    QLineEdit* LineEditSelectPath;

public slots:
    void ClickCreateDoubleKeyButton();
    void ClickCreateCertificateButton();
    void ClickBackSearchButton();
    void ClickSelectSaveKeyPairPathButton();
    void ClickSelectPublicKeyPathButton();
    void ClickSaveCertificateButton();

private:
    Ui::ApplyFor ui;
    UserClass NowUser;
    QString OpenPublicKeyPath;
    string ClientPublicKey;


    //两种格式的证书
    CertificateTable certificateTable;
    X509* x509;
    //CreateKeyPair CAKeyPair;//用于生成
    //Cre
};
