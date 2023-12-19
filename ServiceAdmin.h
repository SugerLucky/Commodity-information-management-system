#pragma once
#include "Service.h"
#include "Commodity.h"

/*
* ��Ӧ����Ա�Ĳ���
*/
class ServiceAdmin : public Service {
public:

	void addGoods() {
		cout << "��������Ҫ�����Ʒ�������Ϣ��" << endl;
		string name;
		int type = 0;
		double price = 0;
		int count= 0;
		int supplierId = 0;
		cout << "��������Ʒ�����ƣ�";
		cin >> name;
		cout << "��������Ʒ�����ͣ���1.ʳƷ 2.�·� 3.���� 4.�鼮��";
		cin >> type;
		cout << "��������Ʒ�ļ۸�";
		cin >> price;
		cout << "��������Ʒ��������";
		cin >> count;
		cout << "�����빩Ӧ�̵�id��";
		cin >> supplierId;

		Commodity commodity(Commodity::getNextId(), name, type, price, count, supplierId);
		FileStorage::save(commodity);

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}



	void browseClientOrders() {
		vector<Order> orders = FileStorage::loadAll<Order>(); // ���ļ��м������ж���
		for (const auto& order : orders) {
			cout << order.toString() << endl;
		}
		system("pause");
		system("cls");
	}

	void searchClientOrders(const string& name) {
		vector<Order> orders = FileStorage::loadAll<Order>(); // ���ļ��м������ж���
		vector<Order> clientOrders; // ���û��Ķ���
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
			cout << "δ�ҵ�" << name << "�Ķ���" << endl;
			system("pause");
			system("cls");
		}
	}
};

