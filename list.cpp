#include <sstream>
#include <string>
#include "list.h"
#include <iostream>

using namespace std;

IntList::IntList(const IntList & src)
{
	itemsCount = 0;
	pos = 0;
	first = last = NULL;
	AddLast(src);
}

IntList::~IntList()
{
	ListItem  *current = NULL;
	ListItem *next = first;
	while (next)
	{
		current = next;
		next = next->next;
		delete current;
	}
}

void IntList::AddLast(const IntList & src)
{
	for (ListItem *cur = src.first; cur; cur = cur->next)
		AddLast(cur->item);
}

void IntList::AddFirst(int item)
{
	ListItem *newItem = new ListItem(item, first);
	if (!first)
	{
		last = newItem;
	}
	first = newItem;
	itemsCount++;
}

void IntList::AddLast(int item)
{
	ListItem *newItem = new ListItem(item);
	if (!last)
	{
		first = newItem;
	}
	else
		last->next = newItem;
	last = newItem;
	itemsCount++;
}

int IntList::RemoveFirst()
{
	int res = first->item;
	first = first->next;
	itemsCount--;
	return res;
}

bool IntList::Remove(int value)
{
	ListItem *prev = 0, *current = first;
	while (current)
	{
		if (current->item == value)
		{
			if (prev) prev->next = current->next;

			if (current == last)
			{
				last = prev;
			}
			delete current;
			itemsCount--;
			return true;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	return false;
}
void IntList::Insert_1(int value)
{
	ListItem *prev = NULL, *succ = first;
	while ((succ != NULL) && (succ->item < value))
	{
		prev = succ;
		succ = succ->next;
	}
	ListItem *newItem = new ListItem(value, succ);
	if (succ == NULL)	last = newItem;
	if (prev == NULL)	first = newItem;
	else prev->next = newItem;
	itemsCount++;
}

string IntList::GetAllItemsInfo()
{
	stringstream stream;
	ListItem *current = first;
	while (current){
		stream << current->item << ' ';
		current = current->next;
	}
	stream << endl;
	return stream.str();
}

int IntList::get_list(ListItem * head)
{
	ListItem *p = head;
	while (p != NULL)
	{
		cout << p->item << ' ';
		p = p->next;
	}
	cout << endl;
}
void IntList::insert(ListItem *&head,int pos, int val)
{
	//ListItem *newItem = new ListItem(item, first);
	
	
	int j = 1;
	int i;
	ListItem *newItem, *p = head;
	//newItem = new ListItem(i, first);
	newItem->item = val;
	if (pos <= 1 || head == NULL)
	{
		newItem->next = head;
		head = newItem;
	}
	else
	{
		for (i = 1; i<pos - 1; i++)
		if (p->next != NULL)
		{
			p = p->next;
			j++;
		}
		if (pos <= j + 1)
		{
			newItem->next = p->next; p->next = newItem;
		}
	}


	itemsCount++;
}
bool IntList::is_empty(ListItem *&head)
{
	if (head == NULL)
	{
		cout << "Список пуст! добавь что-нибудь...";
		insert(*&head, pos, val);
		return true;
	}
	else
		return false;
}
void IntList::erase(ListItem *&head, int pos2)
{
	{
		ListItem *a = head, *b;
		
		int i = 0;
		while (a != NULL)
		{
			a = a->next;
			i++;
		}
		if (pos2>i || pos2<1)
		{
			cout << "Владыка, такой позиции в списке нет!" << endl;
		}//проверка на сущ-е позиции      
		else
		{
			if (pos2 == 1)
			{
				a = head->next;//если эл-т первый
				head = a;
			}
			if (pos2>1)
			{
				i = 1;//если эл-т не первый
				a = head;
				while (i != pos2 - 1)
				{
					i++; 
					a = a->next;
				}
				b = a->next;
				a->next = b->next;//сдвигаем
				delete b;
			}
		}
	}
}
size_t IntList::get_size()
{

}
