#pragma once

#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_CA_System.h"
#include "qpushbutton.h"
#include "../Class_File/UserClass.h"
#include <strstream>
#include <sstream>
#include <string>
#include <random>
using namespace std;

class CA_System : public QMainWindow
{
    Q_OBJECT

public:
    CA_System(QWidget *parent = Q_NULLPTR);
    QLabel* LabelTips;//������ʾ
    QPushButton* ButtonLogIn;
    QPushButton* ButtonSignIn;
    QLineEdit* LineEditUserName;
    QLineEdit* LineEditUserPassWord;
    QComboBox* ComboBoxUserKind;//��ѡ��


public slots:
    void ClickLogInButton();
    void ClickSignInButton();
    void ReShowWindow();

signals:
    void sendsignal();//δ�õ�


private:
    Ui::CA_SystemClass ui;
    int getInputDate();//��ȡ���������
    UserClass NowUser;//��ǰ�����User����

};
