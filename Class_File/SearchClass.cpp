#include "SearchClass.h"
#pragma comment(lib,"libmysql.lib")
#pragma comment(lib,"wsock32.lib")
#include<iostream>
#include<Windows.h>
#include<WinSock.h>
#include<mysql.h>
using namespace std;

MYSQL* mysql = new MYSQL; //mysql����  
MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����  
MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
char query[5000]; //��ѯ���
string SearchKind[3] = { "Usertable", "certificatetable","Diecertificatetable"};

//���溯��������
bool ConnectDatabase();

SearchClass::SearchClass(){}


SearchClass::SearchClass(string key, string keyName, int tag) {
	this->SearchKey = key;
	this->SearchKeyName = keyName;
	this->SearchTag = tag;
}

int SearchClass::toSearch() {	//����0��ʧ��,����1����ѯʧ��,����5����ѯ�ɹ�

	if (ConnectDatabase()) {


		string Query = "select * from "+ SearchKind[this->SearchTag]+" where " + this->SearchKeyName + " = " + this->SearchKey;//������ѯ���
		this->lab = Query;
		sprintf_s(query, &Query[0]); //ת���ѯ���
		mysql_query(mysql, "set names utf8"); //���ñ����ʽ

		//����0 ��ѯ�ɹ�������1��ѯʧ��  
		if (mysql_query(mysql, query))    //ִ��SQL���
		{
			return 1;
		}
		//��ȡ�����  
		if (!(res = mysql_store_result(mysql)))   //���sql�������󷵻صĽ����  
		{
			return 1;
		}

		if (this->SearchTag == 0) {//��ѯLogin��
			
			for (int i = 0; column = mysql_fetch_row(res); i++) {
				this->UserClassList[i].setUserName(column[0]);
				this->UserClassList[i].setUserPassWord(column[1]);
				this->UserClassList[i].setUserTag(int(column[2]));
			}
			return 5;
		}
		else if(this->SearchTag==1)//��ѯcertificatetable��
		{

		}
		else if(this->SearchTag==2)//��ѯDiecertificatetable��
		{

		}

	}
	else//��ѯʧ�ܷ���ֵ
	{
		return 0;
	}

}


//�������ݿ⺯��
bool ConnectDatabase() {
	//��ʼ��mysql  
	mysql_init(mysql);
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(mysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}





