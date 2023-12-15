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

    static Commodity fromString(const string& data) {
        istringstream iss(data);
        string idStr, name, typeStr, priceStr, quantityStr, supplierIdStr;
        getline(iss, idStr, ' ');
        getline(iss, name, ' ');
        getline(iss, typeStr, ' ');
        getline(iss, priceStr, ' ');
        getline(iss, quantityStr, ' ');
        getline(iss, supplierIdStr, ' ');

        // �Ƴ�ð��
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

        // �������ַ���ת��������
        int type;
        if (typeStr == "ʳƷ") {
            type = 1;
        }
        else if (typeStr == "�·�") {
            type = 2;
        }
        else if (typeStr == "����") {
            type = 3;
        }
        else if (typeStr == "�鼮") {
            type = 4;
        }
        else {
            type = 0; // δ֪����
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

    // �������ID���ļ�
    static void updateMaxId();
};



