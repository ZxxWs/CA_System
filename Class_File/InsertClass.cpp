#include "InsertClass.h"
#include "../Class_File/SearchClass.h"
#include <string>
#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������



using namespace std;

InsertClass::InsertClass()
{
}


//���tag=0,������������Ҫ����ظ���
void InsertClass::Ins(UserClass insertUser,int tag) {

	this->tips = "false";

	if (ConnectDatabase()) {

		if (tag == 0) {

			SearchClass search = SearchClass(insertUser.UserName, "UserName", 1);
			search.toSearch();

			if (search.UserClassList[0].UserName != insertUser.UserName) {

				string str = "insert into usertable  (UserName,UserPassWord,UserTag,UserTEL,UserCompany,UserRemark) values ('" 
					+ insertUser.UserName + "','" 
					+ insertUser.UserPassWord + "','" 
					+ to_string(insertUser.UserTag) + "','" 
					+ insertUser.UserTEL + "','" 
					+ insertUser.UserCompany + "','" 
					+ insertUser.UserRemark + "')";

				this->tips = str;


				sprintf_s(AddQuery, &str[0]);
				if (mysql_query(AddMysql, AddQuery))        //ִ��SQL���  
				{
					this->tips = "ע��ʧ��,�����������ݡ�";
					return;
				}
				else
				{
					this->tips = "ע��ɹ�";
					return;
				}
			}
			else
			{
				this->tips = "�û����ظ�";
			}
		}
		else
		{
		}

	}
	else
	{
		this->tips = "���ݿ�����ʧ�ܣ�������������";
	}

}


//tag=0����֤���tag=1����ɾ����
void InsertClass::Ins(CertificateTable insertCertificate, int tag) {

	this->tips = "false";
	if (ConnectDatabase()) {
		if (tag == 0) {

			string str = "insert into certificatetable  (CertID,ClientKey,Certificate,ClientName,CreateTime,DieTime) values ('"
				+ insertCertificate.CertID + "','" 
				+ insertCertificate.ClientKey + "','" 
				+ insertCertificate.Certificate + "','"
				+ insertCertificate.ClientName + "',"
				+ to_string(insertCertificate.CreateTime) + ","
				+ to_string(insertCertificate.DieTime) +
				")";

			this->tips = str;

			sprintf_s(AddQuery, &str[0]);
			if (mysql_query(AddMysql, AddQuery))        //ִ��SQL���  
			{
				this->tips = "����ʧ�ܡ�";
				return;
			}
			else
			{
				this->tips = "���ɳɹ�";
				return;
			}
		}
		else//��ɾ�������
		{
			string str = "insert into diecertificatetable  (CertID,ClientKey,Certificate,ClientName,CreateTime,DieTime,DeleteTime) values ('"
				+ insertCertificate.CertID + "','"
				+ insertCertificate.ClientKey + "','"
				+ insertCertificate.Certificate + "','"
				+ insertCertificate.ClientName + "',"
				+ to_string(insertCertificate.CreateTime) + ","
				+ to_string(insertCertificate.DieTime) + ","
				+ to_string(insertCertificate.DeleteTime) +
				")";

			this->tips = str;

			sprintf_s(AddQuery, &str[0]);
			if (mysql_query(AddMysql, AddQuery))        //ִ��SQL���  
			{
				this->tips = "ʧ�ܡ�";
				return;
			}
			else
			{
				this->tips = "�ɹ�";
				return;
			}
		}
	}
	else
	{
		this->tips = "���ݿ�����ʧ�ܣ�������������";
	}
}


//�������ݿ⺯��
bool  InsertClass::ConnectDatabase() {
	//��ʼ��mysql  
	mysql_init(AddMysql);
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(AddMysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}


