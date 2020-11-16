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
	InsertClass(UserClass insertUser);
	InsertClass(CertificateTable insertCertificate,int tag);
	//InsertClass(UserClass insertUser);

	string tips;//用于返回插入提示


private:

};


