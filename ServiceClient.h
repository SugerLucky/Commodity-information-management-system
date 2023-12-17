#pragma once
#include "Service.h"
#include "Client.h"

/*
* ��Ӧ�ͻ��Ĳ���
*/
class ServiceClient : public Service {
private:

public:

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
        vector<Order> orders = FileStorage::loadAll<Order>();
        for (const auto& order : orders) {
            cout << order.toString() << endl;
        }
        system("pause");
        system("cls");
    }
};

