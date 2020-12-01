/*
�ο�����https://stackoverrun.com/cn/q/33397
*/

#include "CreateCertificate.h"


//Ĭ�Ϲ��캯��
CreateCertificate::CreateCertificate(string savePath, string pubPath,string clientName) {
    this->SavePath = savePath;
    this->PublicPath = pubPath;
    this->CertID = CreateCertID();
    this->ClientName = clientName;

    //��ȡ�ͻ���Կ
    ifstream infile;
    infile.open(PublicPath.data());  //���ļ����������ļ��������� 

    if (infile.is_open()) {
        string s;
        while (getline(infile, s))
        {
            this->ClientKey = this->ClientKey + s + '\n';
        }
        infile.close();             //�ر��ļ�������
    }

    //test=this->ClientKey;
}

/*
    �˴�������������֤�飬Ҳ������⡣
    ֻ�����ɹ��������ʾ���ͻ��ˣ�
    ������ʾ��Ӧ�Ĵ������
    0���ɹ�
*/
int CreateCertificate::Create() {


    //-------------------------------��ȡ��Կ
    EVP_PKEY* pkey=0;
    FILE* f;
    f = fopen(PublicPath.c_str(), "r");
    PEM_read_PUBKEY(f, &pkey, 0, 0);
    //-------------------------------��ȡ��Կ


    this->Certx509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(Certx509), CertID);//֤����

    X509_gmtime_adj(X509_get_notBefore(Certx509), 0);//����֤���notBefore��������Ϊ��ǰʱ�䡣 ��X509_gmtime_adj��������ǰʱ�����ָ�������� - ������������ޣ���
    X509_gmtime_adj(X509_get_notAfter(Certx509), 31536000L);//��֤���notAfter��������Ϊ�����ڿ�ʼ��365�죨60�� * 60���� * 24Сʱ * 365�죩

    //long i = time_t(0);

    //----------------------�������ݿ��������ʱ��-----------------------

    time_t now;
    time(&now);
    this->CertTable.CreateTime = now;
    this->CertTable.DieTime = now + 31536000L;

    //----------------------�������ݿ��������ʱ��-----------------------

    //����������Ҫ�����ǲ�������Ĺؼ���Ϊ���ǵ�֤��Ĺ�Կ��
    X509_set_pubkey(Certx509, pkey);


    ////����������ǩ��֤�飬���������˷����˵����Ƶ�����ѧ�ơ���������̵ĵ�һ���ǻ�ȡ�������ƣ�
    X509_NAME* name;
    name = X509_get_subject_name(Certx509);



    ////�����������������������ǩ��֤��֮ǰ������ܻ��ǵñ�����һ�����Ҵ��롣���������ṩ��������֯����O������ͨ��������CN������
    X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC,
        (unsigned char*)"CA", -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "O", MBSTRING_ASC,
        (unsigned char*)this->ClientName.c_str(), -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
        (unsigned char*)"localhost", -1, -1, 0);


    ////���ڣ�����ʵ���Ͽ����趨���������ƣ�
    X509_set_issuer_name(Certx509, name);


    ////���������׼����ִ��ǩ�����̡����ǳ�X509_sign�������������ɵ���Կ���ô��룬����ʹ��ؼ򵥣�
    //    //����ʹ�õ���SHA - 1ɢ���㷨Ҫǩ������Կ
    X509_sign(Certx509, pkey, EVP_sha1());



    //��֤�鱣�����ļ���---------------------------------------------
    FILE* savef;
    savef = fopen((SavePath + "/Cert.pem").c_str(), "wb");
    PEM_write_X509(savef,Certx509);
    fclose(savef);
    //��֤�鱣�����ļ���---------------------------------------------


    //���ļ��ж�ȡ֤��--------------------------------------------
    ifstream infile;
    infile.open((SavePath + "/Cert.pem").data());  //���ļ����������ļ��������� 

    if (infile.is_open()) {
        string s;
        while (getline(infile, s))
        {
            this->CertString = this->CertString+s+'\n';
        }
        infile.close();             //�ر��ļ�������
    }
    //���ļ��ж�ȡ֤��--------------------------------------------

    return 0;
}



X509* CreateCertificate::getCertX509() {

    return this->Certx509;
}

string CreateCertificate::getCertString() {

    //��X509��ʽתΪString
    return this->CertString;
}

CertificateTable CreateCertificate::getCertTable() {


    this->CertTable.CertID = to_string(this->CertID);
    this->CertTable.Certificate = this->CertString;
    this->CertTable.ClientKey = this->ClientKey;
    this->CertTable.ClientName = this->ClientName;

    return this->CertTable;
}


//ͨ����ѯ���ݿ�������һ��CertID
long CreateCertificate::CreateCertID() {

    long CertID;
    string s1, s2;//��ѯ���е�CertID

    default_random_engine eng(time(0));//���������
    uniform_int_distribution<long> dis(1, 2147483646);

    do {

        CertID = dis(eng);

        //longתstring
        ostringstream os;
        os << CertID;

        string strCertID;
        istringstream is(os.str());
        is >> strCertID;

        SearchClass sea;
        sea.setData(strCertID, "CertID", 1);
        sea.toSearch();
        s1 = sea.certificateTable[0].CertID;
        sea.setData(strCertID, "CertID", 1);
        sea.toSearch();
        s2 = sea.dieCertificateTable[0].CertID;



    } while (s1 != "" || s2 != "");

    return CertID;
}

