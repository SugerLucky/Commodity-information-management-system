#include "Commodity.h"

int Commodity::nextId = Commodity::getNextId();

// 获取下一个ID
int Commodity::getNextId() {
    return ++nextId;
}

//程序每一次启动时，从文件中加载最大ID
void Commodity::loadMaxId() {
    std::ifstream file(getMaxIdFileName());
    if (file.is_open()) {
        file >> nextId;
        file.close();
    }
}

// 更新最大ID到文件----应该是程序关闭时将最大的下个id写入文件
void Commodity::updateMaxId() {
    std::ofstream file(getMaxIdFileName());
    if (file.is_open()) {
        file << nextId;
        file.close();
    }
}