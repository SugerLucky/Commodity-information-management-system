#pragma once
#include "User.h"
/*
* ����Ա�û�
*/
class Administrator : public User {
private:

public:
	Administrator() = default;

	Administrator(const string& user, const string& pwd) : User(user, pwd) {}

	static string getFileName() { return "administrators.json"; }
};

