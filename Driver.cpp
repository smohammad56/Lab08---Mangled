#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include "Part.h"
#include "Part.cpp"
#include <string>
#include <stdio.h>
using namespace std;



//void displaySKU(LinkedList<Part>* lis);

int main() {

	int user_input;

	std::cout << "We are testing the Ordered Double Linked List Class. Please select an option: " << endl;
	//std::cout << "(1) To run the constructor LinkedList()." << endl;
	std::cout << "(2) To add an item to the list." << endl;
	std::cout << "(3) To search for AND return the item in the list." << endl;
	std::cout << "(4) To see if the item is in the list (returns T/F)." << endl;
	std::cout << "(5) To see if the list is empty (returns T/F)" << endl;
	std::cout << "(6) To return the number of items in the list." << endl;
	std::cout << "(7) To see the next item in the list from your given location." << endl;
	std::cout << "(8) To see the prior item in the list from your given location." << endl;
	std::cout << "(9) Finds an item at a given location in the list." << endl;
	std::cout << "(10) To reset cursor to the first node of the list." << endl;
	std::cout << "(11) To remove all items in the list." << endl;
	std::cout << "(12) To display the contents of the class." << endl; //task 4
	std::cout << "(0) To exit program. " << endl;
	std::cin >> user_input;

	//declare variables necessary to add an item
	int SKU;
	string description;
	double price;
	string UOM;
	int quantity;
	int index;


	do {
		//creates an instance pointing to items class
		LinkedList<Part>* list = new LinkedList<Part>();
		std::cout << "An instance has been created.";

		//runs additem function
		if (user_input == 2)
		{
			std::cout << "Enter the necessary information to add an item." << endl;
			std::cout << "Input an integer for SKU: " << endl;
			std::cin >> SKU;
			std::cout << "Input a string for a Description: " << endl;
			std::cin >> description;
			std::cout << "Input a double for Price: " << endl;
			std::cin >> price;
			std::cout << "Input a string for the Unit of Measurement: " << endl;
			std::cin >> UOM;

			char tf;
			std::cout << "Do you have an integer for quantity? Enter T for true or F for false. " << endl;
			std::cin >> tf;

			if (tf == 'T' || tf == 't') {
				cout << "Input an integer for Quantity: " << endl;
				cin >> quantity;
			}
			else {
				quantity = 0;
			}

			list->AddItem(SKU, description, price, UOM, quantity);
			std::cout << "The item has been succcessfully added to the list." << endl;
			break;

		}

		//search and return item from list
		if (user_input == 3) {
			std::cout << "Enter the SKU of the item you would like to search and return: " << endl;
			std::cin >> SKU;
			/*Part* inst1 = list->data;
			Part* inst2 = list->GetItem(inst1);//searchAndReturn(SKU, list));*/
			Part* inst1 = list->GetItem(SKU);
			std::cout << "The item returned is: " << inst1 << endl;
			//should I handle if SKU is not found ? adding try/catch? 
		}

		if (user_input == 4) {
			std::cout << "Type in the SKU of the item you want to check: " << endl;
			cin >> SKU;
			bool tf = list->IsInList(SKU);
			if (tf) {
				cout << "True: the item is in the list." << endl;
			}
			else {
				cout << "False: the item is not in the list." << endl;
			}
			break;
		}


		if (user_input == 5) {
			if (list->IsEmpty()) {
				std::cout << "The list is empty.";
			}
			else
			{
				std::cout << "The list is NOT empty.";
			}
			break;
		}

		if (user_input == 6) {
			std::cout << "The size of the list is: " << list->Size() << endl;
			break;
		}

		if (user_input == 7) {
			std::cout << "The next item in the list is: " << list->SeeNext();
			break;
		}

		if (user_input == 8) {
			std::cout << "The last item in the list is: " << list->SeePrev();
			break;
		}

		//item at a given location
		if (user_input == 9) {
			std::cout << "Type in the index of the item you want to check: " << endl;
			std::cin >> index;
			std::cout << "The item at that index is: " << list->SeeAt(index) << endl;

			if (list->SeeAt(index) == nullptr) {
				std::cout << "This is an invalid index.";
			}
		}

		if (user_input == 10) {
			list->Reset();
			std::cout << "You have reset the cursor to the beginning of the list." << endl;
			break;
		}

		//delete contents of the list
		if (user_input == 11) {
			list->~LinkedList();
		}

		if (user_input == 12) {
			std::cout << "The contents of the class are: " << endl;
			//std::cout << displaySKU(list); //need to write Display method
		}



	} while (user_input != 0);

}

/*
void displaySKU(LinkedList<Part>* lis) {
	std::string sku;
	for (int i = 0; i < lis->Size(); i++) {
		sku = lis->SeeNext()->GetPartInfo();
		cout << sku << endl;
	}
	lis->Reset();
}*/