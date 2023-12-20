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

	Client();

	Client(const string& user, const string& pwd);

	static string getFileName();

};

