#pragma once
#include "Iterator.hpp"

template<typename T>
class Vector {
    Iterator<T>* It; 
    int size;        

public:
    Vector();
    ~Vector();

    void pushBack(T value);
    T operator[](int index);
    int Size();
    Iterator<T> Begin();
    Iterator<T> end();
};

template<typename T>
Vector<T>::Vector() : It(new Iterator<T>()), size(0) {
    It->Current = nullptr; 
}

template<typename T>
Vector<T>::~Vector() {
    while (It->Current && It->Current->Prev) {
        It->operator--();
    }

    while (It->Current) {
        Node<T>* temp = It->Current->Next;
        delete It->Current;
        It->Current = temp;
    }

    delete It;
}

template<typename T>
void Vector<T>::pushBack(T value) {
    if (size == 0) {
        It->Current = new Node<T>();
        It->Current->Value = value;
        It->Current->Prev = nullptr;
        It->Current->Next = nullptr;
    }
    else {
        while (It->Current->Next != nullptr) {
            It->operator++();
        }

        Node<T>* newNode = new Node<T>();
        newNode->Value = value;
        newNode->Prev = It->Current;
        newNode->Next = nullptr;

        It->Current->Next = newNode;
        It->operator++();
    }

    size++;
}

template<typename T>
T Vector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        std::cout << " \033[31mIndex out of range\033[0m";
    }

   
    Begin();

    for (int i = 0; i < index; i++) {
        It->operator++();
    }

    return It->Current->Value; 
}

template<typename T>
int Vector<T>::Size() {
    return size;
}

template<typename T>
Iterator<T> Vector<T>::Begin() {
    while (It->Current && It->Current->Prev != nullptr) {
        It->operator--();
    }

    return *It;
}
template<typename T>
Iterator<T> Vector<T>::end() {
    while (It->Current && It->Current->Next != nullptr) {
        It->operator++();
    }

    return *It;
}
