#include "UserClass.h"

UserClass::UserClass(){}

UserClass::UserClass(string UserName, string UserPassWord, int UserTag) {
	this->UserName = UserName;
	this->UserPassWord = UserPassWord;
	this->UserTag = UserTag;
}

void UserClass::setUserName(string UserName) {

	this->UserName = UserName;
}

void UserClass::setUserPassWord(string UserPassWord) {

	this->UserPassWord = UserPassWord;
}

void UserClass::setUserTag(int UserTag){
	this->UserTag = UserTag;
}

string UserClass::getUserName(){
	return this->UserName;
}

string UserClass::getUserPassWord(){
	return this->UserPassWord;
}

int UserClass::getUserTag(){
	return this->UserTag;
}
