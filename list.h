#include <stdlib.h>
#include <string>
using namespace std;

class IntList
{
private:
	struct ListItem {
		int item;
		ListItem *next;

		ListItem(int i, ListItem *n = NULL)
		{
			item = i;
			next = n;
		}
	};
	int itemsCount;
	int pos;
	int val;
	ListItem  *first;
	ListItem *last;
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
	void Insert_1(int n);
	size_t get_size() const;					//получить размер списка
	bool is_empty(ListItem *&head);					//возвращает true, если список пуст
	int & operator[](int i);					//неконстантный оператор - получение ссылки на i-ый элемент
	const int & operator[](int i) const;				//константный оператор - получение ссылки на i-ый элемент
	void pop_front();						//удаление элемента из начала списка
	int & get_front();						//получение первого элемента
	const int & get_front() const;					//
	void insert(ListItem *&head,int pos, int val);			//добавление нового элемента в заданную позицию
	void erase(ListItem *&head, int pos);				//удалить определенный элемент
	int get_list(ListItem * head);					//вывести список
	int GetItemsCount()
	{
		return itemsCount;
	}
	string GetAllItemsInfo();


};


