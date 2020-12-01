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
    QLabel* LabelTips;
    QPushButton* ButtonLogIn;
    QPushButton* ButtonSignIn;
    QLineEdit* LineEditUserName;
    QLineEdit* LineEditUserPassWord;
    QComboBox* ComboBoxUserKind;


public slots:
    void ClickLogInButton();
    void ClickSignInButton();
    void ReShowWindow();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息


private:
    Ui::CA_SystemClass ui;
    int getInputDate();//获取输入的内容
    UserClass NowUser;//当前界面的User对象

};
