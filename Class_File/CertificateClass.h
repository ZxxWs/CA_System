#pragma once
#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;

class CertificateClass
{
public:
	string CertID;
	string ClientKey;
	string CAPublicKey;
	string PriKey;
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

 