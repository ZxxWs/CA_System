#include "UserClass.h"

UserClass::UserClass(){}

UserClass::UserClass(string UserID, string UserPassWord, int UserTag) {
	this->UserID = UserID;
	this->UserPassWord = UserPassWord;
	this->UserTag = UserTag;
}

void UserClass::setUserName(string UserID) {

	this->UserID = UserID;
}

void UserClass::setUserPassWord(string UserPassWord) {

	this->UserPassWord = UserPassWord;
}

void UserClass::setUserTag(int UserTag){
	this->UserTag = UserTag;
}

string UserClass::getUserID(){
	return this->UserID;
}

string UserClass::getUserPassWord(){
	return this->UserPassWord;
}

int UserClass::getUserTag(){
	return this->UserTag;
}
