#include "CreateCertificate.h"
#include "SearchClass.h"
#include <random>
#include <strstream>
#include <sstream>
#include <string>
#include <io.h>
using namespace std;

long CreateCertID();

//Ĭ�Ϲ��캯��
CreateCertificate::CreateCertificate() {
}

/*
    �˴�������������֤�飬Ҳ������⡣
    ֻ�����ɹ��������ʾ���ͻ��ˣ�
    ������ʾ��Ӧ�Ĵ������
    0���ɹ�
*/
int CreateCertificate::Create() {


    EVP_PKEY* pkey;//�Լ��ӵģ�����֪���Ǹ�ɶ��

    pkey = EVP_PKEY_new();
    FILE* f;
    f = fopen("C:/Users/zxxw/Desktop/pubkey.pem", "r");


    //X509* x509;
    this->Certx509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(Certx509), CreateCertID());//֤����
    X509_gmtime_adj(X509_get_notBefore(Certx509), 0);//����֤���notBefore��������Ϊ��ǰʱ�䡣 ��X509_gmtime_adj��������ǰʱ�����ָ�������� - ������������ޣ���
    X509_gmtime_adj(X509_get_notAfter(Certx509), 31536000L);//��֤���notAfter��������Ϊ�����ڿ�ʼ��365�죨60�� * 60���� * 24Сʱ * 365�죩

    //����������Ҫ�����ǲ�������Ĺؼ���Ϊ���ǵ�֤��Ĺ�Կ��
    X509_set_pubkey(Certx509, pkey);


    //����������ǩ��֤�飬���������˷����˵����Ƶ�����ѧ�ơ���������̵ĵ�һ���ǻ�ȡ�������ƣ�

    //----------------------��֪Ϊ��ͻȻBUG-----------------------
    //X509_NAME* name;
    //name = X509_get_subject_name(Certx509);



    ////�����������������������ǩ��֤��֮ǰ������ܻ��ǵñ�����һ�����Ҵ��롣���������ṩ��������֯����O������ͨ��������CN������
    //X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC,
    //    (unsigned char*)"CA", -1, -1, 0);
    //X509_NAME_add_entry_by_txt(name, "O", MBSTRING_ASC,
    //    (unsigned char*)"MyCompany Inc.", -1, -1, 0);
    //X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
    //    (unsigned char*)"localhost", -1, -1, 0);


    ////���ڣ�����ʵ���Ͽ����趨���������ƣ�
    //X509_set_issuer_name(Certx509, name);


    //���������׼����ִ��ǩ�����̡����ǳ�X509_sign�������������ɵ���Կ���ô��룬����ʹ��ؼ򵥣�
        //����ʹ�õ���SHA - 1ɢ���㷨Ҫǩ������Կ
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


    //��X509��ʽתΪString��δд��
    return this->CertString;
}

CertificateTable CreateCertificate::getCertTable() {

    //��X509��ʽתΪCertificateTable��δд��
    return this->CertTable;
}


//ͨ����ѯ���ݿ�������һ��CertID
long CreateCertID() {

    string s1, s2;//��ѯ���е�CertID
    long CertID;
    do {

        default_random_engine e(time(0));//���������
        CertID = e();

        //longתstring
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