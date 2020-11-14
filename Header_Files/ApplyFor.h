#pragma once
#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_ApplyFor.h"
#include "../Class_File/UserClass.h"
#include "qpushbutton.h"
#include "../Class_File/CreateKeyPair.h"

class ApplyFor : public QMainWindow
{
    Q_OBJECT

public:
    ApplyFor(UserClass nowUser,QWidget* parent = Q_NULLPTR);
    QPushButton* ButtonCreateDoubleKey;
    QPushButton* ButtonCreateCertificate;
    QPushButton* ButtonSave;   //加不加再说
    QPushButton* ButtonBackSearch;
    QPushButton* ButtonSelectSavePublicKeyPath;
    QPushButton* ButtonSelectPublicKeyPath;
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
    //ApplyFor(UserClass nowUser, QWidget* parent);
    //按钮点击事件
    void ClickCreateCertificateButton();
    void ClickBackSearchButton();
    void ClickSelectSavePublicKeyPathButton();
    void ClickSelectPublicKeyPathButton();

private:
    Ui::ApplyFor ui;
    UserClass NowUser;
    QString OpenPublicKeyPath;
    string ClientPublicKey;
    CreateKeyPair CAKeyPair;
};
