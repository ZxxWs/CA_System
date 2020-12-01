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

	string tips;//���ڷ��ز�����ʾ


private:


	MYSQL* AddMysql = new MYSQL; //mysql����  
	MYSQL_RES* AddRes; //����ṹ�������е�һ����ѯ�����  
	MYSQL_ROW AddColumn; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е��� 
	char AddQuery[3000]; //��ѯ���

	bool ConnectDatabase();
};


