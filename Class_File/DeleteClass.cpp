#include "DeleteClass.h"

DeleteClass::DeleteClass()
{

}

void DeleteClass::Del(CertificateTable cert)
{
	if (ConnectDatabase()) {
		string str = "delete from certificatetable where certid='" + cert.CertID + "';";
		sprintf_s(DelQuery, &str[0]); //查询语句

		mysql_query(DelMysql, "set names utf8");
		if (mysql_query(DelMysql, DelQuery))    //执行SQL语句
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
	//初始化mysql  
	mysql_init(DelMysql);
	//返回false则连接失败，返回true则连接成功  
	if (!(mysql_real_connect(DelMysql, "localhost", "root", "123456", "ca_system", 0, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		return false;
	}
	else
	{
		return true;
	}
	return true;
}

