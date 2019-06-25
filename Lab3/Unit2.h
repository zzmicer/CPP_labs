// ---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
#include <StdCtrls.hpp>
// ---------------------------------------------------------------------------

class Storage {

private:
	int number, price;
	String name;

public:

	void set_number(int number) {
		this->number = number;
	}

	int get_number() {
		return number;
	}

	void set_price(int price) {
		this->price = price;
	}

	int get_price() {
		return price;
	}

	void set_name(String name) {
		this->name = name;
	}

	String get_name() {
		return name;
	}
};

class List {
public:
	List();
	~List();

private:
	class Node {
	public:
		Node *pNext;
		Storage data;

		Node(Storage data = Storage(), Node *pNext = NULL) {
			this->data = data;
			this->pNext = pNext;
		}
	};

public:
	Node *head;
	int size;

	void push_back(Storage *data);
	void pop_front();
	void pop_index(int index);
	void clear();

	int get_size() {
		return size;
	}
	Storage &operator[](const int index);
};

class MyException : public Exception{
	public:
	MyException(String msg):Exception(msg){
	}
};
#endif
