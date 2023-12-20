#pragma once
#include "Service.h"
#include "Commodity.h"

/*
* 响应管理员的操作
*/
class ServiceAdmin : public Service {

public:

	void addGoods();

	void browseClientOrders();

	void searchClientOrders(const string& name);
};

