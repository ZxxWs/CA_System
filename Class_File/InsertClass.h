#pragma once
#include <string.h>
#include <iostream>
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#include<Windows.h>
#include<WinSock.h>
#include<mysql.h>
#include "UserClass.h"
#include "CertificateTable.h"

using namespace std;

class InsertClass
{
public:
	InsertClass();
	void Ins(UserClass insertUser, int tag);
	void Ins(CertificateTable insertCertificate,int tag);

	string tips;//用于返回插入提示


private:


	MYSQL* AddMysql = new MYSQL; //mysql连接  
	MYSQL_RES* AddRes; //这个结构代表返回行的一个查询结果集  
	MYSQL_ROW AddColumn; //一个行数据的类型安全(type-safe)的表示，表示数据行的列 
	char AddQuery[3000]; //查询语句

	bool ConnectDatabase();
};


