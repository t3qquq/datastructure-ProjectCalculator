#pragma once
#include <iostream>
#include <cstring>
template <typename T>
class Stack
{
private:
    T *items;
    int size;
    int top;

public:
    Stack();
    Stack(int m);
    ~Stack();

    void Push(T item);
    T Pop();
    T peek();
    void print();

    bool isEmpty();
};

template <typename T>
Stack<T>::Stack(int m)
{
    size = m;
    items = new T[size];
    top = 0;
}

template <typename T>
Stack<T>::Stack() : Stack(10)
{
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] items;
}

template <typename T>
void Stack<T>::Push(T item)
{
    if (top < size)
        items[top++] = item;
    else
    {
        size *= 2;
        T *newItems = new T[size];
        memcpy(newItems, items, sizeof(T) * top);
        newItems[top++] = item;
        delete items;
        items = newItems;
    }
}

template <typename T>
T Stack<T>::Pop()
{
    if (top > 0)
    {
        int pos = top - 1;
        T value = items[pos];
        for (int i = pos; i < top; i++)
            items[i] = items[i + 1];
        top--;
        return value;
    }
    else
        throw "Stack is empty";
}

template <typename T>
T Stack<T>::peek()
{
    if (top > 0)
        return items[top - 1];
    else
        throw "Stack is empty";
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return (top == 0);
}

template <typename T>
void Stack<T>::print()
{
    for (int i = 0; i < top; i++)
    {
        items[i].print();
    }
}