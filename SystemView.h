#pragma once
#include <iostream>
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
	Service* service;

public:
	void mainMenu() {
        while (loop) {


            cout << "欢迎进入商品信息管理系统" << endl;
            cout << "1. 登录系统" << endl;
            cout << "2. 退出系统" << endl;
            cout << "请输入你的选择: (1-2)" << endl;

            while (loop) {
                cin >> key;

                //一级菜单
                switch (key) {
                case '1':
                    cout << "请选择你登录的账号类型：1. 管理员 2. 客户" << endl;
                    cin >> key;
                    if (key == '1') {
                        string username;
                        string password;
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;
                        if () { //这里进行登录校验
                            /*进入二级菜单*/








                        } else {
                            cout << "登录失败！" << endl;
                        }
                        
                    }
                    else if (key == '2') {
                        string username;
                        string password;
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;
                        if () { //这里进行登录校验









                        } else {
                            cout << "登录失败！" << endl;
                        }
                    } else {
                        cout << "你的输入有误，请重新输入！" << endl;
                    }
                    break;
                case '2':
                    loop = false;
                    break;
                default:
                    cout << "你的输入有误，请重新输入！" << endl;
                }
            }
            



            //cout << "1. 登录" << endl;
            //cout << "2. 注册" << endl;
            //cout << "3. 浏览商品" << endl;
            //cout << "4. 查询商品" << endl;
            //cout << "5. 购买商品" << endl;
            //cout << "6. 浏览订单" << endl;
            //cout << "7. 修改商品信息" << endl;
            //cout << "8. 查看全部订单" << endl;
            //cout << "9. 退出" << endl;
        }

	}
};

