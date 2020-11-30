#pragma once
#include "SearchClass.h"

#include <random>
#include <strstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif


#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")
#include <iostream>
#include <openssl/x509v3.h>
#include <openssl/conf.h>
#include "openssl/rsa.h"
#include <openssl/bio.h>
#include <string>
#include "openssl/pem.h"


using namespace std;

class CreateCertificate
{
public:
	CreateCertificate(string savePath,string pubPath,string clientName);
	int Create();
	string getCertString();
	CertificateTable getCertTable();
	X509* getCertX509();
	
	string test;

private:

	long CreateCertID();
	long CertID;


	string CertString;//ͨ������API������֤��String
	X509* Certx509;//ͨ������API������֤��ԭ��
	CertificateTable CertTable;//ͨ������API������֤��CertificateTable����

	string SavePath;
	string PublicPath;
	string ClientKey;
	string ClientName;
};

 