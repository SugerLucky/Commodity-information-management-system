#pragma once
#include <string>
#include <iostream>
using namespace std;
/*
* 用户的基类
*/
class User {
private:
    int id;
    string username;
    string password;


public:
    User() = default;

    User(int id, const string& username, const string& password)
        : id(id), username(username), password(password)
    {
    }

    int getId() const {
        return id;
    }

    void set(int id) {
        this->id = id;
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

