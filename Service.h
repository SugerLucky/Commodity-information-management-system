#pragma once
#include "User.h"
#include "Client.h"
#include "Administrator.h"
/*
* 客户和管理员业务逻辑处理的基类
*/
class Service {
private:
	User* user;

public:
	//校验用户登录
	bool checkUser(string username, string pwd, int role) {
		bool b = false;
		/*下面要去访问数据库，查询是否有该用户*/
		if (role == 1) {
			//去client表查询
		}
		else {
			//去administrator
		}

		//user->setUsername(username);
		//user->setPassword(pwd);

		




		//拿到结果进行判断
		if (true) {
			b = true;
		}
		return b;
	}

	//注册用户
	void enroll() {
		//将该用户信息存入数据库





		cout << "注册成功" << endl;
	}

	//浏览商品
	void browseGoods() {}

	//查询商品
	void searchGoods(int id) {}

	//





	
};

