#pragma once
#include "User.h"
/*
* 管理员用户
*/
class Administrator : public User {
private:

public:
	Administrator() = default;

	Administrator(const string& user, const string& pwd) : User(user, pwd) {}

	static string getFileName() { return "administrators.json"; }
};

