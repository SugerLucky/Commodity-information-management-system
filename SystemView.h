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
    ~SystemView();

	void mainMenu();
};

