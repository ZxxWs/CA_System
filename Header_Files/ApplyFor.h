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
    QPushButton* ButtonCreateKeyPair;
    QPushButton* ButtonCreateCertificate;
    QPushButton* ButtonSelectCertificatePath;
    QPushButton* ButtonSelectKeyPairPath;
    QPushButton* ButtonBackSearch;
    QPushButton* ButtonBackFunctionAlter;

    QLabel* LabelUserName;
    QLabel* LabelCertificate;
    QLabel* LabelPrivate;
    QLabel* LabelPublic;

    QTextEdit* TextEditPublicKey;
    QTextEdit* TextEditPrivateKey;
    QTextEdit* TextEditCertificate;

    QLineEdit* LineEditSelectKeyPairPath;
    QLineEdit* LineEditSelectCertificatePath;


public slots:
    void ClickCreateKeyPairButton();
    void ClickCreateCertificateButton();
    void ClickSelectKeyPairPathButton();
    void ClickSelectCertificatePathButton();
    void ClickFunctionAlter();
    void ClickBackSearchButton();


signals:
    void sendsignalApplyFor();//��������û���������֪ͨ�رյ���Ϣ

private:
    Ui::ApplyFor ui;
    UserClass NowUser;
    QString OpenPublicKeyPath;//����֤��ʱ�򿪵��ļ�
    string ClientPublicKey;
    int tagFunctionAlter;//0��ʱ������������Կ�ԣ�1����֤��

    //���ָ�ʽ��֤��
    CertificateTable certificateTable;
    X509* x509;
    //CreateKeyPair CAKeyPair;//��������


protected:
    void closeEvent(QCloseEvent* event);//�رս�����߼�����Ҫ�Ǹ��ϸ����������ݲ���
};
