#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <nlohmann/json.hpp>
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

    Commodity();

    Commodity(int id, const string& name, int type, double price, int quantity, int supplierId);

    int getId() const;

    void setId(int newId);

    string getName() const;

    void setName(const string& newName);

    int getType() const;

    void setType(int newType);

    double getPrice() const;

    void setPrice(double newPrice);

    int getQuantity() const;

    void setQuantity(int newQuantity);

    int getSupplierId() const;

    void setSupplierId(int newSupplierId);

    string toString() const;

    void serialize(nlohmann::json& j) const;

    void deserialize(const nlohmann::json& j);
        
    bool operator==(const Commodity& other) const;
    
    static string getFileName();

    static string getMaxIdFileName();

    static int getNextId();
        
    static void loadMaxId();

    static void updateMaxId(); // �������ID���ļ�
};



