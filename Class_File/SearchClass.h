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
	int toSearch();//��Ҫִ�в�ѯ����-�����ʱ�佫�˺����ع�
	string lab;
private:
	int SearchTag;//��ѯ�ķ�ʽ����
	string SearchKey;
	string SearchKeyName;
	//int SearchKeyCount;
};

