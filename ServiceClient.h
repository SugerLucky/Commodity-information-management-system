#pragma once
#include "Service.h"
#include "Client.h"

/*
* ��Ӧ�ͻ��Ĳ���
*/
class ServiceClient : public Service {
private:

	vector<Order> order;
//��Ҫ�����һ��id�������Ļ��ƣ�Ȼ�����newOrder��id��ÿ����������������ܱ�֤

public:

	//������Ʒ---����Ʒȫ����ӵ�������
	//@ pram: numΪ���������
	void purchase(int id, int num) {
		//�������ɵĶ������뵽order.txt�ļ���

	}

	//�������
	void browseOrder() {
		//��order.txt�ļ��������еĶ����������order�����У��������ж�����Ϣչʾ����
		

	}
};

