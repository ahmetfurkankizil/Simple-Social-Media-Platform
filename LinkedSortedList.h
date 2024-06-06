//
// Ahmet Furkan KIZIL, Section 2, 22203112
//

#ifndef HW3_LINKEDSORTEDLIST_H
#define HW3_LINKEDSORTEDLIST_H


template <typename T>
class Node {
private:
    T data;
    Node* next;
public:
    Node(T entry) ;
    Node ();
    void setItem(const T& itemToBeSet);
    void setNext(Node<T>* nextValue);
    T& getItem();
    Node* getNext() const;
    Node(const Node& other);
    Node& operator=(const Node& other);
    ~Node();
};

template <typename T>
class LinkedSortedList {
private:
    Node<T>* head;
    int itemCount;

public:
    LinkedSortedList() : head(nullptr), itemCount(0) {}
    ~LinkedSortedList();
    bool insertSorted(T& newEntry);
    bool isEmpty() const;
    int getLength() const;
    bool remove(int targetId);
    bool exists(int targetId) const;
    Node<T>* getHead() const;
};


#endif //HW3_LINKEDSORTEDLIST_H
