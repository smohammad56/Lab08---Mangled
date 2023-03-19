#pragma once
#include "Part.h"

template <class T>
class LinkedList {
private:
	Part* head = nullptr;
	Part* cursor = nullptr;
	int size = 0;

public:
	LinkedList();
	void AddItem(int sku, std::string des, double price, std::string uom, int qoh);
	Part* GetItem(int sku);
	bool IsInList(int sku);
	bool IsEmpty() { return size == 0; }
	int Size() { return size; }
	Part* SeeNext();
	Part* SeePrev();
	Part* SeeAt(int index);
	void Reset() { cursor = head; }
	~LinkedList();
};