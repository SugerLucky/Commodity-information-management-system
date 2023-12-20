#pragma once
#include <chrono>
#include <ctime>
#include "Commodity.h"
#include <fstream>
#include <nlohmann/json.hpp>
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

    Order();

    Order(int orderId, string clientName, const Commodity& orderGoods, int orderCount, const std::chrono::system_clock::time_point& orderCreateTime);

    int getId() const;

    void setId(int newId);

    string getClientName() const;

    void setClientName(string newClientName);

    Commodity getGoods() const;

    void setGoods(const Commodity& newGoods);

    int getCount() const;

    void setCount(int newCount);

    std::chrono::system_clock::time_point getCreateTime() const;

    void setCreateTime(const std::chrono::system_clock::time_point& newCreateTime);

    string toString() const;

    void serialize(nlohmann::json& j) const;

    void deserialize(const nlohmann::json& j);

    static string getFileName();

    static string getMaxIdFileName();

    static int getNextId();

    static void loadMaxId();

    static void updateMaxId();

};

