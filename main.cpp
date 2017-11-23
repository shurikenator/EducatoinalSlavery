#include <iostream>
#include "list.h"
using namespace std;

int main(int item)
{
	//
	//
	//Оформить как меню с вопросами!!!
	//
	//




	setlocale(LC_ALL, "Russian");

	IntList list;

	int pos, pos1, pos2, otv, da;
	//ListItem *first, *last;
	int x, r, k, m, y, j, val;
	ListItem *head = NULL;							//понять как обращаться
	ListItem *newItem = new ListItem(item, first);	//понять как обращаться
	cout << "Введите количество элементов, владыка: ";
	cin >> k;
	if (k != 0)
	for (int i = 1; i <= k; i++)					// формирование списка
	{
		r = rand() % 100;
		list.insert(*&head, i, val);				// вставка элемента 
	}
	list.get_list(head);							// вывод списка



													//добавление элемента в заданную позицию:
	cout << "Введите позицию в списке для добовлаяемой переменной, владыка: ";
	cin >> pos;
	cout << "Введите переменную, которую желаете добавить в список, владыка: ";
	cin >> val;
	list.insert(*&head, pos, val);

	list.is_empty(*&head);


													//удаление элемента в заданной позиции:
	cout << "Введите позицию в списке для удаляемой переменной, владыка: ";
	cin >> pos2;
	list.erase(*&head, pos2);
	
	list.AddLast(2);
	list.AddLast(3);
	list.AddFirst(1);
	list.is_empty(*&head);
	cout << list.GetAllItemsInfo();
	IntList list1(list);
	list1.AddLast(4);
	list1.Remove(2);
	list1.Remove(5);
	list1.Remove(4);

	cout << list1.GetAllItemsInfo();

	return 0;
}
