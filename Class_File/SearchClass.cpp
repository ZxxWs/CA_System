
#include "SearchClass.h"

#include <string>

using namespace std;

SearchClass::SearchClass(){}

SearchClass::SearchClass(string key, string keyName, int tag) {
	this->SearchKey = key;
	this->SearchKeyName = keyName;
	this->SearchTag = tag;
}

int SearchClass::setData(string key, string keyName, int tag)
{
	this->SearchKey = key;
	this->SearchKeyName = keyName;
	this->SearchTag = tag;
	return 0;
}

int SearchClass::toSearch() {	//返回0：失败,返回1：查询失败,返回5：查询成功

	if (ConnectDatabase()) {

		string Query = "select * from "+ SearchKind[this->SearchTag]+" where " + this->SearchKeyName + " = " + this->SearchKey;//构建查询语句
		sprintf_s(query, &Query[0]); //转存查询语句
		mysql_query(mysql, "set names utf8"); //设置编码格式

		//返回0 查询成功，返回1查询失败  
		if (mysql_query(mysql, query))    //执行SQL语句
		{
			return 1;
		}
		//获取结果集  
		if (!(res = mysql_store_result(mysql)))   //获得sql语句结束后返回的结果集  
		{
			return 1;
		}

		if (this->SearchTag == 0) {//查询Login表
			
			for (int i = 0; column = mysql_fetch_row(res); i++) {
				this->UserClassList[i].UserName=column[0];
				this->UserClassList[i].UserPassWord = column[1];
				this->UserClassList[i].UserTag = stoi(column[2]);
				this->UserClassList[i].UserTEL = column[3];
				this->UserClassList[i].UserRemark = column[4];
				this->UserClassList[i].UserCompany = column[5];
				this->UserClassList[i].UserRemark = column[6];
				this->UserClassList[i].IsCheck = stoi(column[7]);
			}
			return 5;
		}
		else if(this->SearchTag==1)//查询certificatetable表
		{
			for (int i = 0; column = mysql_fetch_row(res); i++) {
				this->certificateTable[i].CertID = column[0];
				this->certificateTable[i].ClientKey = column[1];
				this->certificateTable[i].Certificate = column[5];
				this->certificateTable[i].ClientName = column[6];
				//this->certificateTable[i].ClientKey = column[1];
				//this->certificateTable[i].ClientKey = column[1];

				string CertID;
				string ClientKey;
				string CAPublicKey;
				string CAPrivateKey;
				string Certificate;
				string ClientName;
				time_t CreateTime;
				time_t DieTime;
				time_t DeleteTime;
			}
			return 5;
		}
		else if(this->SearchTag==2)//查询Diecertificatetable表
		{
			for (int i = 0; column = mysql_fetch_row(res); i++) {

				this->dieCertificateTable[i].CertID = column[0];
				this->dieCertificateTable[i].ClientKey = column[1];
				this->dieCertificateTable[i].Certificate = column[5];
				this->dieCertificateTable[i].ClientName = column[6];

			}
			return 5;
		}

	}
	else//查询失败返回值
	{
		return 0;
	}

}


//连接数据库函数
bool SearchClass::ConnectDatabase() {
	//初始化mysql  
	mysql_init(mysql);
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(mysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}





