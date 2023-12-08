#pragma once
#include "Service.h"
#include "User.h"
/*
* 接收请求响应数据给控制台界面
*/
class Controller {
private:
	Service* service;

	//每一个对外暴露的方法都称之为功能接口
public:
	User* list() {

	}
};

