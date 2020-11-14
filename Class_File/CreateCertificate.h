#pragma once
#include <iostream>
#pragma once

using namespace std;

class CreateCertificate
{
public:
	CreateCertificate();
	string Create();

private:
	string Certificate;//通过调用API来生成证书

};

 