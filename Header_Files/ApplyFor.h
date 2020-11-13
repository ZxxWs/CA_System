#pragma once
#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_ApplyFor.h"
#include "qpushbutton.h"
#include <QComboBox>

class ApplyFor : public QMainWindow
{
    Q_OBJECT

public:
    ApplyFor(QWidget* parent = Q_NULLPTR);
    QPushButton* ButtonCreateDoubleKey;
    QPushButton* ButtonCreateCertificate;
    QPushButton* ButtonSave;   //加不加再说
    QPushButton* ButtonBackSearch;
    QLabel* LabelUserName;
    QTextEdit* TextEditPublicKey;
    QTextEdit* TextEditPrivateKey;
    QTextEdit* TextEditCertificate;
    QLabel* LabelCertificate;

public slots:
    void ClickCreateDoubleKeyButton();//按钮点击事件
    void ClickCreateCertificateButton();
    void ClickBackSearchButton();

private:
    Ui::ApplyFor ui;
};
