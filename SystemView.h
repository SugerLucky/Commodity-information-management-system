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
	Service* service; //提供用户各种操作的接口

public:
	void mainMenu() {
        while (loop) {
            string username;
            string password;
            //一级菜单
            cout << "欢迎进入商品信息管理系统" << endl;
            cout << "1. 登录系统" << endl;
            cout << "2. 注册账号" << endl;
            cout << "3. 退出系统" << endl;
            cout << "请输入你的选择: " << endl;
            cin >> key;

            switch (key) {
            case '1':
                while (loop) {
                    //二级菜单
                    system("cls");
                    cout << "请选择你登录的账号类型：1. 管理员 2. 客户" << endl;
                    cin >> key;

                    if (key == '1') {
                        service = new ServiceAdmin; //提供管理员的服务
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;

                        if (service->checkUser(username, password, 1)) { //这里进行登录校验
                            //成功后进入三级客户菜单
                            while (loop) {
                                cout << "欢迎进入客户操作界面" << endl;
                                cout << "1. 浏览商品" << endl;
                                cout << "2. 查询商品" << endl;
                                cout << "3. 浏览用户订单" << endl;
                                cout << "4. 查询用户订单" << endl;
                                cout << "5. 退出系统" << endl;
                                cout << "请输入你的选择: " << endl;
                                cin >> key;

                                switch (key) {
                                case '1':

                                    break;
                                case '2':

                                    break;
                                case '3':

                                    break;
                                case '4':

                                    break;
                                case '5':
                                    loop = false;
                                    break;
                                default:
                                    cout << "你的输入有误，请重新输入！" << endl;
                                    system("pasue");
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else {
                            cout << "登录失败！" << endl;
                        }
                    }
                    else if (key == '2') {
                        service = new ServiceClient; //提供客户的服务
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;
                        if (service->checkUser(username, password, 2)) { //这里进行登录校验                        
                            //成功后进入三级管理员菜单
                            while (loop) {
                                cout << "欢迎进入客户操作界面" << endl;
                                cout << "1. 浏览商品" << endl;
                                cout << "2. 查询商品" << endl;
                                cout << "3. 购买商品" << endl;
                                cout << "4. 浏览订单" << endl;
                                cout << "5. 退出系统" << endl;
                                cout << "请输入你的选择: " << endl;
                                cin >> key;
                                switch (key) {
                                case '1':

                                    break;
                                case '2':

                                    break;
                                case '3':

                                    break;
                                case '4':

                                    break;
                                case '5':
                                    loop = false;
                                    break;
                                default:
                                    cout << "你的输入有误，请重新输入！" << endl;
                                    system("pasue");
                                    system("cls");
                                    break;
                                }
                            }


                        }
                        else {
                            cout << "登录失败，请重新登录！" << endl;
                        }
                    }
                    else {
                        cout << "你的输入有误，请重新输入！" << endl;
                        system("pasue");
                        system("cls");
                    }
                    break;
                }
            case '2':
                cout << "请选择注册的账号类型：1. 管理员 2. 客户" << endl;
                cin >> key;
                cout << "请输入用户名：" << endl;
                cin >> username;
                cout << "请输入密码：" << endl;
                cin >> password;
                service->enroll(key);

                break;
            case '3':
                loop = false;
                break;
            default:
                cout << "你的输入有误，请重新输入！" << endl;
                system("pasue");
                system("cls");
                break;
            }
        }
	}
};

