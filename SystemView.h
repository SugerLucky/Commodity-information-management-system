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
	Service* service;

public:
	void mainMenu() {
        while (loop) {


            cout << "��ӭ������Ʒ��Ϣ����ϵͳ" << endl;
            cout << "1. ��¼ϵͳ" << endl;
            cout << "2. �˳�ϵͳ" << endl;
            cout << "���������ѡ��: (1-2)" << endl;

            while (loop) {
                cin >> key;

                //һ���˵�
                switch (key) {
                case '1':
                    cout << "��ѡ�����¼���˺����ͣ�1. ����Ա 2. �ͻ�" << endl;
                    cin >> key;
                    if (key == '1') {
                        string username;
                        string password;
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;
                        if () { //������е�¼У��
                            /*��������˵�*/








                        } else {
                            cout << "��¼ʧ�ܣ�" << endl;
                        }
                        
                    }
                    else if (key == '2') {
                        string username;
                        string password;
                        cout << "�������û�����" << endl;
                        cin >> username;
                        cout << "���������룺" << endl;
                        cin >> password;
                        if () { //������е�¼У��









                        } else {
                            cout << "��¼ʧ�ܣ�" << endl;
                        }
                    } else {
                        cout << "��������������������룡" << endl;
                    }
                    break;
                case '2':
                    loop = false;
                    break;
                default:
                    cout << "��������������������룡" << endl;
                }
            }
            



            //cout << "1. ��¼" << endl;
            //cout << "2. ע��" << endl;
            //cout << "3. �����Ʒ" << endl;
            //cout << "4. ��ѯ��Ʒ" << endl;
            //cout << "5. ������Ʒ" << endl;
            //cout << "6. �������" << endl;
            //cout << "7. �޸���Ʒ��Ϣ" << endl;
            //cout << "8. �鿴ȫ������" << endl;
            //cout << "9. �˳�" << endl;
        }

	}
};

