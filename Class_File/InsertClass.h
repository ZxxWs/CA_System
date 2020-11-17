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

	string tips;//���ڷ��ز�����ʾ


private:


	MYSQL* AddMysql = new MYSQL; //mysql����  
	MYSQL_RES* AddRes; //����ṹ�������е�һ����ѯ�����  
	MYSQL_ROW AddColumn; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
	char AddQuery[150]; //��ѯ���
	int AddTag;//�����Tag��������Ӱ༶�������ѧ��(0:�༶��1��ѧ����
	string StringTag;//���ڼ�¼��ӹ��̵�����
	string AddGradeList[9999];//�༶�б�
	int AddGradeListLen = 0;

	bool ConnectDatabase();
};


