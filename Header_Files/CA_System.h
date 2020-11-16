#pragma once

#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_CA_System.h"
#include "qpushbutton.h"

class CA_System : public QMainWindow
{
    Q_OBJECT

public:
    CA_System(QWidget *parent = Q_NULLPTR);
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
    void sendsignal();//��������û���������֪ͨ�رյ���Ϣ


private:
    Ui::CA_SystemClass ui;
};
