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
		/*ofstream file("Goods.txt", ios::app);
		if (file.is_open()) {
			file << commodity.toString() << endl;
			file.close();
		}
		else {
			cout << "Failed to open file for adding goods." << endl;
		}*/
		FileStorage::save(commodity);

		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
	}

	void modifyGoods(int id) {
		//从Goods.txt中查询到该id的商品，修改后重新添加到文件中
	}

	void browseClientOrders() {
		vector<Order> orders; //将order.txt文件中所有的订单一一存到到数组中,然后一一遍历
		
	}

	void searchClientOrders(int id) {
		//从order.txt文件中查找编号为id的商品
	}
};

