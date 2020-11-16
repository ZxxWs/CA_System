#pragma once

#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_SignIn.h"
#include "qpushbutton.h"
#include <QComboBox>
#include <QtWidgets/qlabel.h>
#include "../Class_File/UserClass.h"

class SignIn : public QMainWindow
{
    Q_OBJECT

public:
    SignIn(QWidget* parent = Q_NULLPTR);

    QPushButton* PushButtonSure;
    QPushButton* PushButtonBack;
    QComboBox* ComboBoxType;
    QLabel* LabelType;
    QLabel* LabelPass;
    QLabel* LabelSurePass;
    QLabel* LabelCompany;
    QLabel* LabelTEL;
    QLabel* LabelMail;
    QLabel* LabelMessage;
    QLabel* LabelRemark;
    QLineEdit* LineEditPass;
    QLineEdit* LineEditSurePass;
    QLineEdit* LineEditCompany;
    QLineEdit* LineEditTEL;
    QLineEdit* LineEditMail;
    QLineEdit* LineEditRemark;


public slots:

    void ClickSureButton();//��ť����¼�
    void ClickBackButton();//��ť����¼�

private:
    Ui::SignIn ui;
    UserClass signInUser;
    bool getData();

signals:
    void sendsignal();//��������û���������֪ͨ�رյ���Ϣ

protected:
    void closeEvent(QCloseEvent* event);//�رս�����߼�����Ҫ�Ǹ��ϸ����������ݲ���

};
