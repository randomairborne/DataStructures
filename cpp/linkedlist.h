#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <cstddef>

template<typename T>
class LinkedList {
public:
    LinkedList();
    bool Push(T);

    T *Get(std::size_t);

    bool Remove(size_t);

    bool Set(size_t, T);

    bool Insert(size_t, T);

    size_t Len();

private:
    T *data = nullptr;
    LinkedList<T> *next = nullptr;
};



#endif //DATASTRUCTURES_LINKEDLIST_H
