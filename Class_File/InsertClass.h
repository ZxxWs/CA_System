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
	InsertClass(UserClass insertUser, int tag);
	InsertClass(CertificateTable insertCertificate,int tag);
	//InsertClass(UserClass insertUser);

	string tips;//用于返回插入提示


private:


	MYSQL* AddMysql = new MYSQL; //mysql连接  
	MYSQL_RES* AddRes; //这个结构代表返回行的一个查询结果集  
	MYSQL_ROW AddColumn; //一个行数据的类型安全(type-safe)的表示，表示数据行的列  
	char AddQuery[150]; //查询语句
	int AddTag;//用这个Tag区分是添加班级还是添加学生(0:班级，1：学生）
	string StringTag;//用于记录添加过程的问题
	string AddGradeList[9999];//班级列表
	int AddGradeListLen = 0;

	bool ConnectDatabase();
};


