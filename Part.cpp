#include "Part.h"
#include <string>
#include <chrono>
#include <ctime>
#include <iostream>

//constructor
Part::Part(int sku, std::string des, double price, std::string uom, int qoh) {
	SKU = sku;
	Description = des;
	Price = price;
	UOM = uom;
	QuantityOnHand = qoh;
}

/*std::string Part::GetPartInfo() {
	std::string returnString = "SKU: " + std::to_string(SKU) + ". " + "Description: " + Description;
	return returnString;
}*/

/*bool Part::Available(int month, int date, int year) {
	//check if quantity on hand is > 0
	if (QuantityOnHand > 0) {
		return true;
	}
	auto now = std::chrono::system_clock::now();
	//create a tm object to hold desiredDate and set values to the members of the object
	struct tm desiredDate;
	desiredDate.tm_year = year - 1900;
	desiredDate.tm_mon = month - 1;
	desiredDate.tm_mday = date;
	desiredDate.tm_hour = 0;
	desiredDate.tm_min = 0;
	desiredDate.tm_sec = 0;

	//convert to Unix timestamp
	std::time_t UnixTimestamp = std::mktime(&desiredDate);

	std::chrono::system_clock::time_point desiredDate_c = std::chrono::system_clock::from_time_t(UnixTimestamp);

	//calculate number of days from the current date to the desired date
	auto days = std::chrono::duration_cast<std::chrono::hours>(desiredDate_c - now).count() / 24;
	return days >= LeadTime;
}*/