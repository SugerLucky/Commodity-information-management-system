#pragma once
#include "Service.h"
#include "Client.h"

/*
* 响应客户的操作
*/
class ServiceClient : public Service {
private:

public:

    void purchase(const string& username, int id, int num) {
        Order newOrder;
        newOrder.setId(Order::getNextId());  // 设置订单ID为下一个可用的ID
        newOrder.setClientName(username);

		vector<Commodity> goods = FileStorage::loadAll<Commodity>();
		for (const auto& good : goods) {
			// 检查商品id是否匹配
			if (good.getId() == id) {
				// 找到了指定id的商品信息
				// 将这个商品加入订单中
				newOrder.setGoods(good);
				break; // 如果找到了指定id的商品信息，直接跳出循环
			}
		}

        newOrder.setCount(num);
        newOrder.setCreateTime(std::chrono::system_clock::now());

        FileStorage::save(newOrder); //保存订单到文件中

        cout << "购买成功！" << endl;
        system("pause");
        system("cls");

    }

    void browseOrder() {
        vector<Order> orders = FileStorage::loadAll<Order>();
        for (const auto& order : orders) {
            cout << order.toString() << endl;
        }
        system("pause");
        system("cls");
    }
};

