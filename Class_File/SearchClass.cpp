
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

int SearchClass::toSearch() {	//����0��ʧ��,����1����ѯʧ��,����5����ѯ�ɹ�

	if (ConnectDatabase()) {

		string Query = "select * from "+ SearchTable[this->SearchTag]+" where " + this->SearchKeyName + " = '" + this->SearchKey+"'";//������ѯ���

		this->tips = Query;//��������

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
			
			for (int i = 0; column = mysql_fetch_row(res); i++){ 
				//�ж��Ƿ�Ϊ�գ�������жϻ������ֱ�ӿ���
			
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
		else if(this->SearchTag==1)//��ѯcertificatetable��
		{
			for (int i = 0; column = mysql_fetch_row(res); i++) {
				this->certificateTable[i].CertID = column[0];
				this->certificateTable[i].ClientKey = column[1];
				this->certificateTable[i].Certificate = column[2];
				this->certificateTable[i].ClientName = column[3];
				this->certificateTable[i].setTime(column[4],1);
				this->certificateTable[i].setTime(column[5],2);
				this->certificateTable[i].setTime(column[6], 3);


			}
			return 5;
		}
		else if(this->SearchTag==2)//��ѯDiecertificatetable��
		{
			for (int i = 0; column = mysql_fetch_row(res); i++) {

				this->dieCertificateTable[i].CertID = column[0];
				this->dieCertificateTable[i].ClientKey = column[1];
				this->dieCertificateTable[i].Certificate = column[2];
				this->dieCertificateTable[i].ClientName = column[3];
				this->dieCertificateTable[i].setTime(column[4], 1);
				this->dieCertificateTable[i].setTime(column[5], 2);
				this->dieCertificateTable[i].setTime(column[6], 3);

			}
			return 5;
		}

	}
	else//��ѯʧ�ܷ���ֵ
	{
		return 0;
	}

}

int SearchClass::getFlash(long nowTime)
{
	int count=0;
	if (ConnectDatabase()) {

		string Query = "select * from certificatetable where  DieTime<="+to_string(nowTime);//������ѯ���

		this->tips = Query;//��������

		sprintf_s(query, &Query[0]); //ת���ѯ���
		mysql_query(mysql, "set names utf8"); //���ñ����ʽ

		//����0 ��ѯ�ɹ�������1��ѯʧ��  
		if (mysql_query(mysql, query))    //ִ��SQL���
		{
			return 0;//����ֵ���õ�������
		}
		//��ȡ�����  
		if (!(res = mysql_store_result(mysql)))   //���sql�������󷵻صĽ����  
		{
			return 0;//����ֵ���õ�������
		}
		for (; column = mysql_fetch_row(res); count++) {
			this->certificateTable[count].CertID = column[0];
			this->certificateTable[count].ClientKey = column[1];
			this->certificateTable[count].Certificate = column[2];
			this->certificateTable[count].ClientName = column[3];
			this->certificateTable[count].setTime(column[4], 1);
			this->certificateTable[count].setTime(column[5], 2);
		}
	}
	else//��ѯʧ�ܷ���ֵ
	{
		return 0;
	}
	return count;
}

//�������ݿ⺯��
bool SearchClass::ConnectDatabase() {
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





