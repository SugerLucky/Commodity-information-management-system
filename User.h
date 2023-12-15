#pragma once
#include <string>
#include <iostream>
using namespace std;
/*
* 用户的基类
*/
class User {
private:
    string username;
    string password;


public:
    User() = default;

    User(const string& username, const string& password)
        : username(username), password(password)
    {
    }

    virtual ~User() {}

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

    bool operator==(const User& other) const
    {
        return username == other.username && password == other.password;
    }

    string toString() const {
        return "username: " + username + ", password: " + password;
    }

    static string getFileName() { return "users.txt"; }
};

