#pragma once
#include <string>
#include <iostream>
using namespace std;
#include <nlohmann/json.hpp>
/*
* 用户的基类
*/
class User {
private:
    string username;
    string password;

public:
    User();

    User(const string& username, const string& password);

    virtual ~User();

    string getUsername() const;

    void serialize(nlohmann::json& j) const;

    void deserialize(const nlohmann::json& j);

    void setUsername(string name);

    string getPassword() const;

    void setPassword(string psw);

    bool operator==(const User& other) const;

    string toString() const;

    static string getFileName();
};

