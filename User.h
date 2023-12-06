#pragma once
#include <string>
using namespace std;
/*
* �û��Ļ���
*/
class User {
private:
    string username;
    string password;
    string role;

public:
    User() = default;

    User(const string& username, const string& password, const string& role)
        : username(username), password(password), role(role)
    {
    }
};

