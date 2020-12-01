#include "CertificateTable.h"

//默认构造函数
CertificateTable::CertificateTable() {

}

void CertificateTable::setTime(string tm, int tag)
{

	switch (tag)
	{
	case 1:
		this->CreateTime = atoi(tm.c_str());
		break;
	case 2:
		this->DieTime = atoi(tm.c_str());
		break;
	case 3:
		this->DeleteTime = atoi(tm.c_str());
		break;
	default:
		break;
	}
}


