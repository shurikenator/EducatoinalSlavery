#include <sstream>
#include <string>
#include "list.h"

using namespace std;

IntList::IntList(const IntList & src)
{
	itemsCount = 0;
	first = last = NULL;
	AddLast(src);
}

IntList::~IntList()
{
	ListItem *current = NULL;
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
void IntList::Insert(int value)
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
