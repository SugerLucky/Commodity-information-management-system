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

