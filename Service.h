#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
#include "Dao.h"
/*
* �ͻ��͹���Աҵ���߼�����Ļ���
*/
class Service {
private:
	Dao dao; //�������ݿ�

public:
	//У���û���¼
	bool checkUser(const string& username, const string& password, int role) {
		bool b = false;
		/*����Ҫȥ�������ݿ⣬��ѯ�Ƿ��и��û�*/
		if (role == 1) {
			//ȥclient���ѯ
			b = dao.check(username, password, role);

		}
		else {
			//ȥadministrator���ѯ
			b = dao.check(username, password, role);
		}
		return b;
	}

	//ע���û�
	void enroll() {
		//�����û���Ϣ�������ݿ�





		cout << "ע��ɹ�" << endl;
	}

	//�����Ʒ
	void browseGoods() {

	}

	//��ѯ��Ʒ
	void searchGoods(int id) {
	
	}

	//





	
};

