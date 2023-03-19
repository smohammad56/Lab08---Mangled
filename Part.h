#pragma once
#pragma once
#include <string>


class Part {
private:
	int SKU = 0;
	std::string Description;
	double Price = 0;
	std::string UOM;
	int QuantityOnHand = 0;
	int LeadTime = 0;
public:
	Part* next = nullptr;
	Part* prev = nullptr;
	Part(int sku, std::string des, double price, std::string uom, int qoh = 0);
	//std::string GetPartInfo();
	int GetSKU() { return SKU; };
	double GetPrice() { return Price; };
	bool InStock() { return QuantityOnHand > 0; };
	//bool Available(int month, int date, int year);
	void setLeadTime(int time) { LeadTime = time; };
	bool operator==(const Part& other) { return SKU == other.SKU; };
	bool operator>(const Part& other) { return SKU > other.SKU; };
	bool operator<(const Part& other) { return SKU < other.SKU; };
};