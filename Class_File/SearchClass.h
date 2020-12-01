#pragma once
#include "UserClass.h"
#include "CertificateTable.h"
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#include<iostream>
#include<Windows.h>
#include<WinSock.h>
#include<mysql.h>

class SearchClass
{
public:
	UserClass UserClassList[100];
	CertificateTable certificateTable[999];
	CertificateTable dieCertificateTable[999];
	SearchClass();
	SearchClass(string key,string keyName, int tag);
	int setData(string key, string keyName, int tag);
	int toSearch();//需要执行查询函数-如果有时间将此函数重构

	string tips;

private:
	int SearchTag;//查询的方式类型
	string SearchKey;
	string SearchKeyName;
	//int SearchKeyCount;

	MYSQL* mysql = new MYSQL; //mysql连接  
	MYSQL_RES* res; //这个结构代表返回行的一个查询结果集  
	MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
	char query[5000]; //查询语句
	string SearchTable[3] = { "Usertable", "certificatetable","dieCertificatetable" };


	bool ConnectDatabase();
};

