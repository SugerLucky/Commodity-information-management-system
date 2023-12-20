#pragma once
#include "Service.h"
#include "Client.h"

/*
* ��Ӧ�ͻ��Ĳ���
*/
class ServiceClient : public Service {
private:
	Client client;
public:
	ServiceClient(const string& name, const string& pwd);

	void purchase(const string& username, int id, int num);

	void browseOrder();
};

