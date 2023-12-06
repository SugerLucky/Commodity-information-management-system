#pragma once
#include <string>
using namespace std;
/*
* ¹©Ó¦ÉÌ
*/
class Supplier {
private:
    int id;
    string name;
    string phone;

public:
    Supplier() = default;

    Supplier(int id, const string& name, const string& phone)
        : id(id), name(name), phone(phone)
    {
    }

    int getId() const {
        return id;
    }

    void set(int id) {
        this->id = id;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    string getPhone() const {
        return phone;
    }

    void setPhone(string phone) {
        this->phone = phone;
    }
};

