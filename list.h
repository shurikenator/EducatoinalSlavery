#include <stdlib.h>
#include <string>
using namespace std;

class IntList
{
public:
	IntList()
	{
		itemsCount = 0;
		first = last = NULL;
	}

	IntList(const IntList & src);
	~IntList();
	int Head() const
	{
		return first->item;
	}
	int & Head()
	{
		return first->item;
	}

	int Tail() const
	{
		return last->item;
	}
	int & Tail()
	{
		return last->item;
	}

	void AddLast(const IntList & src);
	void AddFirst(int item);
	void AddLast(int item);
	int RemoveFirst();
	bool Remove(int n);
	void Insert(int n);

	int GetItemsCount()
	{
		return itemsCount;
	}
	string GetAllItemsInfo();

private:
	struct ListItem{
		int item;
		ListItem *next;

		ListItem(int i, ListItem *n = NULL)
		{
			item = i;
			next = n;
		}
	};
	int itemsCount;
	ListItem  *first;
	ListItem *last;
};

