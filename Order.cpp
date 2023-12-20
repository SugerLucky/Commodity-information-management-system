#include "Order.h"

int Order::nextId = Order::getNextId();

Order::Order() = default;

Order::Order(int orderId, string clientName, const Commodity& orderGoods, int orderCount, const std::chrono::system_clock::time_point& orderCreateTime)
    : id(orderId), clientName(clientName), goods(orderGoods), count(orderCount), createTime(orderCreateTime) {}

int Order::getId() const { return id; }

void Order::setId(int newId) { id = newId; }

string Order::getClientName() const { return clientName; }

void Order::setClientName(string newClientName) { clientName = newClientName; }

Commodity Order::getGoods() const { return goods; }

void Order::setGoods(const Commodity& newGoods) { goods = newGoods; }

int Order::getCount() const { return count; }

void Order::setCount(int newCount) { count = newCount; }

std::chrono::system_clock::time_point Order::getCreateTime() const { return createTime; }

void Order::setCreateTime(const std::chrono::system_clock::time_point& newCreateTime) { createTime = newCreateTime; }

string Order::toString() const {
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

void Order::serialize(nlohmann::json& j) const {
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

void Order::deserialize(const nlohmann::json& j) {
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

string Order::getFileName() { return "orders.json"; }

string Order::getMaxIdFileName() { return "max_order_id.txt"; }

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