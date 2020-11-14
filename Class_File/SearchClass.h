#pragma once
#include "UserClass.h"
#include "CertificateTable.h"

class SearchClass
{
public:

	UserClass UserClassList[100];
	CertificateTable certificateTable[999];
	SearchClass();
	SearchClass(string key,string keyName, int tag);
	int toSearch();//需要执行查询函数-如果有时间将此函数重构
	string lab;
private:
	int SearchTag;//查询的方式类型
	string SearchKey;
	string SearchKeyName;
	//int SearchKeyCount;
};

