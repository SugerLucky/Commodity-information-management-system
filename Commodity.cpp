#include "Commodity.h"

int Commodity::nextId = Commodity::getNextId();

Commodity::Commodity() = default;

Commodity::Commodity(int id, const string& name, int type, double price, int quantity, int supplierId)
    : id(id), name(name), type(type), price(price), quantity(quantity), supplierId(supplierId)
{
}


int Commodity::getId() const { return id; }

void Commodity::setId(int newId) { id = newId; }

string Commodity::getName() const { return name; }

void Commodity::setName(const string& newName) { name = newName; }

int Commodity::getType() const { return type; }

void Commodity::setType(int newType) { type = newType; }

double Commodity::getPrice() const { return price; }

void Commodity::setPrice(double newPrice) { price = newPrice; }

int Commodity::getQuantity() const { return quantity; }

void Commodity::setQuantity(int newQuantity) { quantity = newQuantity; }

int Commodity::getSupplierId() const { return supplierId; }

void Commodity::setSupplierId(int newSupplierId) { supplierId = newSupplierId; }

string Commodity::toString() const {
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


void Commodity::serialize(nlohmann::json& j) const {
    j = {
        {"ID", id},
        {"Name", name},
        {"Type", type},
        {"Price", price},
        {"Quantity", quantity},
        {"SupplierID", supplierId}
    };
}

void Commodity::deserialize(const nlohmann::json& j) {
    id = j["ID"];
    name = j["Name"];
    type = j["Type"];
    price = j["Price"];
    quantity = j["Quantity"];
    supplierId = j["SupplierID"];
}

bool Commodity::operator==(const Commodity& other) const
{
    return id == other.id && type == other.type && price == other.price && quantity == other.quantity && supplierId == other.supplierId;
}

string Commodity::getFileName() { return "commodities.json"; }

string Commodity::getMaxIdFileName() { return "max_commodity_id.txt"; }

// ��ȡ��һ��ID
int Commodity::getNextId() {
    return ++nextId;
}

//����ÿһ������ʱ�����ļ��м������ID
void Commodity::loadMaxId() {
    std::ifstream file(getMaxIdFileName());
    if (file.is_open()) {
        file >> nextId;
        file.close();
    }
}

// �������ID���ļ�----Ӧ���ǳ���ر�ʱ�������¸�idд���ļ�
void Commodity::updateMaxId() {
    std::ofstream file(getMaxIdFileName());
    if (file.is_open()) {
        file << nextId;
        file.close();
    }
}