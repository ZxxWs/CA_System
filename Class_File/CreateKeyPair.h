#pragma once
#include <string.h>
#include <iostream>
#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")
#include <iostream>
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include "CreateKeyPair.h"

using namespace std;

class CreateKeyPair
{
public:

	CreateKeyPair(string filePath,bool createFile);
	string PublicKey;//string类型的密钥对
	string PrivateKey;
	EVP_PKEY* PublicEVP;//原生类型的秘钥对
	EVP_PKEY* PrivatEVP;
	bool isSucceed;//未做验证
private:
	/*string UserName;
	string UserPassWord;
	int UserTag;*/
};

