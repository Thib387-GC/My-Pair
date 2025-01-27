#pragma once
#include "Iterator.hpp"

template<typename T>
class Vector {
	Iterator<T>* It;
public:
	 Vector();

	void pushBack(T value);

	T operator[](int j);

	int Size();
	
	Iterator<T> Begin();
};

template<typename T>
Vector<T>::Vector(){
	It = new Iterator<T>();
	It->Current = new Node<T>();
	It->Current->Prev = nullptr;
	It->Current->Next = nullptr;


}
template<typename T>
void Vector<T>::pushBack(T value) {
	while(It->Current->Next != nullptr) {
		It->operator++();
	}


	Node<T>* tempNode = new Node<T>();
	tempNode->Prev = It->Current;
	tempNode->Value = value;
	tempNode->Next = nullptr;
	It->Current->Next =tempNode;
}

template<typename T>
inline T Vector<T>::operator[](int j)
{
	if (j < Size())
	{
		Begin();
		for (int i = 0; i <= j; i++)
		{
			It->operator++();

		}
		
	}
	return It->Current->Value;
}

template<typename T>
inline int Vector<T>::Size()
{
	Begin();
	int it=0;

	while (It->Current->Next != nullptr)
	{
		It->operator++();
		it++;
	}
	return it;
}

template<typename T>
inline Iterator<T> Vector<T>::Begin()
{
	while (It->Current->Prev != nullptr)
	{
		It->operator--();
	}
	return *It;

}



