#include "CreateCertificate.h"
#include "SearchClass.h"
#include <random>
#include <strstream>
#include <sstream>
#include <string>
#include <io.h>
using namespace std;

long CreateCertID();

//默认构造函数
CreateCertificate::CreateCertificate() {
}

/*
    此处不仅仅是生成证书，也包括入库。
    只有入库成功后才能显示到客户端，
    否则显示相应的错误代码
    0：成功
*/
int CreateCertificate::Create() {


    EVP_PKEY* pkey;//自己加的，但不知道是干啥的

    pkey = EVP_PKEY_new();
    FILE* f;
    f = fopen("C:/Users/zxxw/Desktop/pubkey.pem", "r");


    //X509* x509;
    this->Certx509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(Certx509), CreateCertID());//证书编号
    X509_gmtime_adj(X509_get_notBefore(Certx509), 0);//设置证书的notBefore属性设置为当前时间。 （X509_gmtime_adj函数将当前时间加上指定的秒数 - 在这种情况下无）。
    X509_gmtime_adj(X509_get_notAfter(Certx509), 31536000L);//将证书的notAfter属性设置为从现在开始的365天（60秒 * 60分钟 * 24小时 * 365天）

    //现在我们需要用我们产生较早的关键，为我们的证书的公钥：
    X509_set_pubkey(Certx509, pkey);


    //由于这是自签名证书，我们设置了发行人的名称的名称学科。在这个过程的第一步是获取主题名称：

    //----------------------不知为何突然BUG-----------------------
    //X509_NAME* name;
    //name = X509_get_subject_name(Certx509);



    ////如果你曾经创建的命令行自签名证书之前，你可能还记得被问了一个国家代码。这里我们提供它随着组织（“O”）和通用名（“CN”）：
    //X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC,
    //    (unsigned char*)"CA", -1, -1, 0);
    //X509_NAME_add_entry_by_txt(name, "O", MBSTRING_ASC,
    //    (unsigned char*)"MyCompany Inc.", -1, -1, 0);
    //X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
    //    (unsigned char*)"localhost", -1, -1, 0);


    ////现在，我们实际上可以设定发行人名称：
    //X509_set_issuer_name(Certx509, name);


    //最后，我们已准备好执行签名过程。我们称X509_sign与我们早先生成的密钥。该代码，这是痛苦地简单：
        //我们使用的是SHA - 1散列算法要签名的密钥
    X509_sign(Certx509, pkey, EVP_sha1());


    //FILE* f;
    //f = fopen("key.pem", "wb");
    //PEM_write_PrivateKey(
    //    f,     /* write the key to the file we've opened */
    //    pkey,    /* our key from earlier */
    //    EVP_des_ede3_cbc(), /* default cipher for encrypting the key on disk */
    //    "replace_me",  /* passphrase required for decrypting the key on disk */
    //    10,     /* length of the passphrase string */
    //    NULL,    /* callback for requesting a password */
    //    NULL    /* data to pass to the callback */
    //);





    return 0;
}



X509* CreateCertificate::getCertX509() {
    return this->Certx509;
}

string CreateCertificate::getCertString() {


    //将X509格式转为String（未写）
    return this->CertString;
}

CertificateTable CreateCertificate::getCertTable() {

    //将X509格式转为CertificateTable（未写）
    return this->CertTable;
}


//通过查询数据库来生成一个CertID
long CreateCertID() {

    string s1, s2;//查询表中的CertID
    long CertID;
    do {

        default_random_engine e(time(0));//随机数引擎
        CertID = e();

        //long转string
        ostringstream os;
        os << CertID;
        string strCertID;
        istringstream is(os.str());
        is >> strCertID;

        SearchClass search1 = SearchClass(strCertID, "CertID", 1);
        SearchClass search2 = SearchClass(strCertID, "CertID", 2);
        search1.toSearch();
        search2.toSearch();
        s1 = search1.certificateTable[0].CertID;
        s2 = search2.certificateTable[0].CertID;


    } while (s1 != "" && s2 != "");

    return CertID;

}