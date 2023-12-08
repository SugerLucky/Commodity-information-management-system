#pragma once
#include <string>
using namespace std;
/*
* 商品类
*/
class Commodity {
private:
    int id;
    int type; //1.食品 2.衣服 3.数码 4.书籍
    double price;
    int quantity;
    int supplierId;

public:

    Commodity() = default;

    Commodity(int id, int type, double price, int quantity, int supplier_id)
        : id(id), type(type), price(price), quantity(quantity), supplierId(supplierId)
    {
    }

    int getId() const {
        return id;
    }

    void setId(int i) {
        id = i;
    }

    int getType() const {
        return type;
    }

    void setType(int t) {
        type = t;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double p) {
        price = p;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    int getSupplierId() const {
        return supplierId;
    }

    void setSupplierId(int si) {
        supplierId = si;
    }


};

