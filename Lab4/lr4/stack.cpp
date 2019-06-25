// ---------------------------------------------------------------------------

#pragma hdrstop
#include <vcl.h>
#include "stack.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

template<typename T>
Stack<T>::Stack(int i) {
	size = i;
}

template<typename T>
void Stack<T>::Push(T x) {

	data[size] = x;
	size++;
}

template<typename T>
T Stack<T>::Pop() {

	size--;
	return data[size];
}

template<typename T>
T Stack<T>::Top() {

	return data[size - 1];
}
