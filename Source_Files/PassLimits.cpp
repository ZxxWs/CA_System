//#pragma execution_character_set("UTF-8")//用于qt的编码，如果没有，界面会有中文乱码
//#include "../Header_Files/PassLimits.h"
//#include "../Class_File/InsertClass.h"
//#include "qpushbutton.h"
//#include "qstring.h"
//
//#include <QtWidgets/QMainWindow>
//
//#include <qstandarditemmodel.h>
//
//using namespace std;
//
//
//QStandardItemModel* dataModel = new QStandardItemModel();	//表格绑定数据模型
//
//PassLimits::PassLimits(QWidget* parent)
//    : QMainWindow(parent)
//{
//    ui.setupUi(this);
//    
//
//
//
//    this->TableView->setModel(dataModel);	//绑定数据模型
//    //this->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//设置表格宽度自动化
//    this->TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置表格为不可编辑状态
//
//
//    //connect(ui.PushButtonSure, SIGNAL(clicked()), this, SLOT(ClickSureButton()));
//
//
//
//
//
//
//}
//
// 
//
//void PassLimits::ClickBackButton() {
//
//    emit sendsignal();//给父界面传递被关闭信息
//    this->close();
//
//}
//
//
//void PassLimits::closeEvent(QCloseEvent* event) {
//    emit sendsignal(); // 给父界面传递被关闭信息
//}
//
//
//
//
//
