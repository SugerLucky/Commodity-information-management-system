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
	bool checkUser(string username, string password, int role);

	//注册用户
	void enroll(string username, string password, int role);

	//浏览商品
	void browseGoods();

	//查询商品
	void searchGoods(int id);
};

