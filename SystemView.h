#pragma once
#include "Service.h"
/*
* ��Ʒ��Ϣ����ϵͳ�Ŀ���̨����
*/
class SystemView {
private:
	bool loop = true; //���Ʋ˵���ʾ
	char key = ' '; //�����û�ѡ��
	Service* service = new Service();


};

