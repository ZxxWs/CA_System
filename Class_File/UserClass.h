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
	string getUserName();
	string getUserPassWord();
	int getUserTag();

private:
	string UserName;
	string UserPassWord;
	int UserTag;
};

