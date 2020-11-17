#include "InsertClass.h"
#include "../Class_File/SearchClass.h"
#include <string>
//
//MYSQL* mysql = new MYSQL; //mysql连接  
//MYSQL_RES* res; //这个结构代表返回行的一个查询结果集  
//MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
//char query[5000]; //查询语句



using namespace std;

//如果tag=0,则是新增，需要检查重复名
InsertClass::InsertClass(UserClass insertUser,int tag) {
	this->tips = "false";
	if (ConnectDatabase()) {



		if (tag == 0) {
			SearchClass search = SearchClass(insertUser.UserName, "UserName", 1);
			if (search.UserClassList[0].UserName != insertUser.UserName) {



				string str = "insert into usertabl  (UserName,UserPassWord,UserTag,UserTEL,UserCompany,UserRemark) values ('" + insertUser.UserName + "','" + insertUser.UserPassWord + "','" + to_string(insertUser.UserTag) + "','" + insertUser.UserTEL + "','" + insertUser.UserCompany + "','" + insertUser.UserRemark + "','" +insertUser.UserRemark  + "')";

////	sprintf_s(AddQuery, &str[0]);
////	if (mysql_query(AddMysql, AddQuery))        //执行SQL语句  
////	{
////		return false;
////	}
////	else
////	{
////		return true;
////	}








			}
			else
			{
				this->tips = "用户名重复";
			}

		}
		else
		{

		}

	}
	else
	{
		this->tips = "数据库连接失败，请检查网络设置";
	}
}

InsertClass::InsertClass(CertificateTable insertCertificate, int tag) {
	this->tips = "false";
	if (ConnectDatabase()) {






	}
	else
	{
		this->tips = "数据库连接失败，请检查网络设置";
	}
}




//////插入学生信息
////bool InsertStudent(string num, string name, string grade, string remark) {
////
////	string str = "insert into grade" + grade + " (Snum,Sname,Sgrade,Sremark) values ('" + num + "','" + name + "','" + grade + "','" + remark + "')";
////	sprintf_s(AddQuery, &str[0]);
////	if (mysql_query(AddMysql, AddQuery))        //执行SQL语句  
////	{
////		return false;
////	}
////	else
////	{
////		return true;
////	}
////}

//连接数据库函数
bool  InsertClass::ConnectDatabase() {
	//初始化mysql  
	mysql_init(AddMysql);
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(AddMysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}


