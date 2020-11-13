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
    QPushButton* ButtonSave;   //�Ӳ�����˵
    QPushButton* ButtonBackSearch;
    QLabel* LabelUserName;
    QTextEdit* TextEditPublicKey;
    QTextEdit* TextEditPrivateKey;
    QTextEdit* TextEditCertificate;
    QLabel* LabelCertificate;

public slots:
    void ClickCreateDoubleKeyButton();//��ť����¼�
    void ClickCreateCertificateButton();
    void ClickBackSearchButton();

private:
    Ui::ApplyFor ui;
};
