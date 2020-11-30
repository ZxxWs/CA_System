#pragma once
//#include <iostream>
//#include <stdio.h>
//#include <openssl/x509.h>
//#include <openssl/x509v3.h>
//#include "openssl/rsa.h"
//#include "openssl/pem.h"
//#include "openssl/evp.h"
//#include "CertificateTable.h"
//#include <openssl/conf.h>
//
//#pragma comment(lib,"libssl.lib")
//#pragma comment(lib,"libcrypto.lib")
//extern "C"
//{
//#include <openssl/applink.c>
//}
//using namespace std;


//#include <openssl/x509.h>
//#include <openssl/x509v3.h>
//#include "openssl/rsa.h"
//#include "openssl/pem.h"
//#include "openssl/evp.h"
//#include <openssl/conf.h>
//#include <openssl/bio.h>

#include "SearchClass.h"

#include <random>
#include <strstream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>



#include <fstream>
#include <stdio.h>
#include <stdlib.h>
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
extern "C"
{
#include <openssl/applink.c>
}
//using namespace std;

//#ifndef OPENSSL_NO_ENGINE
//#include <openssl/engine.h>
//#endif

//extern "C"
//{
//#include <openssl/applink.c>
//}



//#pragma comment(lib,"libssl.lib")
//#pragma comment(lib,"libcrypto.lib")

//#include <openssl/x509v3.h>

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

	long CreateCertID();
	//下面的类型未必全用，此处先声明上
	string CertString;//通过调用API来生成证书String
	X509* Certx509;//通过调用API来生成证书原生
	CertificateTable CertTable;//通过调用API来生成证书CertificateTable类型

	string SavePath;
	string PublicPath;

};

 