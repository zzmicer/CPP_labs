//---------------------------------------------------------------------------

#ifndef ClassH
#define ClassH
//---------------------------------------------------------------------------
#endif
#include <iostream>
using namespace std;

class Node {
	public:
	wchar_t simbol;
	Node *Next;
	Node(){}
	Node(wchar_t data) {
		simbol = data;
		Next = NULL;
	}
};

class List {
	public:
	int size;
	Node *head;
	Node *tail;
	List(){
		size = 0;
		head = NULL;
		tail = NULL;
	}
	void Add(Node *node){
		if (size == 0) {
			head = node;
			tail = node;
		}
		else{
			tail->Next = node;
			tail = node;
		}
		size++;
	}
	int GetSize() {
		return size;
	}
	~List(){}
};

class Calculation {
	private:
		wchar_t* infixStr;
		wchar_t stack[100];
		List *list;
		int size;
		int number_in_stack;
	public:
		Calculation ();
		Calculation (wchar_t *str);
		wchar_t* postfixStr;
		wchar_t* TransletadeToInfix;
		bool modif;
		float result;
		void push(wchar_t simb);
		wchar_t pop();
		wchar_t last_in_stack();
		void Transformation();
		void calculate(wchar_t *str);
		void decoding(wchar_t *str);
};




