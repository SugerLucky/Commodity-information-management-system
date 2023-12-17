#pragma once
#include "User.h"
#include "Commodity.h"
#include "Order.h"
#include <vector>
/*
* ¿Í»§
*/
class Client : public User {
private:


public:

	Client() = default;

	Client(const string& user, const string& pwd) : User(user, pwd) {}

	static string getFileName() { return "clients.json"; }

};

