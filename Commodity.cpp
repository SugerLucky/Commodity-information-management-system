#include "Commodity.h"

int Commodity::nextId = Commodity::getNextId();

// ��ȡ��һ��ID
int Commodity::getNextId() {
    return ++nextId;
}

//����ÿһ������ʱ�����ļ��м������ID
void Commodity::loadMaxId() {
    std::ifstream file(getMaxIdFileName());
    if (file.is_open()) {
        file >> nextId;
        file.close();
    }
}

// �������ID���ļ�----Ӧ���ǳ���ر�ʱ�������¸�idд���ļ�
void Commodity::updateMaxId() {
    std::ofstream file(getMaxIdFileName());
    if (file.is_open()) {
        file << nextId;
        file.close();
    }
}