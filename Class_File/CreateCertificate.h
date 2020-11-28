#pragma once
#include <iostream>
#include <stdio.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include "CertificateTable.h"

#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")

using namespace std;

class CreateCertificate
{
public:
	CreateCertificate(string savePath,string pubPath);
	int Create();
	string getCertString();
	CertificateTable getCertTable();
	X509* getCertX509();
	
	string test;

private:
	//���������δ��ȫ�ã��˴���������
	string CertString;//ͨ������API������֤��String
	X509* Certx509;//ͨ������API������֤��ԭ��
	CertificateTable CertTable;//ͨ������API������֤��CertificateTable����

	string SavePath;
	string PublicPath;

};

 