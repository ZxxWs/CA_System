#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class UserClass
{
public:
	UserClass();
	UserClass(string UserName,string UserPassWord,int UserTag);
	void setUserName(string UserName); 
	void setUserPassWord(string UserPassWord);
	void setUserTag(int UserTag);
	string getUserID();
	string getUserPassWord();
	int getUserTag();



	string UserID;
	string UserPassWord;
	int UserTag;
	string UserTEL;
	string UserMail;
	string UserCompany;
	string UserRemark;
	int IsCheck;


private:
	
};

