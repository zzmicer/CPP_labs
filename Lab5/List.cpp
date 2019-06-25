// ---------------------------------------------------------------------------

#pragma hdrstop

#include "List.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

List::List() {
	size = 0;
	head = NULL;
}

List::~List() {
	clear();
}

void List::push_back(int data) {
	Node *temp = new Node(data, size, head, tail);
	size++;

	if (head != NULL) {
		tail->pNext = temp;
		head->pPrev = temp;
		tail = temp;

	}
	else {
		head = tail = temp;
	}

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
		toDelete->pNext->pPrev = previous;
		delete toDelete;
		size--;
	}

	Node *current = this->head;
	for (int i = 0; i < size; i++) {
		current->num = i;
		current = current->pNext;
	}
}

void List::push_index(int index, int data) {

	Node *previous = this->head;

	for (int i = 0; i < index - 1; i++) {
		previous = previous->pNext;
	}

	Node *newNode = new Node(data, 0, previous->pNext, previous);
	previous->pNext->pPrev = newNode;
	previous->pNext = newNode;
	size++;

	Node *current = this->head;
	for (int i = 0; i < size; i++) {
		current->num = i;
		current = current->pNext;
	}
}

int &List:: operator[](const int index) {
	int counter = 0;
	Node *current = this->head;

	while (current != NULL) {
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}

}
