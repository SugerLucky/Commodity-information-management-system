#pragma once
#include "User.h"
/*
* ����Ա�û�
*/
class Administrator : public User {
private:

public:
	Administrator();

	Administrator(const string& user, const string& pwd);

	static string getFileName();
};

