#include "SearchClass.h"
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#include<iostream>
#include<Windows.h>
#include<WinSock.h>
#include<mysql.h>
using namespace std;

MYSQL* mysql = new MYSQL; //mysql连接  
MYSQL_RES* res; //这个结构代表返回行的一个查询结果集  
MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
char query[5000]; //查询语句
string SearchKind[3] = { "Usertable", "certificatetable","Diecertificatetable"};

//下面函数的声明
bool ConnectDatabase();

SearchClass::SearchClass(){}


SearchClass::SearchClass(string key, string keyName, int tag) {
	this->SearchKey = key;
	this->SearchKeyName = keyName;
	this->SearchTag = tag;
}

int SearchClass::toSearch() {	//返回0：失败,返回1：查询失败,返回5：查询成功

	if (ConnectDatabase()) {


		string Query = "select * from "+ SearchKind[this->SearchTag]+" where " + this->SearchKeyName + " = " + this->SearchKey;//构建查询语句
		this->lab = Query;
		sprintf_s(query, &Query[0]); //转存查询语句
		mysql_query(mysql, "set names utf8"); //设置编码格式

		//返回0 查询成功，返回1查询失败  
		if (mysql_query(mysql, query))    //执行SQL语句
		{
			return 1;
		}
		//获取结果集  
		if (!(res = mysql_store_result(mysql)))   //获得sql语句结束后返回的结果集  
		{
			return 1;
		}

		if (this->SearchTag == 0) {//查询Login表
			
			for (int i = 0; column = mysql_fetch_row(res); i++) {
				this->UserClassList[i].setUserName(column[0]);
				this->UserClassList[i].setUserPassWord(column[1]);
				this->UserClassList[i].setUserTag(int(column[2]));
			}
			return 5;
		}
		else if(this->SearchTag==1)//查询certificatetable表
		{

		}
		else if(this->SearchTag==2)//查询Diecertificatetable表
		{

		}

	}
	else//查询失败返回值
	{
		return 0;
	}

}


//连接数据库函数
bool ConnectDatabase() {
	//初始化mysql  
	mysql_init(mysql);
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(mysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}





