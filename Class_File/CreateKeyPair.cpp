#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")
#include <iostream>
#include "openssl/rsa.h"
#include "openssl/pem.h"
#include "CreateKeyPair.h"
#include <string>
#include <fstream>
extern "C"
{
#include <openssl/applink.c>
}
using namespace std;
/*************************************************************************************
 *                         RSA密钥生成函数
 * 1.PEM_write_RSA_PUBKEY()    //生成----BEGIN RSA PRIVATE KEY----格式的公钥pem文件
 *   PEM_write_RSAPublicKey()  //生成----BEGIN PUBLIC KEY----格式的公钥pem文件
 *
 *  2.----BEGIN PUBLIC KEY----格式的公钥pem文件才可以用
 **************************************************************************************/

CreateKeyPair::CreateKeyPair() {
    this->isSucceed = false;
    this->PublicKey = "";
    this->PrivateKey = "";
}

CreateKeyPair::CreateKeyPair(string filePath, bool createFile=true){//tag==0时，生成文件


    RSA* rsa = RSA_generate_key(2048, 65537, NULL, NULL);

    FILE* Private_key_file;
    FILE* Public_key_file;
    fopen_s(&Private_key_file, (filePath + "/prikey.pem").c_str(), "w+");
    fopen_s(&Public_key_file, (filePath + "/pubkey.pem").c_str(), "w+");
    PEM_write_RSAPrivateKey(Private_key_file, rsa, NULL, NULL, 0, NULL, NULL);
    PEM_write_RSA_PUBKEY(Public_key_file, rsa);
    fclose(Private_key_file);
    fclose(Public_key_file);
    RSA_free(rsa);

    ifstream infile1;
    ifstream infile2;
    infile1.open((filePath + "/prikey.pem").data());   //将文件流对象与文件连接起来 
    infile2.open((filePath + "/pubkey.pem").data());   //将文件流对象与文件连接起来 


    string a="";
    while (getline(infile1, a))
    {
        this->PrivateKey += a;
    }  
    while (getline(infile2, a))
    {
        this->PublicKey += a;
    }
    infile1.close();             //关闭文件输入流
    infile2.close();
       

    if (!createFile) {
        remove((filePath + "/prikey.pem").c_str());
        remove((filePath + "/pubkey.pem").c_str());
    }

}


