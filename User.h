#pragma once
#include <string>
using namespace std;
/*
* 用户的基类
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

    string getUsername() const {
        return username;
    }

    void setUsername(string name) {
        username = name;
    }

    string getPassword() const {
        return password;
    }

    void setPassword(string psw) {
        password = psw;
    }


};

