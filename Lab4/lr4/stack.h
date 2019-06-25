//---------------------------------------------------------------------------

#ifndef stackH
#define stackH
//---------------------------------------------------------------------------
template <typename T>
class Stack
{
	public:
		T data[100];
		int size;
		Stack(int i);
		void Push(T x);
		T Pop();
		T Top();
};
#endif






























/*
void Stack::Push(char operand) {
	Node *current;
	current = new Node(operand);
	if (head == NULL) {
		head = current;
	}
	else {
		current->next = head;
		head = current;
	}

}

char Stack::Pop() {
	Node *current = head;
	head = current->next;
	char s = current->operand;
	delete current;
	return s;

}
char Stack::Top() {
	Node *current = head;
	char s = current->operand;
	return s;
}
*/
