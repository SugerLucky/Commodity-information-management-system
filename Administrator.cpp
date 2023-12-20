#include "Administrator.h"

Administrator::Administrator() = default;

Administrator::Administrator(const string& user, const string& pwd) : User(user, pwd) {}

string Administrator::getFileName() { return "administrators.json"; }