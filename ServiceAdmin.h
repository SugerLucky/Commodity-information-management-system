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
		/*ofstream file("Goods.txt", ios::app);
		if (file.is_open()) {
			file << commodity.toString() << endl;
			file.close();
		}
		else {
			cout << "Failed to open file for adding goods." << endl;
		}*/
		FileStorage::save(commodity);

		cout << "��ӳɹ���" << endl;
		system("pause");
		system("cls");
	}

	void modifyGoods(int id) {
		//��Goods.txt�в�ѯ����id����Ʒ���޸ĺ�������ӵ��ļ���
	}

	void browseClientOrders() {
		vector<Order> orders; //��order.txt�ļ������еĶ���һһ�浽��������,Ȼ��һһ����
		
	}

	void searchClientOrders(int id) {
		//��order.txt�ļ��в��ұ��Ϊid����Ʒ
	}
};

