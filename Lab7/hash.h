//---------------------------------------------------------------------------

#ifndef hashH
#define hashH
//---------------------------------------------------------------------------
template<typename T>
class List
{
public:
	List();
	~List();

	void deleteFirst();

	void addInEnd(T data);

	void clear();

	int GetSize() { return Size; }

	T& operator[](const int index);

	void addInFirst(T data);

	void insert(T data, int index);

	void deleteElemet(int index);

	void deleteLast();

	void rewriteData(int index, T newData);

	int hash(int k);

private:
	template<typename T>
	class Node
	{
	public:
		Node * pNext;
		T data;
		Node(T data = T(), Node *pNext = NULL)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = NULL;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::deleteFirst()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::addInEnd(T data)
{
	if (head == NULL)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != NULL)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		deleteFirst();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != NULL)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::addInFirst(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		addInFirst(data);
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *newNode = new Node<T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::deleteElemet(int index)
{
	if (index == 0)
	{
		deleteFirst();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::rewriteData(int index, T newData)
{
		Node<T> *selected = this->head;
		for (int i = 0; i < index; i++)
		{
			selected = selected->pNext;
		}
		selected->data=newData;

}


template<typename T>
void List<T>::deleteLast()
{
	deleteElemet(Size - 1);
}

template<typename T>
int List<T>::hash(int k)
{
return k%10;
}

#endif
