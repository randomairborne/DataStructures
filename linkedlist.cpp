#ifndef DATASTRUCTURES_LINKEDLIST_CPP
#define DATASTRUCTURES_LINKEDLIST_CPP

#include <cstdlib>
#include "linkedlist.h"

template<typename T>
class LinkedList {
public:
    /// Takes ownership of value passed into it
    void Push(T);

    T *Get(size_t);

    bool Remove(size_t);

    bool Set(size_t, T);

private:
    LinkedListEntry<T> *first = nullptr;
};

template<typename T>
void LinkedList<T>::Push(T item) {
    auto entry = new LinkedListEntry<T>;
    entry->next = nullptr;
    entry->data = item;
    if (first == nullptr) {
        first = entry;
    } else {
        LinkedListEntry<T> *prev = first;
        while (prev->next != nullptr) {
            prev = prev->next;
        }
        prev->next = entry;
    }
}

/// Returns a pointer to the data at this index, or null
template<typename T>
T *LinkedList<T>::Get(size_t idx) {
    LinkedListEntry<T> *item = first;
    if (item == nullptr) {
        return nullptr;
    }
    for (size_t current_idx = 0; current_idx < idx; ++current_idx) {
        item = item->next;
        if (item == nullptr) {
            return nullptr;
        }
    }
    return &item->data;
}

/// Returns false if no such element exists, and true if the set succeeded
template<typename T>
bool LinkedList<T>::Set(size_t idx, T value) {
    auto item = this->Get(idx);
    if (item == nullptr) {
        return false;
    } else {
        *item = value;
        return true;
    }
}

/// Returns false if no such item existed, and true if one did
template<typename T>
bool LinkedList<T>::Remove(size_t idx) {
    LinkedListEntry<T> *item = first;
    if (item == nullptr) {
        return false;
    }
    LinkedListEntry<T> *prev = first;
    for (size_t current_idx = 0; current_idx < idx; ++current_idx) {
        prev = item;
        item = item->next;
        if (item == nullptr) {
            return false;
        }
    }
    prev->next = item->next;
    return true;
}

template<typename T>
class LinkedListEntry {
    friend class LinkedList<T>;

public:
    T data;
protected:
    LinkedListEntry<T> *next;
};

#endif