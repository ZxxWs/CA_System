#pragma once
#include <QtWidgets/QMainWindow>
#include "../x64/Debug/uic/ui_Search.h"
#include "../Class_File/UserClass.h"
#include "qpushbutton.h"

class Search : public QMainWindow
{
    Q_OBJECT

public:
    Search(UserClass nowUser,QWidget* parent = Q_NULLPTR);
    QPushButton* ButtonApplyFor;
    QPushButton* ButtonClearnText;
    QPushButton* ButtonExit;
    QPushButton* ButtonToSearch;
    QLabel* LabelUserName;
    QComboBox* ComboBoxSearchKind;
    QTextEdit* TextEditSearchContent;
    QLabel* lab;//用于测试的lab

public slots:
    void ClickSearchButton();//按钮点击事件
    void ClickEixtButton();
    void ClickClearnTextButton();
    void ClickApplyForButton();

private:
    Ui::Serach ui;
    UserClass NowUser;
};
