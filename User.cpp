#include "User.h"

User::User() = default;

User::User(const string& username, const string& password)
    : username(username), password(password)
{
}

User::~User() {}

string User::getUsername() const {
    return username;
}

void User::serialize(nlohmann::json& j) const {
    j = {
        {"Username", username},
        {"Password", password}
    };
}

void User::deserialize(const nlohmann::json& j) {
    username = j["Username"];
    password = j["Password"];
}

void User::setUsername(string name) {
    username = name;
}

string User::getPassword() const {
    return password;
}

void User::setPassword(string psw) {
    password = psw;
}

bool User::operator==(const User& other) const
{
    return username == other.username && password == other.password;
}

string User::toString() const {
    return "username: " + username + ", password: " + password;
}

string User::getFileName() { return "users.json"; }
