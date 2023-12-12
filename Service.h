#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
#include "Dao.h"
/*
* 客户和管理员业务逻辑处理的基类
*/
class Service {
private:
	Dao dao; //连接数据库

public:
	//校验用户登录
	bool checkUser(const string& username, const string& password, int role) {
		bool b = false;
		/*下面要去访问数据库，查询是否有该用户*/
		if (role == 1) {
			//去client表查询
			b = dao.check(username, password, role);

		}
		else {
			//去administrator表查询
			b = dao.check(username, password, role);
		}
		return b;
	}

	//注册用户
	void enroll(string username, string password, int role) {
		//将该用户信息存入数据库
		dao._register(username, password, role);
		cout << "注册成功" << endl;
	}

	//浏览商品
	void browseGoods() {
		vector<Commodity> res = dao.browseGoods();
	}

	//查询商品
	void searchGoods(int id) {
		Commodity goods = dao.searchGoods(id);

		goods.toString();
	}

	//





	
};

