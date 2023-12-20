#pragma once
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#include <nlohmann/json.hpp>
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

    static void updateMaxId(); // 更新最大ID到文件
};



