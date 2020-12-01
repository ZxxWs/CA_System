//#pragma once
//#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
//
//#include <QtWidgets/QMainWindow>
//#include "../x64/Debug/uic/ui_PassLimits.h"
//#include <QTableView>
//
//class PassLimits : public QMainWindow
//{
//    Q_OBJECT
//
//public:
//    PassLimits(QWidget* parent = Q_NULLPTR);
//
//
//    QTableView* TableView = new QTableView;
//
//
//public slots:
//
//    void ClickSureButton();//按钮点击事件
//    void ClickBackButton();
//
//private:
//    Ui::PassLimits ui;
//
//
//signals:
//    void sendsignal();//这个函数用户向主界面通知关闭的消息
//
//protected:
//    void closeEvent(QCloseEvent* event);//关闭界面的逻辑，主要是给上个界面来传递参数
//
//};
