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
    void ReShowWindow();

private:
    Ui::Serach ui;
    UserClass NowUser;


signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

protected:
    void closeEvent(QCloseEvent* event);//关闭界面的逻辑，主要是给上个界面来传递参数
    int SearchKind;//查找方式


};
