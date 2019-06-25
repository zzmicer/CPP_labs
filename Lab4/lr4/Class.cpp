//---------------------------------------------------------------------------


#pragma hdrstop

#include "Class.h"
#include <cwchar>
//---------------------------------------------------------------------------

#pragma package(smart_init)


Calculation :: Calculation (){
	list = new List();
}

Calculation :: Calculation (wchar_t *str){
	number_in_stack = 0;
	int i = 0;
	while(i <= 100){
		stack[i++] = ' ';
	}
	size = wcslen(str);
	infixStr = new wchar_t[size];
	postfixStr = new wchar_t[size];
	list = new List();
	for (int i = 0; i <= size; i++) {
		infixStr[i] = str[i];
	}
		
}

void Calculation :: push(wchar_t simb) {
	Node *temp = new Node();
	temp->simbol = simb;
	list->Add(temp);
}

wchar_t Calculation :: pop(){
	wchar_t temporal;
	temporal = list->tail->simbol;
	if (list->head == list->tail) {
		temporal = list->head->simbol;
		list->head = list->tail = NULL;
		list->size--;
		return temporal;
	}
	else if (list->head != NULL) {
		Node *temp = list->head;
		while (temp->Next != list->tail) {
			temp = temp->Next;
		}
		temp->Next = NULL;
		list->tail = temp;
		list->size--;
		return temporal;
	}
}

wchar_t Calculation :: last_in_stack(){
	if (list->tail != NULL) {
		return list->tail->simbol;
	}
}


void Calculation :: Transformation() {
	int in_number = 0, out_number = 0;
	do {
		wchar_t c = infixStr[in_number];
		switch (c) {
			case '+': {
				while (last_in_stack() == '+' || last_in_stack() == '-' || last_in_stack() == '*' || last_in_stack() == '/' || last_in_stack() == '^'){
					postfixStr[out_number++] = pop();
				}
				push(c);
				in_number++;
			} break;
			case '-': {
				while (last_in_stack() == '+' || last_in_stack() == '-' || last_in_stack() == '*' || last_in_stack() == '/' || last_in_stack() == '^'){
					postfixStr[out_number++] = pop();
				}
				push(c);
				in_number++;
			} break;
			case '*': {
				while (last_in_stack() == '/' || last_in_stack() == '*' || last_in_stack() == '^'){
					postfixStr[out_number++] = pop();
				}
				push(c);
				in_number++;
			} break;
			case '/': {
				while (last_in_stack() == '/' || last_in_stack() == '*' || last_in_stack() == '^'){
					postfixStr[out_number++] = pop();
				}
				push(c);
				in_number++;
			} break;
			case '(': {
				push(c);
				in_number++;
			} break;
			case ')': {
				while(last_in_stack() != '(') {
					postfixStr[out_number++] = pop();
				}
				char sinb = pop();
				in_number++;
			} break;
			case '^': {
				while (last_in_stack() == '^') {
                 	postfixStr[out_number++] = pop();
                }
            	push(c);
				in_number++;
            } break;
		default: {
				postfixStr[out_number++] = c;
				in_number++;
			} break;
		}
	} while(infixStr[in_number] != '\0');

	while(list->head != NULL) {
		postfixStr[out_number++] = pop();
	}
	postfixStr[out_number] = '\0';
}

void Calculation :: calculate(wchar_t *str) {
	float output[100];
	int top = -1;
	wchar_t temp[20];
	int k, l, i;
	modif = true;
	for (k = 0, top = -1; k < wcslen(str); k++) {
		if (((int)str[k] >= 97 && (int)str[k] <= 122) || ((int)str[k] >= 65 && (int)str[k] <= 90)) {
			modif = false;
			return;
		}
		if (iswdigit(str[k]) != 0) {
			l = k;
			while (iswdigit(str[l+1]) != 0 || str[l+1] == '.') {
				l++;
			}

			for (i = 0; i < l - k + 1; i++) {
				temp[i] = str[k + i];
			}
			temp[i] = '\0';
			output[++top] = _wtof(temp);
			k = l;
		}

		else {
			if (str[k] == '+' || str[k] == '-' || str[k] == '*' || str[k] == '/' || str[k] == '^') {
				switch (str[k]) {
					case '+': {
						output[top - 1] += output[top];
						top--;
					} break;
					case '-': {
						output[top - 1] -= output[top];
						top--;
					} break;
					case '*': {
						output[top - 1] *= output[top];
						top--;
					} break;
					case '/': {
						if (output[top] != 0) {
							output[top - 1] /= output[top];
							top--;
                        }
					} break;
					case '^': {
						output[top - 1] = pow(output[top - 1], output[top]);
						top--;
					} break;
				}
			}
		}

	}
		result = output[0];

}

void Calculation :: decoding(wchar_t *str) {
	wchar_t result[50][100];
	wchar_t temp[20];
	int in_res = 0, l, j;
	for (int i = 0; i < wcslen(str); i++) {
		if (iswdigit(str[i]) != 0 ) {
			l = i;
			while (iswdigit(str[l+1]) != 0 || str[l+1] == '.') {
				l++;
			}
			for (j = 0; j < l - i + 1; j++) {
				temp[j] = str[i + j];
			}
			temp[j++] = ' ';
			temp[j] = '\0';
			for (int m = 0; m <= j; m++) {
				result[in_res][m] = temp[m];
			}
			in_res++;
			i = l;
		}
		else if (((int)str[i] >= 97 && (int)str[i] <= 122) || ((int)str[i] >= 65 && (int)str[i] <= 90)) {
			temp[0] = str[i];
			temp[1] = ' ';
			temp[2] = '\0';
			for (int m = 0; m <= 2; m++) {
				result[in_res][m] = temp[m];
			}
			in_res++;
			 }
		else {
			wchar_t temporal[100];
			wchar_t last_operation;
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
				switch (str[i]) {
					case '+': {
						int k = 0;
						for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
							temporal[k++] = result[in_res - 2][i];
						}
						temporal[k++] = '+';
						temporal[k++] = ' ';
						for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
							temporal[k++] = result[in_res - 1][i];
						}
						int last;
						temporal[k] = '\0';
						for (last = 0; last < wcslen(temporal); last++) {
							result[in_res - 2][last] = temporal[last];
						}
						result[in_res - 2][last] = '\0';
						in_res -= 1;
						last_operation = '+';
					} break;
					case '-': {
						int k = 0;
						for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
							temporal[k++] = result[in_res - 2][i];
						}
						temporal[k++] = '-';
						temporal[k++] = ' ';
						for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
							temporal[k++] = result[in_res - 1][i];
						}
						temporal[k] = '\0';
						int last;
						for (last = 0; last < wcslen(temporal); last++) {
							result[in_res - 2][last] = temporal[last];
						}
						result[in_res - 2][last] = '\0';
						in_res -= 1;
						last_operation = '+';
					} break;
					case '*': {
						if (last_operation == '+' || last_operation == '-' ) {
							int k = 0;
							temporal[k++] = '(';
							for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
							temporal[k++] = result[in_res - 2][i];
							}
							temporal[k++] = ')';
							temporal[k++] = '*';
							temporal[k++] = ' ';
							temporal[k++] = '(';
							for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
								temporal[k++] = result[in_res - 1][i];
							}
							temporal[k++] = ')';
							temporal[k++] = ' ';
							temporal[k] = '\0';
							int last;
							for (last = 0; last < wcslen(temporal); last++) {
								result[in_res - 2][last] = temporal[last];
							}
							result[in_res - 2][last] = '\0';
							in_res -= 1;
						}
						else {
							int k = 0;
							for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
								temporal[k++] = result[in_res - 2][i];
							}
							temporal[k++] = '*';
							temporal[k++] = ' ';
							for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
								temporal[k++] = result[in_res - 1][i];
							}
							temporal[k] = '\0';
							int last;
							for (last = 0; last < wcslen(temporal); last++) {
								result[in_res - 2][last] = temporal[last];
							}
							result[in_res - 2][last] = '\0';
							in_res -= 1;
						}
						last_operation = '*';
					} break;
					case '/': {
						if (last_operation == '+' || last_operation == '-' ) {
							int k = 0;
							temporal[k++] = '(';
							for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
							temporal[k++] = result[in_res - 2][i];
							}
							temporal[k++] = ')';
							temporal[k++] = '/';
							temporal[k++] = ' ';

							temporal[k++] = '(';
							for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
								temporal[k++] = result[in_res - 1][i];
							}
							temporal[k++] = ')';
							temporal[k++] = ' ';
							temporal[k] = '\0';
							int last;
							for (last = 0; last < wcslen(temporal); last++) {
								result[in_res - 2][last] = temporal[last];
							}
							result[in_res - 2][last] = '\0';
							in_res -= 1;
						}
						else {
							int k = 0;
							for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
								temporal[k++] = result[in_res - 2][i];
							}
							temporal[k++] = '/';
							temporal[k++] = ' ';
							for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
								temporal[k++] = result[in_res - 1][i];
							}
							temporal[k] = '\0';
							int last;
							for (last = 0; last < wcslen(temporal); last++) {
								result[in_res - 2][last] = temporal[last];
							}
							result[in_res - 2][last] = '\0';
							in_res -= 1;
						}
						last_operation = '/';
					} break;
					case '^': {
							int k = 0;
							temporal[k++] = '(';
							for (int i = 0; i < wcslen(result[in_res - 2]); i++) {
							temporal[k++] = result[in_res - 2][i];
							}
							temporal[k++] = ')';
							temporal[k++] = '^';
							for (int i = 0; i < wcslen(result[in_res - 1]); i++) {
								temporal[k++] = result[in_res - 1][i];
							}
							temporal[k] = '\0';
							int last;
							for (last = 0; last < wcslen(temporal); last++) {
								result[in_res - 2][last] = temporal[last];
							}
							result[in_res - 2][last] = '\0';
							in_res -= 1;
							last_operation = '^';
					} break;
				default:
					;
				}
			}
		}
	}
	TransletadeToInfix = new wchar_t[wcslen(result[0])];
	for ( l = 0; l < wcslen(result[0]); l++) {
		TransletadeToInfix[l] = result[0][l];
	}
	TransletadeToInfix[l] = '\0';
}