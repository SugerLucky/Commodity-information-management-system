#include "Client.h"

Client::Client() = default;

Client::Client(const string& user, const string& pwd) : User(user, pwd) {}

string Client::getFileName() { return "clients.json"; }