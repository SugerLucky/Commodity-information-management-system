#pragma once
#include "Service.h"
#include "Commodity.h"

/*
* ��Ӧ����Ա�Ĳ���
*/
class ServiceAdmin : public Service {

public:

	void addGoods();

	void browseClientOrders();

	void searchClientOrders(const string& name);
};

