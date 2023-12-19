#pragma once
#include "Service.h"
#include "Commodity.h"

/*
* 响应管理员的操作
*/
class ServiceAdmin : public Service {
public:

	void addGoods() {
		cout << "请输入你要添加商品的相关信息：" << endl;
		string name;
		int type = 0;
		double price = 0;
		int count= 0;
		int supplierId = 0;
		cout << "请输入商品的名称：";
		cin >> name;
		cout << "请输入商品的类型：（1.食品 2.衣服 3.数码 4.书籍）";
		cin >> type;
		cout << "请输入商品的价格：";
		cin >> price;
		cout << "请输入商品的数量：";
		cin >> count;
		cout << "请输入供应商的id：";
		cin >> supplierId;

		Commodity commodity(Commodity::getNextId(), name, type, price, count, supplierId);
		FileStorage::save(commodity);

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}



	void browseClientOrders() {
		vector<Order> orders = FileStorage::loadAll<Order>(); // 从文件中加载所有订单
		for (const auto& order : orders) {
			cout << order.toString() << endl;
		}
		system("pause");
		system("cls");
	}

	void searchClientOrders(const string& name) {
		vector<Order> orders = FileStorage::loadAll<Order>(); // 从文件中加载所有订单
		vector<Order> clientOrders; // 该用户的订单
		for (const auto& order : orders) {
			if (order.getClientName() == name) {
				clientOrders.push_back(order);
			}
		}

		if (clientOrders.size() != 0) {
			for (const auto& order : clientOrders) {
				cout << order.toString() << endl;
			}
			system("pause");
			system("cls");
		}
		else {
			cout << "未找到" << name << "的订单" << endl;
			system("pause");
			system("cls");
		}
	}
};

