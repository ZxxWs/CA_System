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

	long CreateTime;
	long DieTime;
	long DeleteTime;

	void setTime(string tm,int tag);

};

 