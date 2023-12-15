#pragma once
#include <chrono>
#include <ctime>
#include "Commodity.h"
#include <fstream>
/*
* 订单类
*/
class Order
{
private:

	int id; //订单id,还要设计成自增长，以便不同订单有不同的id

    static int nextId;  // 静态成员变量，表示下一个订单的id

	string clientName; //客户名字
	Commodity goods; //订单中的商品
	int count; //订单数量
	std::chrono::system_clock::time_point createTime; //订单的创建时间

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

