#pragma once
#include "Service.h"
#include "Client.h"
/*
* 响应客户的操作
*/
class ServiceClient : public Service {
private:
	Client client;
	//vector<Commodity> shoppingCart;
	vector<Order> order;
public:
	////加入购物车
	//void addCart(Commodity c) {
	//	shoppingCart.push_back(c);
	//}

	//购买商品
	void purchase(Order o) {
		order.push_back(o);
	}

	//浏览订单
	void browseOrder() {

	}
};

