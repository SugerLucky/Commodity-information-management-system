#include "Order.h"

int Order::nextId = Order::getNextId();


int Order::getNextId() {
    return ++nextId;
}

void Order::loadMaxId() {
    //���ļ��м������ID
    std::ifstream file(getMaxIdFileName());
    if (file.is_open()) {
        file >> nextId;
        file.close();
    }
}

void Order::updateMaxId() {
    // �������id���ļ�
    std::ofstream file(getMaxIdFileName(), std::ios::trunc);  // ���ļ�ʱ�������
    if (file.is_open()) {
        file << nextId; 
    }
    file.close();
}