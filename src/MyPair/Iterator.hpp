#pragma once
#include "Node.hpp"

template<typename T>
class Iterator {
	
public:
	void operator++();
	void operator--();
	T operator*();

	Iterator();
	Node<T>* Current;
};
template<typename T>
Iterator<T>::Iterator(){
	Current = nullptr;
}
template<typename T>
void Iterator<T>::operator++() {
	Current = Current->Next;
}

template<typename T>
void Iterator<T>::operator--() {
	Current = Current->Prev;

}


template<typename T>
T Iterator<T>::operator*() {
	return Current->Value;
}