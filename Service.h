#pragma once
#include "User.h"
/*
* �ͻ��͹���Աҵ���߼�����Ļ���
*/
class Service {
private:
	User* user;

public:
	//У���û���¼
	bool checkUser(string username, string pwd, int role) {
		bool b = false;
		user->setUsername(username);
		user->setPassword(pwd);

		/*����Ҫȥ�������ݿ⣬��ѯ�Ƿ��и��û�*/




		//�õ���������ж�
		if (true) {
			b = true;
		}
		return b;
	}

	//ע���û�
	void enroll(int i) {
		//�����û���Ϣ�������ݿ�





		cout << "ע��ɹ�" << endl;
	}

	//�����Ʒ
	void browseProducts();

	//��ѯ��Ʒ
	void findProducts();





	
};

