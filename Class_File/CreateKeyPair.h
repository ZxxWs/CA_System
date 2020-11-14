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
	string PublicKey;//string���͵���Կ��
	string PrivateKey;
	EVP_PKEY* PublicEVP;//ԭ�����͵���Կ��
	EVP_PKEY* PrivatEVP;
	bool isSucceed;//δ����֤
private:
	/*string UserName;
	string UserPassWord;
	int UserTag;*/
};

