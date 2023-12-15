#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
/*
* 商品类
*/
class Commodity {
private:
    int id;

    static int nextId;

    string name;
    int type; //1.食品 2.衣服 3.数码 4.书籍
    double price;
    int quantity;
    int supplierId;

public:

    Commodity() = default;

    Commodity(int id, const string& name, int type, double price, int quantity, int supplierId)
        : id(id), name(name), type(type), price(price), quantity(quantity), supplierId(supplierId)
    {
    }



    int getId() const { return id; }

    void setId(int newId) { id = newId; }

    string getName() const { return name; }

    void setName(const string& newName) { name = newName; }

    int getType() const { return type; }

    void setType(int newType) { type = newType; }

    double getPrice() const { return price; }

    void setPrice(double newPrice) { price = newPrice; }

    int getQuantity() const { return quantity; }

    void setQuantity(int newQuantity) { quantity = newQuantity; }

    int getSupplierId() const { return supplierId; }

    void setSupplierId(int newSupplierId) { supplierId = newSupplierId; }

    string toString() const {
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

        return "ID: " + to_string(id) + " " +
            "Name: " + name + " " +
            "Type: " + typeStr + " " +
            "Price: " + to_string(price) + " " +
            "Quantity: " + to_string(quantity) + " " +
            "Supplier ID: " + to_string(supplierId);
    }

    static Commodity fromString(const string& data) {
        istringstream iss(data);
        string idStr, name, typeStr, priceStr, quantityStr, supplierIdStr;
        getline(iss, idStr, ' ');
        getline(iss, name, ' ');
        getline(iss, typeStr, ' ');
        getline(iss, priceStr, ' ');
        getline(iss, quantityStr, ' ');
        getline(iss, supplierIdStr, ' ');

        // 移除冒号
        idStr.erase(0, 4);
        name.erase(0, 5);
        typeStr.erase(0, 5);
        priceStr.erase(0, 6);
        quantityStr.erase(0, 9);
        supplierIdStr.erase(0, 13);

        int id = stoi(idStr);
        double price = stod(priceStr);
        int quantity = stoi(quantityStr);
        int supplierId = stoi(supplierIdStr);

        // 将类型字符串转换回整数
        int type;
        if (typeStr == "食品") {
            type = 1;
        }
        else if (typeStr == "衣服") {
            type = 2;
        }
        else if (typeStr == "数码") {
            type = 3;
        }
        else if (typeStr == "书籍") {
            type = 4;
        }
        else {
            type = 0; // 未知类型
        }

        return Commodity(id, name, type, price, quantity, supplierId);
    }


    bool operator==(const Commodity& other) const
    {
        return id == other.id && type == other.type && price == other.price && quantity == other.quantity && supplierId == other.supplierId;
    }

    static string getFileName() { return "commodities.txt"; }

    static string getMaxIdFileName() { return "max_commodity_id.txt"; }

    static int getNextId();
        


    static void loadMaxId();

    // 更新最大ID到文件
    static void updateMaxId();
};



