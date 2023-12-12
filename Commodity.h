#pragma once
#include <string>
using namespace std;
/*
* 商品类
*/
class Commodity {
private:
    int id;
    int type; //1.食品 2.衣服 3.数码 4.书籍，数据处理层再和具体的说明对应
    double price;
    int quantity;
    int supplierId;

public:

    Commodity() = default;

    Commodity(int id, int type, double price, int quantity, int supplierId)
        : id(id), type(type), price(price), quantity(quantity), supplierId(supplierId)
    {
    }

    int getId() const { return id; }

    void setId(int newId) { id = newId; }

    int getType() const { return type; }

    void setType(int newType) { type = newType; }

    double getPrice() const { return price; }

    void setPrice(double newPrice) { price = newPrice; }

    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }

    int getSupplierId() const { return supplierId; }

    void setSupplierId(int newSupplierId) { supplierId = newSupplierId; }

    string toString() {
        string typeStr;
        switch (type) {
        case 1:
            typeStr = "食品";
            break;
        case 2:
            typeStr = "衣服";
            break;
        case 3:
            typeStr = "数码";
            break;
        case 4:
            typeStr = "书籍";
            break;
        default:
            typeStr = "未知类型";
            break;
        }

        return "ID: " + to_string(id) + "\n" +
            "Type: " + typeStr + "\n" +
            "Price: " + to_string(price) + "\n" +
            "Quantity: " + to_string(quantity) + "\n" +
            "Supplier ID: " + to_string(supplierId);
    }

};

