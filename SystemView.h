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
    ~SystemView() {
        delete serviceAdmin;
        delete serviceClient;
    }

    //动态分配对象，但是特有方法又掉不了，除非是接口编程的形式

public:
	void mainMenu() {
        Order::loadMaxId(); //加载订单的下一个编号
        Commodity::loadMaxId(); //加载商品的下一个编号

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
                    cout << "请选择你登录的账号类型：1. 管理员 2. 客户 (输入0可返回主菜单)" << endl;
                    cin >> key;

                    if (key == '1') {
                        //service = new ServiceAdmin; //提供管理员的服务
                        //ServiceAdmin* serAdmin = (ServiceAdmin*)service;
                        serviceAdmin = new ServiceAdmin;
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;
                        
                        if (serviceAdmin->checkUser(username, password, 1)) { //这里进行登录校验
                            //成功后进入三级客户菜单
                            cout << "登录成功" << endl;
                            system("pause");
                            system("cls");
                            while (loop) {
                                cout << "欢迎进入管理员操作界面" << endl;
                                cout << "1. 浏览商品" << endl;
                                cout << "2. 查询商品" << endl;
                                cout << "3. 添加商品" << endl;
                                cout << "4. 浏览用户订单" << endl;
                                cout << "5. 查询用户订单" << endl;
                                cout << "6. 退出系统" << endl;
                                cout << "请输入你的选择: " << endl;
                                cin >> key;

                                switch (key) {
                                case '1':
                                    serviceAdmin->browseGoods();
                                    break;
                                case '2':
                                    cout << "请输入查询商品的id" << endl;
                                    cin >> keyId;
                                    serviceAdmin->searchGoods(keyId);
                                    break;
                                case '3':
                                    serviceAdmin->addGoods();
                                    break;
                                case '4':
                                    serviceAdmin->browseClientOrders();
                                    break;
                                case '5':
                                    cout << "请输入你要查询用户的用户名: " << endl;
                                    cin >> username;
                                    serviceAdmin->searchClientOrders(username);
                                    break;
                                case '6':
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
                        
                        cout << "请输入用户名：" << endl;
                        cin >> username;
                        cout << "请输入密码：" << endl;
                        cin >> password;
                        serviceClient = new ServiceClient(username, password); //提供客户的服务
                        
                        if (serviceClient->checkUser(username, password, 2)) { //这里进行登录校验                        
                            //成功后进入三级的客户菜单
                            cout << "登录成功" << endl;
                            system("pause");
                            system("cls");
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
                                    serviceClient->browseGoods();
                                    break;
                                case '2':
                                    cout << "请输入你要查询商品的id" << endl;
                                    int id;
                                    cin >> id;
                                    serviceClient->searchGoods(id);
                                    break;
                                case '3':
                                    cout << "请输入你要购买商品的id" << endl;
                                    cin >> id;
                                    int num;
                                    cout << "请输入购买的数量" << endl;
                                    cin >> num;
                                    serviceClient->purchase(username, id, num);
                                    break;
                                case '4':
                                    serviceClient->browseOrder();
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
                            system("pause");
                            system("cls");
                        }
                    }
                    else if (key == '0') {
                        system("cls");
                        break; // 返回主菜单

                    }
                    else {
                        cout << "你的输入有误，请重新输入！" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            case '2':
                cout << "请选择注册的账号类型：1. 管理员 2. 客户" << endl;
                cin >> key;
                if (key == '1') {
                    cout << "请输入用户名：" << endl;
                    cin >> username;
                    cout << "请输入密码：" << endl;
                    cin >> password;
                    serviceAdmin->enroll(username, password, 1);
                }
                else if (key == '2') {
                    cout << "请输入用户名：" << endl;
                    cin >> username;
                    cout << "请输入密码：" << endl;
                    cin >> password;
                    serviceClient->enroll(username, password, 2);
                }
                else {
                    cout << "你的输入有误, 注册失败！" << endl;
                    system("pause");
                    system("cls");
                }
                break;
            case '3':
                loop = false;
                break;
            default:
                cout << "你的输入有误，请重新输入！" << endl;
                system("pause");
                system("cls");
                break;
            }
        }

        Order::updateMaxId(); //退出系统时，将下一次的订单id存入文件，以便程序再次启动时加载出来
        Commodity::updateMaxId();
	}
};

