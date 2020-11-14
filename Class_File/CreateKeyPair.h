#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class CreateKeyPair
{
public:
	//CreateKeyPair();
	CreateKeyPair(string filePath,bool createFile);
	string PublicKey;
	string PrivateKey;
	bool isSucceed;
private:
	/*string UserName;
	string UserPassWord;
	int UserTag;*/
};

