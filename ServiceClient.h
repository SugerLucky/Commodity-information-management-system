#pragma once
#include "Service.h"
#include "Client.h"

/*
* 响应客户的操作
*/
class ServiceClient : public Service {
private:

	vector<Order> order;
//还要在设计一个id自增长的机制，然后更新newOrder的id，每次重新启动程序后都能保证

public:

	//购买商品---将商品全部添加到订单中
	//@ pram: num为购买的数量
	void purchase(int id, int num) {
		//将该生成的订单加入到order.txt文件中

	}

	//浏览订单
	void browseOrder() {
		//打开order.txt文件，将所有的订单对象存入order数组中，并将所有订单信息展示出来
		

	}
};

