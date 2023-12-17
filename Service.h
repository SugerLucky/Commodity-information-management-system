#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
#include "FileStorage.h"

/*
* 客户和管理员业务逻辑处理的基类
*/
class Service {
private:

public:
	//校验用户登录
	bool checkUser(string username, string password, int role) {
		vector<Administrator> admins;
		vector<Client> clients;
		string filename = (role == 1) ? "administrators.txt" : "clients.txt";
		if (role == 1) {
			admins = FileStorage::loadAll<Administrator>();
			for (const auto& userInfo : admins) {
				// 进行用户信息匹配的逻辑
				if (username == userInfo.getUsername() && password == userInfo.getPassword()) {
					return true;
				}
			}
		}
		else {
			clients = FileStorage::loadAll<Client>();
			User user(username, password);
			string res = user.toString(); //即将登录用户的信息
			for (const auto& userInfo : clients) {
				// 进行用户信息匹配的逻辑
				if (username == userInfo.getUsername() && password == userInfo.getPassword()) {
					return true;
				}
			}
		}
		return false;
	}

	//注册用户
	void enroll(string username, string password, int role) {
		string filename = (role == 1) ? "clients.txt" : "administrators.txt";

		if (role == 1) {
			//将该用户信息存入client.txt文件中
			Administrator admin(username, password);
			FileStorage::save(admin);
		}
		else {
			//将该用户信息存入administrator.txt文件中
			Client client(username, password);
			FileStorage::save(client);
		}
		cout << "注册成功" << endl;
		system("pause");
		system("cls");
	}

	//浏览商品
	void browseGoods() {
		vector<Commodity> goodsInfo = FileStorage::loadAll<Commodity>();
		for (const auto& info : goodsInfo) {
			// 展示商品信息
			cout << info.toString() << endl;
		}

		system("pause");
		system("cls");
	}

	//查询商品
	void searchGoods(int id) {
		vector<Commodity> goodsInfo = FileStorage::loadAll<Commodity>();
		bool found = false;
		for (const auto& info : goodsInfo) {
			// 检查商品id是否匹配
			if (info.getId() == id) {
				// 找到了指定id的商品信息
				// 展示这个商品信息
				cout << "Found commodity: " << info.toString() << endl;
				found = true;
				break; // 如果找到了指定id的商品信息，直接跳出循环
			}
		}
		if (!found) {
			cout << "Commodity with ID " << id << " not found." << endl;
		}
		system("pause");
		system("cls");
	}
};

