#pragma once
#include <string>
using namespace std;
/*
* ��Ʒ��
*/
class Commodity {
private:
    int id;
    int type; //1.ʳƷ 2.�·� 3.���� 4.�鼮�����ݴ�����ٺ;����˵����Ӧ
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

        return "ID: " + to_string(id) + "\n" +
            "Type: " + typeStr + "\n" +
            "Price: " + to_string(price) + "\n" +
            "Quantity: " + to_string(quantity) + "\n" +
            "Supplier ID: " + to_string(supplierId);
    }

};

