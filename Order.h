#pragma once
#include <chrono>
#include <ctime>
#include "Commodity.h"
/*
* 订单类
*/
class Order
{
private:

	int id; //订单id
	int clientId; //客户id
	Commodity goods; //订单中的商品
	int count; //订单数量
	std::chrono::system_clock::time_point createTime; //订单的创建时间




public:

	Order() = default;

    Order(int orderId, int clientID, const Commodity& orderGoods, int orderCount, const std::chrono::system_clock::time_point& orderCreateTime)
        : id(orderId), clientId(clientID), goods(orderGoods), count(orderCount), createTime(orderCreateTime) {}

    int getId() const { return id; }

    void setId(int newId) { id = newId; }

    int getClientId() const { return clientId; }

    void setClientId(int newClientId) { clientId = newClientId; }

    Commodity getGoods() const { return goods; }

    void setGoods(const Commodity& newGoods) { goods = newGoods; }

    int getCount() const { return count; }

    void setCount(int newCount) { count = newCount; }

    std::chrono::system_clock::time_point getCreateTime() const { return createTime; }

    void setCreateTime(const std::chrono::system_clock::time_point& newCreateTime) { createTime = newCreateTime; }

    string toString() {
        return "Order ID: " + to_string(id) + "\n" +
            "Client ID: " + to_string(clientId) + "\n" +
            "Goods: \n" + goods.toString() + "\n" +
            "Count: " + to_string(count) + "\n" +
            "Create Time: " + to_string(std::chrono::system_clock::to_time_t(createTime));
    }

};

