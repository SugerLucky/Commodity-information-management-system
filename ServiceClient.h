#pragma once
#include "Service.h"
#include "Client.h"
#include "Dao.h"
/*
* 响应客户的操作
*/
class ServiceClient : public Service {
private:
	Dao dao;
	//Client client;
	//vector<Commodity> shoppingCart;
	vector<Order> order;
	int orderNum = 1; //当前的总订单数
	int idCount = 1; //设计一个id自增长的机制，然后更新newOrder的id

public:
	////加入购物车
	//void addCart(Commodity c) {
	//	shoppingCart.push_back(c);
	//}

	//购买商品---将商品全部添加到订单中
	//@ pram: num为购买的数量
	void purchase(int id, int num) {
			//Order o(idCount++, client.getId(), goods.getId(), num);
			//order.push_back(o);
			//orderNum++;

		dao.purchase(id, num);
			//还要将该订单加入到订单表中

	}

	//浏览订单
	void browseOrder() {
		//查询数据库订单表将所有订单展示出来
		dao.browseOrder();

	}
};

