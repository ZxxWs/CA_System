#pragma once
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

/*
����������ݿ��һ���࣬���е����Ի��������ݿ���ʽһһ��Ӧ
*/
class CertificateTable
{
public:
	CertificateTable();
	string CertID;
	string ClientKey;
	string CAPublicKey;
	string CAPrivateKey;
	string Certificate;
	string ClientName;
	time_t CreateTime;
	time_t DieTime;
	time_t DeleteTime;

	void setCreateTime();
	void setDieTime();
	void setDeleteTime();
	time_t getCreateTime();
	time_t getDieTime();
	time_t getDeleteTime();
};

 