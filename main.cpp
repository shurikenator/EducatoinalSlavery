#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	IntList list;
	list.AddLast(2);
	list.AddLast(3);
	list.AddFirst(1);

	cout << list.GetAllItemsInfo();
	IntList list1(list);
	list1.AddLast(4);
	list1.Remove(2);
	list1.Remove(5);
	list1.Remove(4);

	cout << list1.GetAllItemsInfo();

	return 0;
}
