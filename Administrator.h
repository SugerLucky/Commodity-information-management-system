#pragma once
#include "User.h"
/*
* 管理员用户
*/
class Administrator : public User {
private:

public:
	Administrator();

	Administrator(const string& user, const string& pwd);

	static string getFileName();
};

