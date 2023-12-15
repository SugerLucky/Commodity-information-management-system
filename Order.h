#pragma once
#include <chrono>
#include <ctime>
#include "Commodity.h"
#include <fstream>
/*
* ������
*/
class Order
{
private:

	int id; //����id,��Ҫ��Ƴ����������Ա㲻ͬ�����в�ͬ��id

    static int nextId;  // ��̬��Ա��������ʾ��һ��������id

	string clientName; //�ͻ�����
	Commodity goods; //�����е���Ʒ
	int count; //��������
	std::chrono::system_clock::time_point createTime; //�����Ĵ���ʱ��

public:

	Order() = default;

    Order(int orderId, string clientName, const Commodity& orderGoods, int orderCount, const std::chrono::system_clock::time_point& orderCreateTime)
        : id(orderId), clientName(clientName), goods(orderGoods), count(orderCount), createTime(orderCreateTime) {}

    int getId() const { return id; }

    void setId(int newId) { id = newId; }

    string getClientId() const { return clientName; }

    void setClientId(string newClientName) { clientName = newClientName; }

    Commodity getGoods() const { return goods; }

    void setGoods(const Commodity& newGoods) { goods = newGoods; }

    int getCount() const { return count; }

    void setCount(int newCount) { count = newCount; }

    std::chrono::system_clock::time_point getCreateTime() const { return createTime; }

    void setCreateTime(const std::chrono::system_clock::time_point& newCreateTime) { createTime = newCreateTime; }

    string toString() {
        return "Order ID: " + to_string(id) + "\n" +
            "Client Name: " + clientName + "\n" +
            "Goods: \n" + goods.toString() + "\n" +
            "Count: " + to_string(count) + "\n" +
            "Create Time: " + to_string(std::chrono::system_clock::to_time_t(createTime));
    }

    static string getFileName() { return "orders.txt"; }


    static string getMaxIdFileName() { return "max_order_id.txt"; }

    static int getNextId();

    static void loadMaxId();

    static void updateMaxId();

};

