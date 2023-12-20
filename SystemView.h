#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Service.h"
#include "ServiceAdmin.h"
#include "ServiceClient.h"
/*
* 商品信息管理系统的控制台界面
*/
class SystemView {
private:
	bool loop = true; //控制菜单显示
	char key = ' '; //接收用户选择
    int keyId = 0; //接收用户选择
	ServiceAdmin* serviceAdmin; //提供用户各种操作的接口
	ServiceClient* serviceClient; //提供用户各种操作的接口

public:
    ~SystemView();

	void mainMenu();
};

