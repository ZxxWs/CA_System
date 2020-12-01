 #pragma once
#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_Search.h"
#include "../Class_File/UserClass.h"
#include "../Class_File/CertificateTable.h"
#include "qpushbutton.h"

#include <random>
#include <strstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class Search : public QMainWindow
{
    Q_OBJECT

public:
    Search(UserClass nowUser,QWidget* parent = Q_NULLPTR);

    QPushButton* ButtonApplyFor;
    QPushButton* ButtonClearnText;
    QPushButton* ButtonExit;
    QPushButton* ButtonToSearch;
    QPushButton* ButtonDelete;
    QLabel* LabelUserName;
    QLabel* LabelCertID;
    QLabel* LabelCert;
    QLabel* LabelCertCreateTime;
    QLabel* LabelCertDieTime;
    QLabel* LabelCertState;
    QLabel* LabelClientName;
    QLineEdit* LineEditCertID;
    QLineEdit* LineEditClientName;
    QLineEdit* LineEditCertCreateTime;
    QLineEdit* LineEditCertDieTime ;
    QLineEdit* LineEditCertState;
    QComboBox* ComboBoxSearchKind;
    QTextEdit* TextEditSearchContent;
    QTextEdit* TextEditCert;

    QLabel* lab;//用于测试的lab

public slots:
    void ClickSearchButton();//按钮点击事件
    void ClickEixtButton();
    void ClickClearnTextButton();
    void ClickApplyForButton();
    void ClickDeleteButton();
    void ReShowWindow();

private:
    Ui::Serach ui;
    UserClass NowUser;

    CertificateTable delCert;
    void HideOrShow(int tag);
    string shiftTime(long tm);
    string SearchKind[3] = { "CertID","Certificate","ClientName" };//查找方式

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

protected:
    void closeEvent(QCloseEvent* event);//关闭界面的逻辑，主要是给上个界面来传递参数
    
};
