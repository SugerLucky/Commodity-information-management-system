#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
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
		/*����Ҫȥ�������ݿ⣬��ѯ�Ƿ��и��û�*/
		if (role == 1) {
			//ȥclient���ѯ
		}
		else {
			//ȥadministrator
		}

		//user->setUsername(username);
		//user->setPassword(pwd);

		




		//�õ���������ж�
		if (true) {
			b = true;
		}
		return b;
	}

	//ע���û�
	void enroll() {
		//�����û���Ϣ�������ݿ�





		cout << "ע��ɹ�" << endl;
	}

	//�����Ʒ
	void browseProducts() {}

	//��ѯ��Ʒ
	void findProducts() {}

	//





	
};

