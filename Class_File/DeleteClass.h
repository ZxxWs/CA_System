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
	MYSQL* DelMysql = new MYSQL; //mysql����  
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����  
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
	char DelQuery[5000]; //��ѯ���

	bool ConnectDatabase();

	int tag;//tagΪ1ʱ���ɳɹ�
};


