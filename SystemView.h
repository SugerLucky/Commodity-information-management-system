#pragma once
#include "Service.h"
/*
* 商品信息管理系统的控制台界面
*/
class SystemView {
private:
	bool loop = true; //控制菜单显示
	char key = ' '; //接收用户选择
	Service* service = new Service();


};

