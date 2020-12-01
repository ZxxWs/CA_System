#pragma once
#include "CertificateTable.h"
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#include<iostream>
#include<Windows.h>
#include<WinSock.h>
#include<mysql.h>

class DeleteClass
{
public:
	DeleteClass();
	DeleteClass(CertificateTable cert);


private:
	MYSQL* DelMysql = new MYSQL; //mysql连接  
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集  
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
	char DelQuery[5000]; //查询语句

	bool ConnectDatabase();

	int tag;//tag为1时生成成功
};


