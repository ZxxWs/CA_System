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
	int toSearch();//��Ҫִ�в�ѯ����-�����ʱ�佫�˺����ع�

	string tips;

private:
	int SearchTag;//��ѯ�ķ�ʽ����
	string SearchKey;
	string SearchKeyName;
	//int SearchKeyCount;

	MYSQL* mysql = new MYSQL; //mysql����  
	MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����  
	MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
	char query[5000]; //��ѯ���
	string SearchTable[3] = { "Usertable", "certificatetable","dieCertificatetable" };


	bool ConnectDatabase();
};

