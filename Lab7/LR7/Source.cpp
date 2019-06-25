#include <iostream>
#include <conio.h>

typedef struct barcode
{
	int key;
	char name[80];
	int price;
	barcode* next;
	barcode* prev;
} barcode;
typedef barcode* BCode;

typedef struct discountCard
{
	int num;
	int sale;
	discountCard* next;
	discountCard* prev;
} discountCard;
typedef discountCard* DCard;


int read()
{
	char c; //Переменная для хранения каждого введённого символа
	int num, i = 0; //Переменная - вводимое число
	char str[81];
	while (i < 6 && ((c = _getch()) != 13)) //Пока пользователь не нажмёт Enter
	{
		if (isdigit(c))
		{
			str[i++] = c;
			_putch(c); //Если цифра - вывод цифры в консоль
		}
	}

	str[i] = '\0'; //Сформированную строку завершаем признаком окончания строки

	num = atoi(str); //Преобразуем строку в число
	return num;
}

BCode fileReadBCode(BCode headBC)
{
	int numBC;
	FILE *inputBC;
	fopen_s(&inputBC, "barcode.txt", "r");
	if (!inputBC)
	{
		printf("Ошибка при открытии файла!");
		system("pause");
		return NULL;
	}
	fscanf_s(inputBC, "%d", &numBC);
	if (headBC == NULL)
	{
		headBC = new barcode;
		headBC->next = NULL;
		headBC->prev = NULL;
		fscanf_s(inputBC, "%d%s%d", &(headBC->key), &(headBC->name), _countof(headBC->name), &(headBC->price));
		numBC--; // Первый элемент уже считан
	}
	BCode current = headBC;
	for (int i = 0; i < numBC; i++)
	{
		int key;
		char name[80];
		int price;
		bool have = false;
		fscanf_s(inputBC, "%d%s%d", &key, &name, _countof(name), &price);
		BCode temp = headBC;
		while (temp != NULL) // Проверяем нет ли одинакового значения
		{
			if (temp->key == key)
			{
				have = true;
				break;
			}
			temp = temp->next;
		}
		if (have == false)
		{
			BCode current = new barcode;
			current->next = headBC;
			current->prev = NULL;
			headBC->prev = current;
			headBC = current;
			current->key = key;
			strcpy_s(current->name, name);
			current->price = price;
		}
	}
	fclose(inputBC);
	printf("\nОперация прошла успешно!\n");
	system("pause");
	return headBC;
}

BCode addNewBCode(BCode headBC)
{
	int key, price;
	char name[80];
	printf("Номер штрихкода: ");
	key = read();
	printf("\nНаименование: ");
	scanf_s("%s", name, (unsigned)_countof(name));
	printf("Цена: ");
	price = read();
	if (headBC == NULL)
	{
		headBC = new barcode;
		headBC->next = NULL;
		headBC->prev = NULL;
		headBC->key = key;
		strcpy_s(headBC->name, name);
		headBC->price = price;
	}
	else
	{
		BCode current = new barcode;
		current->next = headBC;
		current->prev = NULL;
		headBC->prev = current;
		headBC = current;
		current->key = key;
		strcpy_s(current->name, name);
		current->price = price;
	}
	return headBC;
}


void showBCode(BCode headBC)
{
	BCode current = headBC;
	if (current == NULL)
	{
		printf("Список штрих кодов пуст!\n");
	}
	else
	{
		while (current != NULL)
		{
			printf("%d %s цена: %d\n", current->key, &current->name, current->price);
			current = current->next;
		}
	}

}

BCode deleteBCode(BCode headBC)
{
	showBCode(headBC);
	if (headBC == NULL)
	{
		printf("Список штрих кодов пуст!");
		system("pause");
		return headBC;
	}
	printf("Введите штрих код: \n");
	int delKey = read();
	BCode current = headBC;
	while (current != NULL && current->key != delKey)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		printf("\nТакого штрих кода не существует!\n");
		system("pause");
		return headBC;
	}
	else if (current == headBC && headBC->next == NULL)
	{
		headBC = NULL;
	}
	else if (current == headBC)
	{
		headBC = headBC->next;
		headBC->prev = NULL;
	}
	else
	{
		if (current->prev != NULL)
			current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
	}
	printf("\nОперация прошла успешно!\n");
	system("pause");
	return headBC;
}

void saveBCode(BCode headBC)
{
	int numBC = 0;
	FILE* outputBCode;
	fopen_s(&outputBCode, "barcode.txt", "w");
	if (!outputBCode)
	{
		printf("Ошибка при открытии файла!");
		system("pause");
		return;
	}
	BCode current = headBC;
	while (current != NULL)
	{
		numBC++;
		current = current->next;
	}
	fprintf_s(outputBCode, "%d\n", numBC);
	current = headBC;
	while (current != NULL)
	{
		fprintf_s(outputBCode, "%d %s %d\n", current->key, current->name, current->price);
		current = current->next;
	}
	printf("\nОперация прошла успешно!\n");
	system("pause");
	fclose(outputBCode);
}

DCard fileReadDCard(DCard headDC)
{
	int number;
	FILE* inputDCard;
	fopen_s(&inputDCard, "discountcard.txt", "r");
	if (!inputDCard)
	{
		printf("Ошибка при открытии файла!");
		system("pause");
		return NULL;
	}
	fscanf_s(inputDCard, "%d", &number);
	if (headDC == NULL)
	{
		headDC = new discountCard;
		headDC->next = NULL;
		headDC->prev = NULL;
		fscanf_s(inputDCard, "%d%d", &(headDC->num), &(headDC->sale));
		number--;
	}
	for (int i = 0; i < number; i++)
	{
		int numOfCard;
		int sale;
		bool have = false;
		fscanf_s(inputDCard, "%d%d", &numOfCard, &sale);
		DCard temp = headDC;
		while (temp != NULL)
		{
			if (temp->num == numOfCard)
			{
				have = true;
				break;
			}
			temp = temp->next;
		}
		if (have == false)
		{
			DCard current = new discountCard;
			current->next = headDC;
			current->prev = NULL;
			headDC->prev = current;
			headDC = current;
			current->sale = sale;
			current->num = numOfCard;
		}
	}
	fclose(inputDCard);
	printf("Операция прошла успешно!\n");
	system("pause");
	return headDC;
}

DCard addNewDCard(DCard headDC)
{
	int numOfCard, sale;
	printf("Номер карты: ");
	numOfCard = read();
	printf("\nСкидка: ");
	scanf_s("%d", &sale);
	if (headDC == NULL)
	{
		headDC = new discountCard;
		headDC->next = NULL;
		headDC->prev = NULL;
		headDC->sale = sale;
		headDC->num = numOfCard;
	}
	else
	{
		bool have = false;
		DCard temp = headDC;
		while (temp != NULL)
		{
			if (temp->num == numOfCard)
			{
				have = true;
				break;
			}
			temp = temp->next;
		}
		if (have == false)
		{
			DCard current = new discountCard;
			current->next = headDC;
			current->prev = NULL;
			headDC->prev = current;
			headDC = current;
			current->sale = sale;
			current->num = numOfCard;
		}
	}
	return headDC;
}

void showDCard(DCard headDC)
{
	DCard current = headDC;
	if (current == NULL)
	{
		printf("Список дисконтных карт пуст\n");
		system("pause");
	}
	else
	{
		while (current != NULL)
		{
			printf("Карта %d, скидка: %d\n", current->num, current->sale);
			current = current->next;
		}
	}

}

DCard deleteDCard(DCard headDC)
{
	showDCard(headDC);
	if (headDC == NULL)
	{
		system("pause");
		return headDC;
	}
	printf("Введите дисконтную карту код: ");
	int delKey = read();
	DCard current = headDC;
	while (current != NULL && current->num != delKey)
	{
		current = current->next;
	}
	if (current == NULL)
	{
		printf("\nКарты с таким номером не существует!\n");
		system("pause");
		return headDC;
	}
	else if (current == headDC && headDC->next == NULL)
	{
		headDC = NULL;
	}
	else if (current == headDC)
	{
		headDC = headDC->next;
		headDC->prev = NULL;
	}
	else
	{
		if (current->prev != NULL)
			current->prev->next = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
	}
	printf("\nОперация прошла успешно!\n");
	system("pause");
	return headDC;
}

void saveDCard(DCard headDC)
{
	int numberOfCards = 0;
	FILE* outputDCard;
	fopen_s(&outputDCard, "discountcard.txt", "w");
	if (!outputDCard)
	{
		printf("Ошибка при открытии файла!");
		system("pause");
		return;
	}
	DCard current = headDC;
	while (current != NULL)
	{
		numberOfCards++;
		current = current->next;
	}
	fprintf_s(outputDCard, "%d\n", numberOfCards);
	current = headDC;
	while (current != NULL)
	{
		fprintf_s(outputDCard, "%d %d\n", current->num, current->sale);
		current = current->next;
	}
	printf("Операция прошла успешно!\n");
	system("pause");
	fclose(outputDCard);
}

int purchase(BCode headBC)
{
	int sum = 0;
	bool choiceProduct = true;
	FILE* outputHistory;
	fopen_s(&outputHistory, "history.txt", "a");

	while (choiceProduct)
	{
		int numBC;
		showBCode(headBC);
		printf("\nВведите шрихкод товара:");
		numBC = read();
		BCode current = headBC;

		while (current != NULL)
		{
			if (current->key == numBC) break;
			current = current->next;
		}
		if (current == NULL)
		{
			printf("\nТакого товара не существует!\n");
		}
		else
		{
			int productAmount;
			printf("\nВведите количество: ");
			productAmount = read();
			sum += (current->price) * productAmount;
			fprintf(outputHistory, "%s x %d = %d\n", &current->name, productAmount, (current->price) * productAmount);

		}
		printf("\n\nХотите добавить новый товар? 1/0\n");

		int choice;
		scanf_s("%d", &choice);
		printf("\n");
		if (choice == 1)
			choiceProduct = true;
		else
			choiceProduct = false;
	}
	fclose(outputHistory);
	return sum;
}

int useDCard(int sum, DCard headDC)
{
	if (sum != 0)
	{
		FILE* outputHistory;
		fopen_s(&outputHistory, "history.txt", "a");

		printf("У вас есть дисктонтная карта? 1/0\n");
		int choice = read();
		printf("\n");
		if (choice == 1) 
		{
			int j = 0;
			printf("Введите номер вашей карты: ");
			int numOfCard = read();
			printf("\n");
			DCard current = headDC;
			while (current != NULL)
			{
				if (numOfCard == current->num) break;
				current = current->next;
			}
			if (current == NULL)
			{
				printf("\nКарты с таким номером не существует\n");
			}
			else
			{
				sum = (double)sum * ((100.0 - (double)current->sale) / 100.0);
				fprintf(outputHistory, "Скидка %d%%\n", current->sale);
			}
		}
		printf("Конечная сумма %d\n", sum);
		fprintf(outputHistory, "Конечная сумма %d\n", sum);
		fprintf(outputHistory, "Покупка завершена!\n");
		fclose(outputHistory);
	}
	system("pause");
	return sum;
}

int main() {
	setlocale(LC_ALL, "rus");
	BCode headBC = NULL;
	DCard headDC = NULL;

	int choice;
	do
	{
		system("cls");
		printf("1. Считать штрихкоды из файла\n");
		printf("2. Добавить новый штрихкод\n");
		printf("3. Вывести штрихкоды\n");
		printf("4. Удалить штрихкод\n");
		printf("5. Сохранить штрихкоды в файл\n");
		printf("--------------------------------\n");
		printf("6. Считать дисконтные карты из файла\n");
		printf("7. Добавить новую дисконтную карту\n");
		printf("8. Вывести дисконтные карты\n");
		printf("9. Удалить дисконтную карту\n");
		printf("10. Сохранить дисконтные карты в файл\n");
		printf("--------------------------------\n");
		printf("11. Новая покупка\n");
		printf("--------------------------------\n");
		printf("12. Выход\n");
		printf("Введите цифру(1-12): ");
		choice = read();
		switch (choice)
		{
		case 1:
			system("cls");
			headBC = fileReadBCode(headBC);
			break;
		case 2:
			system("cls");
			headBC = addNewBCode(headBC);
			break;
		case 3:
			system("cls");
			showBCode(headBC);
			system("pause");
			break;
		case 4:
			system("cls");
			deleteBCode(headBC);
			break;
		case 5:
			system("cls");
			saveBCode(headBC);
			break;
		case 6:
			system("cls");
			headDC = fileReadDCard(headDC);
			break;
		case 7:
			system("cls");
			headDC = addNewDCard(headDC);
			break;
		case 8:
			system("cls");
			showDCard(headDC);
			system("pause");
			break;
		case 9:
			system("cls");
			headDC = deleteDCard(headDC);
			break;
		case 10:
			system("cls");
			saveDCard(headDC);
			break;
		case 11:
			int sum;
			system("cls");
			sum = purchase(headBC);
			sum = useDCard(sum, headDC);
			break;
		}
	} while (choice != 12);
	return 1;
}