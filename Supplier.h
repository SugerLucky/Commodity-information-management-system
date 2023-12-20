#pragma once
#include <string>
using namespace std;
/*
* π©”¶…Ã
*/
class Supplier {
private:
    int id;
    string name;
    string phone;

public:
    Supplier();

    Supplier(int id, const string& name, const string& phone);
        
    int getId() const;

    void set(int id);

    string getName() const;

    void setName(string name);

    string getPhone() const;

    void setPhone(string phone);
};

