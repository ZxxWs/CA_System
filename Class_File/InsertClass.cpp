#include "InsertClass.h"
//
//MYSQL* mysql = new MYSQL; //mysql����  
//MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����  
//MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
//char query[5000]; //��ѯ���


MYSQL* AddMysql = new MYSQL; //mysql����  
MYSQL_RES* AddRes; //����ṹ�������е�һ����ѯ�����  
MYSQL_ROW AddColumn; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���  
char AddQuery[150]; //��ѯ���
int AddTag;//�����Tag��������Ӱ༶�������ѧ��(0:�༶��1��ѧ����
string StringTag;//���ڼ�¼��ӹ��̵�����
string AddGradeList[9999];//�༶�б�
int AddGradeListLen = 0;


bool ConnectDatabase();


InsertClass::InsertClass(UserClass insertUser) {
	this->tips = "false";
	if (ConnectDatabase()) {






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




//����ѧ����Ϣ
bool InsertStudent(string num, string name, string grade, string remark) {

	string str = "insert into grade" + grade + " (Snum,Sname,Sgrade,Sremark) values ('" + num + "','" + name + "','" + grade + "','" + remark + "')";
	sprintf_s(AddQuery, &str[0]);
	if (mysql_query(AddMysql, AddQuery))        //ִ��SQL���  
	{
		return false;
	}
	else
	{
		return true;
	}
}

//�������ݿ⺯��
bool ConnectDatabase() {
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


