#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Service.h"
#include "ServiceAdmin.h"
#include "ServiceClient.h"
/*
* ��Ʒ��Ϣ����ϵͳ�Ŀ���̨����
*/
class SystemView {
private:
	bool loop = true; //���Ʋ˵���ʾ
	char key = ' '; //�����û�ѡ��
    int keyId = 0; //�����û�ѡ��
	ServiceAdmin* serviceAdmin; //�ṩ�û����ֲ����Ľӿ�
	ServiceClient* serviceClient; //�ṩ�û����ֲ����Ľӿ�

public:
    ~SystemView() {
        delete serviceAdmin;
        delete serviceClient;
    }

    //��̬������󣬵������з����ֵ����ˣ������ǽӿڱ�̵���ʽ

public:
	void mainMenu() {
        while (loop) {
            string username;
            string password;
            //һ���˵�
            cout << "��ӭ������Ʒ��Ϣ����ϵͳ" << endl;
            cout << "1. ��¼ϵͳ" << endl;
            cout << "2. ע���˺�" << endl;
            cout << "3. �˳�ϵͳ" << endl;
            cout << "���������ѡ��: " << endl;
            cin >> key;

            switch (key) {
            case '1':
                while (loop) {
                    //�����˵�
                    system("cls");
                    cout << "��ѡ�����¼���˺����ͣ�1. ����Ա 2. �ͻ� (����0�ɷ������˵�)" << endl;
                    cin >> key;

                    if (key == '1') {
                        //service = new ServiceAdmin; //�ṩ����Ա�ķ���
                        //ServiceAdmin* serAdmin = (ServiceAdmin*)service;
                        serviceAdmin = new ServiceAdmin;
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;

                        if (serviceAdmin->checkUser(username, password, 1)) { //������е�¼У��
                            //�ɹ�����������ͻ��˵�
                            cout << "��¼�ɹ�" << endl;
                            system("pause");
                            system("cls");
                            while (loop) {
                                cout << "��ӭ����ͻ���������" << endl;
                                cout << "1. �����Ʒ" << endl;
                                cout << "2. ��ѯ��Ʒ" << endl;
                                cout << "3. �����Ʒ" << endl;
                                cout << "4. ����û�����" << endl;
                                cout << "5. ��ѯ�û�����" << endl;
                                cout << "6. �˳�ϵͳ" << endl;
                                cout << "���������ѡ��: " << endl;
                                cin >> key;

                                switch (key) {
                                case '1':
                                    serviceAdmin->browseGoods();
                                    break;
                                case '2':
                                    cout << "�������ѯ��Ʒ��id" << endl;
                                    cin >> keyId;
                                    serviceAdmin->searchGoods(keyId);
                                    break;
                                case '3':
                                    cout << "��������Ҫ�����Ʒ�������Ϣ��" << endl;
                                    //����ʵ��
                                    serviceAdmin->addGoods();
                                    break;
                                case '4':
                                    serviceAdmin->browseClientOrders();
                                    break;
                                case '5':
                                    cout << "��������Ҫ��ѯ�û���id: " << endl;
                                    cin >> key;
                                    serviceAdmin->searchClientOrders(key);
                                    break;
                                case '6':
                                    loop = false;
                                    break;
                                default:
                                    cout << "��������������������룡" << endl;
                                    system("pasue");
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else {
                            cout << "��¼ʧ�ܣ�" << endl;
                        }
                    }
                    else if (key == '2') {
                        serviceClient = new ServiceClient; //�ṩ�ͻ��ķ���
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;
                        if (serviceClient->checkUser(username, password, 2)) { //������е�¼У��                        
                            //�ɹ��������������Ա�˵�
                            cout << "��¼�ɹ�" << endl;
                            system("pause");
                            system("cls");
                            while (loop) {
                                cout << "��ӭ����ͻ���������" << endl;
                                cout << "1. �����Ʒ" << endl;
                                cout << "2. ��ѯ��Ʒ" << endl;
                                cout << "3. ������Ʒ" << endl;
                                cout << "4. �������" << endl;
                                cout << "5. �˳�ϵͳ" << endl;
                                cout << "���������ѡ��: " << endl;
                                cin >> key;
                                switch (key) {
                                case '1':
                                    serviceClient->browseGoods();
                                    break;
                                case '2':
                                    cout << "��������Ҫ��ѯ��Ʒ��id" << endl;
                                    int id;
                                    cin >> id;
                                    serviceClient->searchGoods(id);
                                    break;
                                case '3':
                                    cout << "��������Ҫ������Ʒ��id" << endl;
                                    cin >> id;
                                    int num;
                                    cout << "�����빺�������" << endl;
                                    cin >> num;
                                    serviceClient->purchase(id, num);
                                    break;
                                case '4':
                                    serviceClient->browseOrder();
                                    break;
                                case '5':
                                    loop = false;
                                    break;
                                default:
                                    cout << "��������������������룡" << endl;
                                    system("pasue");
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else {
                            cout << "��¼ʧ�ܣ������µ�¼��" << endl;
                            system("pause");
                            system("cls");
                        }
                    }
                    else if (key == '0') {
                        system("cls");
                        break; // �������˵�

                    }
                    else {
                        cout << "��������������������룡" << endl;
                        system("pause");
                        system("cls");
                    }
                }
                break;
            case '2':
                cout << "��ѡ��ע����˺����ͣ�1. ����Ա 2. �ͻ�" << endl;
                cin >> key;
                if (key == '1') {
                    cout << "�������û�����" << endl;
                    cin >> username;
                    cout << "���������룺" << endl;
                    cin >> password;
                    serviceAdmin->enroll(username, password, 1);
                    cout << "ע��ɹ�������������ҳ" << endl;
                    system("pause");
                    system("cls");
                }
                else if (key == '2') {
                    cout << "�������û�����" << endl;
                    cin >> username;
                    cout << "���������룺" << endl;
                    cin >> password;
                    serviceClient->enroll(username, password, 2);
                    cout << "ע��ɹ�������������ҳ" << endl;
                    system("pause");
                    system("cls");
                }
                else {
                    cout << "�����������, ע��ʧ�ܣ�" << endl;
                    system("pause");
                    system("cls");
                }
                break;
            case '3':
                loop = false;
                break;
            default:
                cout << "��������������������룡" << endl;
                system("pause");
                system("cls");
                break;
            }
        }
	}
};

