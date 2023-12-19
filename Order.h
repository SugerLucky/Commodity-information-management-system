#pragma once
#include <chrono>
#include <ctime>
#include "Commodity.h"
#include <fstream>
#include <nlohmann/json.hpp>
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

    string getClientName() const { return clientName; }

    void setClientName(string newClientName) { clientName = newClientName; }

    Commodity getGoods() const { return goods; }

    void setGoods(const Commodity& newGoods) { goods = newGoods; }

    int getCount() const { return count; }

    void setCount(int newCount) { count = newCount; }

    std::chrono::system_clock::time_point getCreateTime() const { return createTime; }

    void setCreateTime(const std::chrono::system_clock::time_point& newCreateTime) { createTime = newCreateTime; }

    string toString() const {
        std::time_t time = std::chrono::system_clock::to_time_t(createTime);
        std::tm tm;
        localtime_s(&tm, &time);
        char buffer[80];
        strftime(buffer, 80, "%c", &tm);
        return "Order ID: " + to_string(id) + " " +
            "Client Name: " + clientName + " " +
            "Goods:  " + goods.toString() + " " +
            "Count: " + to_string(count) + " " +
            "Create Time: " + string(buffer);
    }

    void serialize(nlohmann::json& j) const
    {
        j = {
            {"ID", id},
            {"ClientName", clientName},
            {"Goods", {
                {"ID", goods.getId()},
                {"Name", goods.getName()},
                {"Type", goods.getType()},
                {"Price", goods.getPrice()},
                {"Quantity", goods.getQuantity()},
                {"SupplierID", goods.getSupplierId()}
            }},
            {"Count", count},
            {"CreateTime", std::chrono::system_clock::to_time_t(createTime)}
        };
    }

    void deserialize(const nlohmann::json& j)
    {
        id = j["ID"];
        clientName = j["ClientName"];
        const nlohmann::json& goodsJson = j["Goods"];
        goods.setId(goodsJson["ID"]);
        goods.setName(goodsJson["Name"]);
        goods.setType(goodsJson["Type"]);
        goods.setPrice(goodsJson["Price"]);
        goods.setQuantity(goodsJson["Quantity"]);
        goods.setSupplierId(goodsJson["SupplierID"]);
        count = j["Count"];
        createTime = std::chrono::system_clock::from_time_t(j["CreateTime"]);
    }

    static string getFileName() { return "orders.json"; }


    static string getMaxIdFileName() { return "max_order_id.txt"; }

    static int getNextId();

    static void loadMaxId();

    static void updateMaxId();

};

