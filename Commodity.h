#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
/*
* ��Ʒ��
*/
class Commodity {
private:
    int id;

    static int nextId;

    string name;
    int type; //1.ʳƷ 2.�·� 3.���� 4.�鼮
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
            typeStr = "ʳƷ";
            break;
        case 2:
            typeStr = "�·�";
            break;
        case 3:
            typeStr = "����";
            break;
        case 4:
            typeStr = "�鼮";
            break;
        default:
            typeStr = "δ֪����";
            break;
        }

        return "ID: " + to_string(id) + " " +
            "Name: " + name + " " +
            "Type: " + typeStr + " " +
            "Price: " + to_string(price) + " " +
            "Quantity: " + to_string(quantity) + " " +
            "Supplier ID: " + to_string(supplierId);
    }


    bool operator==(const Commodity& other) const
    {
        return id == other.id && type == other.type && price == other.price && quantity == other.quantity && supplierId == other.supplierId;
    }

    static string getFileName() { return "commodities.txt"; }

    static string getMaxIdFileName() { return "max_commodity_id.txt"; }

    static int getNextId();
        


    static void loadMaxId();

    // �������ID���ļ�
    static void updateMaxId();
};



