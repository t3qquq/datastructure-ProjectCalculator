#pragma once

/*


	↓↓↓↓명세↓↓↓↓


				  */

template <typename T>
class List
{
private:
	T *items;
	int itemCount;
	int size;

public:
	List();
	~List();
	T getItem(int index);
	void addItem(T itm);
	void insertItem(int index, T itm);
	int removeAt(int index);
	int removeItem(T itm);
	void concat(List &list);
	void print();
	int chItmCnt();
};

/*


	↓↓↓↓구현↓↓↓↓


				  */

template <typename T>
List<T>::List()
{
	size = 5;
	itemCount = 0;
	items = new T[size];
}

template <typename T>
List<T>::~List()
{
	delete[] items;
}

template <typename T>
T List<T>::getItem(int index)
{
	if (index >= 0 && index < itemCount)
		return items[index];
	else
		throw "out of range";
}

template <typename T>
void List<T>::addItem(T itm)
{
	if (itemCount < 5)
	{
		items[itemCount] = itm;
		itemCount++;
	}
	else
	{
		T *newItems = new T[++size];
		for (int i = 0; i < itemCount; i++)
			newItems[i] = items[i];
		newItems[itemCount] = itm;
		delete[] items;
		items = newItems;
		itemCount++;
	}
}

template <typename T>
void List<T>::insertItem(int index, T itm)
{
	T *newItems = new T[++size];
	for (int i = 0; i < index; i++)
	{
		newItems[i] = items[i];
	}
	for (int i = index + 1; i < size; i++)
	{
		newItems[i] = items[i - 1];
	}
	newItems[index] = itm;
	delete[] items;
	items = newItems;
	itemCount++;
}

template <typename T>
int List<T>::removeAt(int index)
{
	int tmp = -99999;
	if (index >= 0 && index < itemCount)
	{
		int tmp = items[index];
		for (int i = index; i < itemCount; i++)
		{
			items[i] = items[i + 1];
		}
		itemCount--;
	}
	return tmp;
}

template <typename T>
int List<T>::removeItem(T itm)
{
	int tmp_indx = -99999;
	for (int i = 0; i < itemCount; i++)
	{
		if (items[i] == itm)
		{
			tmp_indx = i;
			break;
		}
	}
	if (tmp_indx != -99999)
	{
		for (int i = tmp_indx; i < itemCount; i++)
		{
			items[i] = items[i + 1];
		}
		itemCount--;
	}
	return tmp_indx;
}

template <typename T>
void List<T>::concat(List &list)
{

	size += list.size;
	itemCount += list.itemCount;

	int *newItems = new int[size];

	for (int i = 0; i < itemCount - list.itemCount; i++)
	{
		newItems[i] = items[i];
	}

	for (int i = itemCount - list.itemCount; i < itemCount; i++)
	{
		newItems[i] = list.items[i - (itemCount - list.itemCount)];
	}

	delete[] items;

	items = newItems;
}

template <typename T>
void List<T>::print()
{
	for (int i = 0; i < itemCount; i++)
	{
		getItem(i).print();
	}
}

template <typename T>
int List<T>::chItmCnt()
{
	return itemCount;
}