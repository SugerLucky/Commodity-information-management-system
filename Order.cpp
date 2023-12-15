#include "Order.h"

int Order::nextId = Order::getNextId();


int Order::getNextId() {
    return ++nextId;
}

void Order::loadMaxId() {
    //从文件中加载最大ID
    std::ifstream file(getMaxIdFileName());
    if (file.is_open()) {
        file >> nextId;
        file.close();
    }
}

void Order::updateMaxId() {
    // 更新最大id到文件
    std::ofstream file(getMaxIdFileName(), std::ios::trunc);  // 打开文件时清空内容
    if (file.is_open()) {
        file << nextId; 
    }
    file.close();
}