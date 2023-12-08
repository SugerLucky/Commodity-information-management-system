#pragma once
#include <iostream>
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
	Service* service; //�ṩ�û����ֲ����Ľӿ�

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
                    cout << "��ѡ�����¼���˺����ͣ�1. ����Ա 2. �ͻ�" << endl;
                    cin >> key;

                    if (key == '1') {
                        service = new ServiceAdmin; //�ṩ����Ա�ķ���
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;

                        if (service->checkUser(username, password, 1)) { //������е�¼У��
                            //�ɹ�����������ͻ��˵�
                            while (loop) {
                                cout << "��ӭ����ͻ���������" << endl;
                                cout << "1. �����Ʒ" << endl;
                                cout << "2. ��ѯ��Ʒ" << endl;
                                cout << "3. ����û�����" << endl;
                                cout << "4. ��ѯ�û�����" << endl;
                                cout << "5. �˳�ϵͳ" << endl;
                                cout << "���������ѡ��: " << endl;
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
                        service = new ServiceClient; //�ṩ�ͻ��ķ���
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;
                        if (service->checkUser(username, password, 2)) { //������е�¼У��                        
                            //�ɹ��������������Ա�˵�
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
                                    cout << "��������������������룡" << endl;
                                    system("pasue");
                                    system("cls");
                                    break;
                                }
                            }


                        }
                        else {
                            cout << "��¼ʧ�ܣ������µ�¼��" << endl;
                        }
                    }
                    else {
                        cout << "��������������������룡" << endl;
                        system("pasue");
                        system("cls");
                    }
                    break;
                }
            case '2':
                cout << "��ѡ��ע����˺����ͣ�1. ����Ա 2. �ͻ�" << endl;
                cin >> key;
                cout << "�������û�����" << endl;
                cin >> username;
                cout << "���������룺" << endl;
                cin >> password;
                service->enroll(key);

                break;
            case '3':
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
};

