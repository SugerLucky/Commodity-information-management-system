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
    User() = default;

    User(const string& username, const string& password)
        : username(username), password(password)
    {
    }

    virtual ~User() {}

    string getUsername() const {
        return username;
    }

    void serialize(nlohmann::json& j) const
    {
        j = {
            {"Username", username},
            {"Password", password}
        };
    }

    void deserialize(const nlohmann::json& j)
    {
        username = j["Username"];
        password = j["Password"];
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

    static string getFileName() { return "users.json"; }
};

