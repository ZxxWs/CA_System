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
	CreateCertificate();
	int Create();
	string getCertString();
	CertificateTable getCertTable();
	X509* getCertX509();

private:
	//下面的类型未必全用，此处先声明上
	string CertString;//通过调用API来生成证书String
	X509* Certx509;//通过调用API来生成证书原生
	CertificateTable CertTable;//通过调用API来生成证书CertificateTable类型
};

 