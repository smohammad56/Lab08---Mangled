#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	cursor = nullptr;
	size = 0;
}

template <class T>
void LinkedList<T>::AddItem(int sku, std::string des, double price, std::string uom, int qoh) {
	if (IsEmpty()) {
		head = new Part(sku, des, price, uom, qoh);
	}
	else {
		Part* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new Part(sku, des, price, uom, qoh);
	}
	size++;
}

// returns a pointer to the removed value from list
template <class T>
Part* LinkedList<T>::GetItem(int sku) {
	if (IsEmpty()) {
		return nullptr;
	}
	else {
		Part* temp = head;
		while (temp->next != nullptr && temp->GetSKU() != sku) {
			temp = temp->next;
		}
		if (temp->GetSKU() == sku)
		{
			//T* retval = temp->data; //Salma: I changed T to T* so it returns a pointer to the value of the removed node
			Part* removed = temp;
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}
			temp->prev->next = temp->next;
			delete temp;
			size--;
			return removed;
		}
		else {
			return nullptr;
		}
	}
}

template <class T>
bool LinkedList<T>::IsInList(int sku) {
	if (IsEmpty()) {
		return false;
	}
	else {
		Part* temp = head;
		while (temp->next != nullptr && temp->GetSKU() != sku) {
			temp = temp->next;
		}
		if (temp->GetSKU() == sku)
		{
			return true;
		}
		else {
			return false;
		}
	}
}

template <class T>
Part* LinkedList<T>::SeeNext() {
	if (IsEmpty()) {
		return nullptr;
	}
	else {
		if (cursor == nullptr) {
			cursor = head;
		}
		else {
			cursor = cursor->next;
		}
		return cursor;
	}
}

template <class T>
Part* LinkedList<T>::SeePrev() {
	if (IsEmpty()) {
		return nullptr;
	}
	else {
		if (cursor == nullptr) {
			cursor = head;
		}
		else {
			cursor = cursor->prev;
		}
		return cursor;
	}
}

template <class T>
Part* LinkedList<T>::SeeAt(int index) {
	if (IsEmpty()) {
		return nullptr;
	}
	else {
		int i = 0;
		Part* temp = head;
		while (temp->next != nullptr && i < index) {
			temp = temp->next;
			i++;
		}
		if (i == index)
		{
			cursor = temp;
			return temp;
		}
		else {
			return nullptr;
		}
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	if (!IsEmpty()) {
		Part* temp = head;
		while (temp != nullptr) {
			temp = temp->next;
			delete temp->prev;
		}
		delete temp;
	}
}
