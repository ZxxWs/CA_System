/*
参考链接https://stackoverrun.com/cn/q/33397
*/

#include "CreateCertificate.h"


//默认构造函数
CreateCertificate::CreateCertificate(string savePath, string pubPath,string clientName) {
    this->SavePath = savePath;
    this->PublicPath = pubPath;
    this->CertID = CreateCertID();
    this->ClientName = clientName;

    //获取客户公钥
    ifstream infile;
    infile.open(PublicPath.data());  //将文件流对象与文件连接起来 

    if (infile.is_open()) {
        string s;
        while (getline(infile, s))
        {
            this->ClientKey = this->ClientKey + s + '\n';
        }
        infile.close();             //关闭文件输入流
    }

    //test=this->ClientKey;
}

/*
    此处不仅仅是生成证书，也包括入库。
    只有入库成功后才能显示到客户端，
    否则显示相应的错误代码
    0：成功
*/
int CreateCertificate::Create() {


    //-------------------------------获取公钥
    EVP_PKEY* pkey=0;
    FILE* f;
    f = fopen(PublicPath.c_str(), "r");
    PEM_read_PUBKEY(f, &pkey, 0, 0);
    //-------------------------------获取公钥


    this->Certx509 = X509_new();
    ASN1_INTEGER_set(X509_get_serialNumber(Certx509), CertID);//证书编号

    X509_gmtime_adj(X509_get_notBefore(Certx509), 0);//设置证书的notBefore属性设置为当前时间。 （X509_gmtime_adj函数将当前时间加上指定的秒数 - 在这种情况下无）。
    X509_gmtime_adj(X509_get_notAfter(Certx509), 31536000L);//将证书的notAfter属性设置为从现在开始的365天（60秒 * 60分钟 * 24小时 * 365天）

    //long i = time_t(0);

    //----------------------设置数据库插入数据时间-----------------------

    time_t now;
    time(&now);
    this->CertTable.CreateTime = now;
    this->CertTable.DieTime = now + 31536000L;

    //----------------------设置数据库插入数据时间-----------------------

    //现在我们需要用我们产生较早的关键，为我们的证书的公钥：
    X509_set_pubkey(Certx509, pkey);


    ////由于这是自签名证书，我们设置了发行人的名称的名称学科。在这个过程的第一步是获取主题名称：
    X509_NAME* name;
    name = X509_get_subject_name(Certx509);



    ////如果你曾经创建的命令行自签名证书之前，你可能还记得被问了一个国家代码。这里我们提供它随着组织（“O”）和通用名（“CN”）：
    X509_NAME_add_entry_by_txt(name, "C", MBSTRING_ASC,
        (unsigned char*)"CA", -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "O", MBSTRING_ASC,
        (unsigned char*)this->ClientName.c_str(), -1, -1, 0);
    X509_NAME_add_entry_by_txt(name, "CN", MBSTRING_ASC,
        (unsigned char*)"localhost", -1, -1, 0);


    ////现在，我们实际上可以设定发行人名称：
    X509_set_issuer_name(Certx509, name);


    ////最后，我们已准备好执行签名过程。我们称X509_sign与我们早先生成的密钥。该代码，这是痛苦地简单：
    //    //我们使用的是SHA - 1散列算法要签名的密钥
    X509_sign(Certx509, pkey, EVP_sha1());



    //将证书保存在文件中---------------------------------------------
    FILE* savef;
    savef = fopen((SavePath + "/Cert.pem").c_str(), "wb");
    PEM_write_X509(savef,Certx509);
    fclose(savef);
    //将证书保存在文件中---------------------------------------------


    //从文件中读取证书--------------------------------------------
    ifstream infile;
    infile.open((SavePath + "/Cert.pem").data());  //将文件流对象与文件连接起来 

    if (infile.is_open()) {
        string s;
        while (getline(infile, s))
        {
            this->CertString = this->CertString+s+'\n';
        }
        infile.close();             //关闭文件输入流
    }
    //从文件中读取证书--------------------------------------------

    return 0;
}



X509* CreateCertificate::getCertX509() {

    return this->Certx509;
}

string CreateCertificate::getCertString() {

    //将X509格式转为String
    return this->CertString;
}

CertificateTable CreateCertificate::getCertTable() {


    this->CertTable.CertID = to_string(this->CertID);
    this->CertTable.Certificate = this->CertString;
    this->CertTable.ClientKey = this->ClientKey;
    this->CertTable.ClientName = this->ClientName;

    return this->CertTable;
}


//通过查询数据库来生成一个CertID
long CreateCertificate::CreateCertID() {

    long CertID;
    string s1, s2;//查询表中的CertID

    default_random_engine eng(time(0));//随机数引擎
    uniform_int_distribution<long> dis(1, 2147483646);

    do {

        CertID = dis(eng);

        //long转string
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

