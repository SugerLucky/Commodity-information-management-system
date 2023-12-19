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
	ServiceClient(const string& name, const string& pwd) {
		client.setUsername(name);
		client.setPassword(pwd);
	}

    void purchase(const string& username, int id, int num) {
        Order newOrder;
        newOrder.setId(Order::getNextId());  // ���ö���IDΪ��һ�����õ�ID
        newOrder.setClientName(username);

		vector<Commodity> goods = FileStorage::loadAll<Commodity>();
		for (const auto& good : goods) {
			// �����Ʒid�Ƿ�ƥ��
			if (good.getId() == id) {
				// �ҵ���ָ��id����Ʒ��Ϣ
				// �������Ʒ���붩����
				newOrder.setGoods(good);
				break; // ����ҵ���ָ��id����Ʒ��Ϣ��ֱ������ѭ��
			}
		}

        newOrder.setCount(num);
        newOrder.setCreateTime(std::chrono::system_clock::now());

        FileStorage::save(newOrder); //���涩�����ļ���

        cout << "����ɹ���" << endl;
        system("pause");
        system("cls");

    }

    void browseOrder() {
		vector<Order> orders = FileStorage::loadAll<Order>(); // ���ļ��м������ж���
		vector<Order> clientOrders; // ���û��Ķ���
		for (const auto& order : orders) {
			if (order.getClientName() == client.getUsername()) {
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
			cout << "δ�ҵ�" << "����" << "�Ķ���" << endl;
			system("pause");
			system("cls");
		}
	}
};

