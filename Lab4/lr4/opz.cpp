// ---------------------------------------------------------------------------

#pragma hdrstop

#include "opz.h"
#include "stack.cpp"
// ---------------------------------------------------------------------------

 Stack<float>numStack(0);
 Stack<char>opStack(0);

bool delim(char c) {
	return c == ' ';
}

bool is_op(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int priority(char op) {
	return op == '+' || op == '-' ? 1 : op == '*' || op == '/' ||
		op == '%' ? 2 : -1;
}

void process_op(Stack<float>st(0), char op) {
	int r = st.Show();
	st.Pop();
	int l = st.Show();
	st.Pop();
	switch (op) {
	case '+':
		st.Push(l + r);
		break;
	case '-':
		st.Push(l - r);
		break;
	case '*':
		st.Push(l * r);
		break;
	case '/':
		st.Push(l / r);
		break;
	case '%':
		st.Push(l % r);
		break;
	}
}

string toOPZ(string str) {

}