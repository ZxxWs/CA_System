#pragma once
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

/*
用于填充数据库的一个类，类中的属性基本和数据库样式一一对应
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

	string CreateTime;
	string DieTime;
	string DeleteTime;


	time_t getCreateTime();
	time_t getDieTime();
	time_t getDeleteTime();


};

 