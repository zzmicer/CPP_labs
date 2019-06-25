// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"

List::List() {
	size = 0;
	head = NULL;
}

List::~List() {
	clear();
}

void List::push_back(Storage *data) {
	if (head == NULL)
		head = new Node(*data);
	else {
		Node *current = this->head;
		while (current->pNext != NULL) {
			current = current->pNext;
		}

		current->pNext = new Node(*data);
	}
	size++;
}

void List::clear() {
	while (size)
		this->pop_front();

}

void List::pop_front() {
	Node *temp = this->head;
	head = head->pNext;
	delete temp;
	size--;

}

void List::pop_index(int index) {

	if (index == 0)
		this->pop_front();
	else {
		Node *previous = this->head;

		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

Storage &List:: operator[](const int index) {
	int counter = 0;
	Node *current = this->head;

	while (current != NULL) {
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}

}

// ---------------------------------------------------------------------------
#pragma package(smart_init)
