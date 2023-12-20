#include "Supplier.h"

Supplier::Supplier() = default;

Supplier::Supplier(int id, const string& name, const string& phone)
    : id(id), name(name), phone(phone)
{
}

int Supplier::getId() const {
    return id;
}

void Supplier::set(int id) {
    this->id = id;
}

string Supplier::getName() const {
    return name;
}

void Supplier::setName(string name) {
    this->name = name;
}

string Supplier::getPhone() const {
    return phone;
}

void Supplier::setPhone(string phone) {
    this->phone = phone;
}
