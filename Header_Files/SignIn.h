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

    void ClickSureButton();//按钮点击事件
    void ClickBackButton();//按钮点击事件

private:
    Ui::SignIn ui;
    UserClass signInUser;
    bool getData();

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

protected:
    void closeEvent(QCloseEvent* event);//关闭界面的逻辑，主要是给上个界面来传递参数

};
