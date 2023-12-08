#pragma once
class Order
{
private:
	//class DateTime {
	//	int year;
	//	int month;
	//	int day;
	//	int hour;
	//	int minute;

	//};

	int id;
	int clientId;
	int commodityId;
	int count;



public:

	Order() = default;

	Order(int id, int clientId, int commodityId, int count)
		: id(id), clientId(clientId), commodityId(commodityId), count(count)
	{
	}

	int getId() const {
		return id;
	}

	void setId(int i) {
		id = i;
	}

	int getClientId() const {
		return clientId;
	}

	void setClientId(int ci) {
		clientId = ci;
	}

	int getCommodityId() const {
		return commodityId;
	}

	void setCommodityId(int ci) {
		clientId = ci;
	}

	int getCount() const {
		return count;
	}

	void setCount(int c) {
		count = c;
	}

};

