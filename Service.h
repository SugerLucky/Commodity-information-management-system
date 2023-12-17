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
	bool checkUser(string username, string password, int role) {
		vector<Administrator> admins;
		vector<Client> clients;
		string filename = (role == 1) ? "administrators.txt" : "clients.txt";
		if (role == 1) {
			admins = FileStorage::loadAll<Administrator>();
			for (const auto& userInfo : admins) {
				// �����û���Ϣƥ����߼�
				if (username == userInfo.getUsername() && password == userInfo.getPassword()) {
					return true;
				}
			}
		}
		else {
			clients = FileStorage::loadAll<Client>();
			User user(username, password);
			string res = user.toString(); //������¼�û�����Ϣ
			for (const auto& userInfo : clients) {
				// �����û���Ϣƥ����߼�
				if (username == userInfo.getUsername() && password == userInfo.getPassword()) {
					return true;
				}
			}
		}
		return false;
	}

	//ע���û�
	void enroll(string username, string password, int role) {
		string filename = (role == 1) ? "clients.txt" : "administrators.txt";

		if (role == 1) {
			//�����û���Ϣ����client.txt�ļ���
			Administrator admin(username, password);
			FileStorage::save(admin);
		}
		else {
			//�����û���Ϣ����administrator.txt�ļ���
			Client client(username, password);
			FileStorage::save(client);
		}
		cout << "ע��ɹ�" << endl;
		system("pause");
		system("cls");
	}

	//�����Ʒ
	void browseGoods() {
		vector<Commodity> goodsInfo = FileStorage::loadAll<Commodity>();
		for (const auto& info : goodsInfo) {
			// չʾ��Ʒ��Ϣ
			cout << info.toString() << endl;
		}

		system("pause");
		system("cls");
	}

	//��ѯ��Ʒ
	void searchGoods(int id) {
		vector<Commodity> goodsInfo = FileStorage::loadAll<Commodity>();
		bool found = false;
		for (const auto& info : goodsInfo) {
			// �����Ʒid�Ƿ�ƥ��
			if (info.getId() == id) {
				// �ҵ���ָ��id����Ʒ��Ϣ
				// չʾ�����Ʒ��Ϣ
				cout << "Found commodity: " << info.toString() << endl;
				found = true;
				break; // ����ҵ���ָ��id����Ʒ��Ϣ��ֱ������ѭ��
			}
		}
		if (!found) {
			cout << "Commodity with ID " << id << " not found." << endl;
		}
		system("pause");
		system("cls");
	}
};

