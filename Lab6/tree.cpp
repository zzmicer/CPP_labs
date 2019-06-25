// ---------------------------------------------------------------------------

#pragma hdrstop

#include "tree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

Tree::Tree() {
	size = 0;
	root = NULL;
}

Tree::~Tree() {
	root = NULL;
}

void Tree::add(int key, String data, Node **root, int level = 0) {
	if ((*root) == NULL) {
		(*root) = new Node;
		(*root)->key = key;
		(*root)->data = data;
		(*root)->level = level;
		(*root)->Left = (*root)->Right = NULL;
	}
	else if (key > (*root)->key)
		add(key, data, &(*root)->Right, ++level);
	else if (key < (*root)->key)
		add(key, data, &(*root)->Left, ++level);
	else
		ShowMessage("This key has already exist!");

}

void Tree::preOrder(Node *root) {
	if (root != NULL) {
		Form1->Memo1->Lines->Add(IntToStr(root->key));
		Form1->Memo1->Lines->Add(root->data);
		preOrder(root->Left);
		preOrder(root->Right);
	}
}

void Tree::postOrder(Node *root) {
	if (root != NULL) {
		postOrder(root->Left);
		postOrder(root->Right);
		Form1->Memo1->Lines->Add(IntToStr(root->key));
		Form1->Memo1->Lines->Add(root->data);

	}
}

void Tree::inOrder(Node *root) {
	if (root != NULL) {
		inOrder(root->Left);
		Form1->Memo1->Lines->Add(IntToStr(root->key));
		Form1->Memo1->Lines->Add(root->data);
		inOrder(root->Right);

	}
}

void Tree::print(Node *root) {
	Form1->Memo1->Clear();
	if (root == NULL) {
		Form1->Memo1->Lines->Add("������ ������");
	}
	else {
		Form1->Memo1->Clear();
		Form1->Memo1->Lines->Add("������ �����");
		preOrder(root);
		Form1->Memo1->Lines->Add("");
		Form1->Memo1->Lines->Add("�������� �����");
		postOrder(root);
		Form1->Memo1->Lines->Add("");
		Form1->Memo1->Lines->Add("����������� �����");
		inOrder(root);
	}
}

void Tree::viewTree(Node *root, int lv) {
	if (root == NULL)
		return;
	if (lv == -1)
		Form1->TreeView1->Items->AddFirst(NULL,
		root->data + " = " + IntToStr(root->key));
	else
		Form1->TreeView1->Items->AddChildFirst
			(Form1->TreeView1->Items->Item[lv],
		root->data + " = " + IntToStr(root->key));
	lv++;
	viewTree(root->Left, lv);
	viewTree(root->Right, lv);
	lv--;

}

void Tree::search(int key, Node *root) {
	Form1->Memo1->Clear();
	if (root != NULL) {
		if (root->key == key) {
			Form1->Memo1->Lines->Add("������");
			Form1->Memo1->Lines->Add(IntToStr(root->key));
			Form1->Memo1->Lines->Add(root->data);
			Form1->Memo1->Lines->Add("");
		}
		else if (root->key < key)
			search(key, root->Right);
		else if (root->key > key)
			search(key, root->Left);
	}
	else
		Form1->Memo1->Lines->Add("��� ������ ��������");
}

int Tree::arrayFill(Node *root, int *key, String *data, int j) {
	if (root == NULL) {
		return j;
	}
	j = arrayFill(root->Left, key, data, j);
	data[j] = root->data;
	key[j] = root->key;
	j++;
	j = arrayFill(root->Right, key, data, j);
	return j;
}

void Tree::rebuildTree(int left, int right, int *key, String *data) {
	int middle = (left + right) / 2;
	if (left == right) {
		return;
	}
	add(key[middle], data[middle], &root, 0);
	rebuildTree(left, middle, key, data);
	rebuildTree(middle + 1, right, key, data);

}

void Tree::balance() {
	String data[1000];
	int key[1000];
	int amount;
	if (this->root == NULL)
		throw Exception("������ ������");
	amount = arrayFill(this->root, key, data, 0);
	this->root = NULL;
	int middle = (0 + amount - 1) / 2;
	rebuildTree(0, amount, key, data);
}

