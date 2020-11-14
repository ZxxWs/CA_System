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
    QLabel* lab;//���ڲ��Ե�lab

public slots:
    void ClickSearchButton();//��ť����¼�
    void ClickEixtButton();
    void ClickClearnTextButton();
    void ClickApplyForButton();

private:
    Ui::Serach ui;
    UserClass NowUser;
};
