#pragma once
#include "Service.h"
#include "Client.h"
/*
* ��Ӧ�ͻ��Ĳ���
*/
class ServiceClient : public Service {
private:
	Client client;
	//vector<Commodity> shoppingCart;
	vector<Order> order;
public:
	////���빺�ﳵ
	//void addCart(Commodity c) {
	//	shoppingCart.push_back(c);
	//}

	//������Ʒ
	void purchase(Order o) {
		order.push_back(o);
	}

	//�������
	void browseOrder() {

	}
};

