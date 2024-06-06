//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#include <type_traits>
#include "LinkedSortedList.h"

template<typename T>
Node<T>::Node(T value) : data(value), next(nullptr) {}

template<typename T>
Node<T>::Node(){
}

//Copy constructor
template<typename T>
Node<T>::Node(const Node& other) {
    data = other.data;
    if (other.next) {
        next = new Node(*other.next);
    } else {
        next = nullptr;
    }
}

// Assignment operator
template <typename T>
Node<T>& Node<T>::operator=(const Node& other) {
    if (this != &other) {
        data = other.data;
        delete next;

        if (other.next) {
            next = new Node(*other.next);
        } else {
            next = nullptr;
        }
    }
    return *this;
}

template <typename T>
Node<T>::~Node() {}


template<typename T>
void Node<T>::setItem(const T& itemToBeSet) {
    data = itemToBeSet;
}

template<typename T>
void Node<T>::setNext(Node<T>* nextValue) {
    next = nextValue;
}

template<typename T>
T& Node<T>::getItem(){
    return data;
}


template<typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

//LinkedSortList Part
template <typename T>
LinkedSortedList<T>::~LinkedSortedList() {
}

template<typename T>
bool LinkedSortedList<T>::insertSorted(T& newEntry) {
    Node<T>* newNode = new Node<T>(newEntry);
    Node<T>* prev = nullptr;
    Node<T>* current = head;

    while (current != nullptr && newNode->getItem().getId() > current->getItem().getId()) {
        prev = current;
        current = current->getNext();
    }

    if (prev == nullptr) {
        newNode->setNext(head);
        head = newNode;
    } else {
        newNode->setNext(current);
        prev->setNext(newNode);
    }

    itemCount++;
    return true;
}

template<typename T>
bool LinkedSortedList<T>::isEmpty() const {
    return itemCount == 0;
}

template<typename T>
int LinkedSortedList<T>::getLength() const {
    return itemCount;
}

template<typename T>
bool LinkedSortedList<T>::remove(int targetId) {
    Node<T>* current = head;
    Node<T>* prev = nullptr;


    while (current->getNext() != nullptr && current->getItem().getId() != targetId) {
        prev = current;
        current = current->getNext();
    }
    if (current == nullptr) {
        return false;
    }

    if (prev == nullptr) {
        head = current->getNext();
    } else {
        prev->setNext(current->getNext());
        current->setNext(nullptr);
    }
    delete current;
    current = nullptr;
    itemCount--;

    return true;
}

template<typename T>
bool LinkedSortedList<T>::exists(int targetId) const {
    Node<T>* current = head;

    while (current != nullptr) {
        if (current->getItem().getId() == targetId) {
            return true;
        }
        current = current->getNext();
    }
    return false;
}

template<typename T>
Node<T>* LinkedSortedList<T>::getHead() const {
    return head;
}