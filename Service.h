#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
#include "FileStorage.h"

/*
* �ͻ��͹���Աҵ���߼�����Ļ���
*/
class Service {
private:

public:
	//У���û���¼
	bool checkUser(string username, string password, int role);

	//ע���û�
	void enroll(string username, string password, int role);

	//�����Ʒ
	void browseGoods();

	//��ѯ��Ʒ
	void searchGoods(int id);
};

