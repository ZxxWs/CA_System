#include "InsertClass.h"
#include "../Class_File/SearchClass.h"
#include <string>
#pragma execution_character_set("UTF-8")//����qt�ı��룬���û�У����������������



using namespace std;

//���tag=0,������������Ҫ����ظ���
InsertClass::InsertClass(UserClass insertUser,int tag) {

	this->tips = "false";

	if (ConnectDatabase()) {

		if (tag == 0) {
			SearchClass search = SearchClass(insertUser.UserName, "UserName", 1);
			if (search.UserClassList[0].UserName != insertUser.UserName) {



				string str = "insert into usertable  (UserName,UserPassWord,UserTag,UserTEL,UserCompany,UserRemark) values ('" + insertUser.UserName + "','" + insertUser.UserPassWord + "','" + to_string(insertUser.UserTag) + "','" + insertUser.UserTEL + "','" + insertUser.UserCompany + "','" + insertUser.UserRemark + "')";

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

InsertClass::InsertClass(CertificateTable insertCertificate, int tag) {
	this->tips = "false";
	if (ConnectDatabase()) {






	}
	else
	{
		this->tips = "���ݿ�����ʧ�ܣ�������������";
	}
}




//////����ѧ����Ϣ
////bool InsertStudent(string num, string name, string grade, string remark) {
////
////	string str = "insert into grade" + grade + " (Snum,Sname,Sgrade,Sremark) values ('" + num + "','" + name + "','" + grade + "','" + remark + "')";
////	sprintf_s(AddQuery, &str[0]);
////	if (mysql_query(AddMysql, AddQuery))        //ִ��SQL���  
////	{
////		return false;
////	}
////	else
////	{
////		return true;
////	}
////}

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


