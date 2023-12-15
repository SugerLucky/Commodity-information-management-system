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
		vector<string> users;
		string filename = (role == 1) ? "administrators.txt" : "clients.txt";
		if (role == 1) {
			users = FileStorage::loadAll<Administrator>();
		}
		else {
			users = FileStorage::loadAll<Client>();
		}

		User user(username, password);
		string res = user.toString(); //������¼�û�����Ϣ
		for (const auto& userInfo : users) {
			// �����û���Ϣƥ����߼�
			if (res == userInfo) {
				return true;
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
		vector<string> goodsInfo = FileStorage::loadAll<Commodity>();
		for (const auto& info : goodsInfo) {
			// չʾ��Ʒ��Ϣ
			cout << info << endl;
		}

		system("pause");
		system("cls");
	}

	//��ѯ��Ʒ
	void searchGoods(int id) {
		vector<string> goodsInfo = FileStorage::loadAll<Commodity>();
		bool found = false;
		for (const auto& info : goodsInfo) {
			Commodity currentCommodity;
			// ���ַ����д���Commodity����
			currentCommodity = Commodity::fromString(info);

			// �����Ʒid�Ƿ�ƥ��
			if (currentCommodity.getId() == id) {
				// �ҵ���ָ��id����Ʒ��Ϣ
				// չʾ�����Ʒ��Ϣ
				cout << "Found commodity: " << info << endl;
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

