#pragma once
#include <string>
using namespace std;
/*
* …Ã∆∑¿‡
*/
class Commodity {
private:
    int id;
    string type;
    double price;
    int quantity;
    int supplier_id;

public:

    Commodity() = default;

    Commodity(int id, const string& type, double price, int quantity, int supplier_id)
        : id(id), type(type), price(price), quantity(quantity), supplier_id(supplier_id)
    {
    }


};

