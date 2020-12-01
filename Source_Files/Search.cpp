#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码

#include <QtWidgets/QMainWindow>
#include "../Class_File/UserClass.h"
#include "../Class_File/SearchClass.h"
#include "../Class_File/DeleteClass.h"
#include "../Header_Files/Search.h"
#include "../Header_Files/ApplyFor.h"
#include "qstring.h"
#include "qpushbutton.h"
#include "../Class_File/InsertClass.h"

using namespace std;


Search::Search(UserClass nowUser,QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->ButtonApplyFor = ui.ButtonApplyFor;
    this->ButtonClearnText = ui.ButtonClearnText;
    this->ButtonExit = ui.ButtonExit;
    this->ButtonToSearch = ui.ButtonToSearch;
    this->ButtonDelete = ui.ButtonDelete;
    this->LabelUserName = ui.LabelUserName;
    this->LabelCertState = ui.LabelCertState;
    this->LabelCertCreateTime = ui.LabelCertCreateTime;
    this->LabelCertDieTime = ui.LabelCertDieTime;
    this->LabelCert = ui.LabelCert;
    this->LabelCertID = ui.LabelCertID;
    this->LabelClientName = ui.LabelClientName;
    this->ComboBoxSearchKind = ui.ComboBoxSearchKind;
    this->TextEditSearchContent = ui.TextEditSearchContent;
    this->TextEditCert = ui.TextEditCert;
    this->LineEditCertID = ui.LineEditCertID;
    this->LineEditClientName = ui.LineEditClientName;
    this->LineEditCertCreateTime = ui.LineEditCertCreateTime;
    this->LineEditCertDieTime = ui.LineEditCertDieTime;
    this->LineEditCertState = ui.LineEditCertState;
    this->lab = ui.label;   //用于测试的label

    HideOrShow(0);

    if (nowUser.UserTag == 1) {//如果用户是游客，不显示申请按钮
        this->ButtonApplyFor->hide();
    }
    else if (nowUser.UserTag == 2) {
        this->ButtonApplyFor->setText("注册者审核");
    }

    
    this->NowUser = nowUser;
    this->LabelUserName->setText(QString::fromStdString("用户：" + NowUser.UserName));

    QStringList str;
    str << "通过证书号查询" << "通过证书字符串查询" ;
    ComboBoxSearchKind->insertItems(2, str);//填充下拉菜单

    if (nowUser.UserTag == 0) {//用户可以查找自己的所有证书（未写
        //ComboBoxSearchKind->addItem("查找自己的所有证书");
    }

    connect(ui.ButtonToSearch, SIGNAL(clicked()), this, SLOT(ClickSearchButton()));//将按钮和点击事件绑定
    connect(ui.ButtonExit, SIGNAL(clicked()), this, SLOT(ClickEixtButton()));
    connect(ui.ButtonApplyFor, SIGNAL(clicked()), this, SLOT(ClickApplyForButton()));
    connect(ui.ButtonClearnText, SIGNAL(clicked()), this, SLOT(ClickClearnTextButton()));
    connect(ui.ButtonDelete, SIGNAL(clicked()), this, SLOT(ClickDeleteButton()));

}

//内容不少。。。。
void Search::ClickSearchButton() {

    SearchClass sear;
    DeleteClass del;
    InsertClass ins;

    {//在查询前先检索过期证书
         
        time_t now;
        time(&now);
        for (int i = 0; i < sear.getFlash(now); i++) {

            sear.certificateTable[i].DeleteTime = sear.certificateTable[i].DieTime;

            del.Del(sear.certificateTable[i]);
            ins.Ins(sear.certificateTable[i], 1);
        }
    }


    HideOrShow(0);

    string SearchContent = this->TextEditSearchContent->toPlainText().toStdString();
    
    sear.setData(SearchContent, SearchKind[this->ComboBoxSearchKind->currentIndex()], 1);
    sear.toSearch();


    this->delCert = sear.certificateTable[0];

    if (delCert.CertID == "") {//第一个表为空
        sear.setData(SearchContent, SearchKind[this->ComboBoxSearchKind->currentIndex()], 2);
        sear.toSearch();
        this->delCert = sear.dieCertificateTable[0];
    }


    if(delCert.CertID!=""){
        HideOrShow(1);

        this->LineEditCertID->setText(QString::fromStdString(this->delCert.CertID));
        this->TextEditCert->setText(QString::fromStdString(this->delCert.Certificate));
        this->LineEditClientName->setText(QString::fromStdString(this->delCert.ClientName));

        this->LineEditCertCreateTime->setText(QString::fromStdString(shiftTime(this->delCert.CreateTime)));

        this->LineEditCertDieTime->setText(QString::fromStdString(shiftTime(this->delCert.DieTime)));

        string str = shiftTime(this->delCert.DeleteTime);
        if (this->delCert.DeleteTime != 1) {
            str += "被删除";
        }
        this->LineEditCertState->setText(QString::fromStdString(str));
    }
    else {
        this->lab->setText("并未有此证书");
    }


    if (this->delCert.DeleteTime == 1 &&(this->NowUser.UserName==this->delCert.ClientName||this->NowUser.UserTag==2)) {
        this->ButtonDelete->show();
    }

}


void Search::ClickApplyForButton() {

    this->hide();
    //UserClass u=this->NowUser;
    ApplyFor* applyForWin = new ApplyFor(this->NowUser,this);
    connect(applyForWin, SIGNAL(sendsignalApplyFor()), this, SLOT(ReShowWindow()));//当点击子界面EixtButton，调用主界面的ReShowWindow()函数
    applyForWin->show();

}

void Search::ClickClearnTextButton() {
    this->TextEditSearchContent->setText("");
}

void Search::ReShowWindow() {
    this->show();
}

void Search::ClickEixtButton() {

    emit sendsignal();//给父界面传递被关闭信息
    this->close();
}

void Search::closeEvent(QCloseEvent* event) {

    emit sendsignal(); // 给父界面传递被关闭信息
}

string Search::shiftTime(long tm)
{
    if (tm == 1) {
        return "证书未过期";
    }

    //参数为数据库里的string类型的时间
    string returnTm;
    time_t _tTm = time_t(tm);
    struct tm* stTm = localtime(&_tTm);

    returnTm = to_string(stTm->tm_year + 1900)+"年/";
    returnTm += to_string(stTm->tm_mon + 1) + "月/";
    returnTm += to_string(stTm->tm_mday)+"日  ";
    returnTm += to_string(stTm->tm_hour) + ":";
    returnTm += to_string(stTm->tm_min) + ":";
    returnTm += to_string(stTm->tm_sec);

    return returnTm;
}

void Search::HideOrShow(int tag)
{
    if(tag==0){
    
        this->LabelCert->hide();
        this->LabelCertID->hide();
        this->LabelClientName->hide();
        this->LabelCertCreateTime->hide();
        this->LabelCertDieTime->hide();
        this->LabelCertState->hide();
        this->LineEditCertID->hide();
        this->LineEditClientName->hide();
        this->LineEditCertCreateTime->hide();
        this->LineEditCertDieTime->hide();
        this->LineEditCertState->hide();
        this->TextEditCert->hide();
        this->ButtonDelete->hide();
    
    }
    else
    {
        this->LabelCert->show();
        this->LabelCertID->show();
        this->LabelClientName->show();
        this->LabelCertCreateTime->show();
        this->LabelCertDieTime->show();
        this->LabelCertState->show();
        this->LineEditCertID->show();
        this->LineEditClientName->show();
        this->LineEditCertCreateTime->show();
        this->LineEditCertDieTime->show();
        this->LineEditCertState->show();
        this->TextEditCert->show();
    }
}

void Search::ClickDeleteButton() {


    time_t now;
    time(&now);
    this->delCert.DeleteTime = now;

    DeleteClass del;
    del.Del(this->delCert);
    InsertClass ins;
    ins.Ins(this->delCert, 1);

}


