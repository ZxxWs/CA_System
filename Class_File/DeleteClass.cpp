#include "DeleteClass.h"

DeleteClass::DeleteClass()
{

}

void DeleteClass::Del(CertificateTable cert)
{
	if (ConnectDatabase()) {
		string str = "delete from certificatetable where certid='" + cert.CertID + "';";
		sprintf_s(DelQuery, &str[0]); //��ѯ���

		mysql_query(DelMysql, "set names utf8");
		if (mysql_query(DelMysql, DelQuery))    //ִ��SQL���
		{
			//return false;
			tag = 0;
		}
		else
		{
			tag = 1;
		}
	}
}

bool DeleteClass::ConnectDatabase() {
	//��ʼ��mysql  
	mysql_init(DelMysql);
	//����false������ʧ�ܣ�����true�����ӳɹ�  
	if (!(mysql_real_connect(DelMysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}

