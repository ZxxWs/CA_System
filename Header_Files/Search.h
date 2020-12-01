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

    QLabel* lab;//���ڲ��Ե�lab

public slots:
    void ClickSearchButton();//��ť����¼�
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
    string shiftTime(string tm);


signals:
    void sendsignal();//��������û���������֪ͨ�رյ���Ϣ

protected:
    void closeEvent(QCloseEvent* event);//�رս�����߼�����Ҫ�Ǹ��ϸ����������ݲ���
    //int SearchKind;//���ҷ�ʽ
    string SearchKind[3] = { "CertID","","" };//���ҷ�ʽ
};
