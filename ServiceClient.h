#pragma once
#include "Service.h"
#include "Client.h"
#include "Dao.h"
/*
* ��Ӧ�ͻ��Ĳ���
*/
class ServiceClient : public Service {
private:
	Dao dao;
	//Client client;
	//vector<Commodity> shoppingCart;
	vector<Order> order;
	int orderNum = 1; //��ǰ���ܶ�����
	int idCount = 1; //���һ��id�������Ļ��ƣ�Ȼ�����newOrder��id

public:
	////���빺�ﳵ
	//void addCart(Commodity c) {
	//	shoppingCart.push_back(c);
	//}

	//������Ʒ---����Ʒȫ����ӵ�������
	//@ pram: numΪ���������
	void purchase(int id, int num) {
			//Order o(idCount++, client.getId(), goods.getId(), num);
			//order.push_back(o);
			//orderNum++;

		dao.purchase(id, num);
			//��Ҫ���ö������뵽��������

	}

	//�������
	void browseOrder() {
		//��ѯ���ݿⶩ�������ж���չʾ����
		dao.browseOrder();

	}
};

