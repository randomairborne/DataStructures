#include "linkedlist.h"
#include <cstddef>

template<typename T>
bool LinkedList<T>::Push(T item) {
    T* a = malloc(sizeof(t));
    if (a == nullptr) {
        return false;
    }
    *a = item;
    if (this.data == nullptr) {
        data = entry;
    } else {
        LinkedListEntry<T> *prev = first;
        while (prev->next != nullptr) {
            prev = prev->next;
        }
        prev->next = entry;
    }
    return true;
}

/// Returns a pointer to the data at this index, or null
template<typename T>
T *LinkedList<T>::Get(std::size_t idx) {
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

/// Returns false if this value is beyond the length of the list, and true if the insert succeeded
template<typename T>
bool LinkedList<T>::Insert(size_t idx, T value) {
    auto previous = this->Get(idx);
    if (previous == nullptr) {
        return false;
    }
    auto entry = new LinkedListEntry<T>;
    entry->data = value;
    entry->next = previous;
    if (idx == 0) {
        first = entry;
    } else {
        auto item = this->Get(idx - 1);
        item->next = entry;
    }
    return true;
}

/// Returns false if no such item existed, and true if it did
template<typename T>
bool LinkedList<T>::Remove(const size_t idx) {
    if (first == nullptr) {
        return false;
    }
    LinkedListEntry<T> *item = first;
    LinkedListEntry<T> *prev = first;
    for (size_t current_idx = 0; current_idx < idx; ++current_idx) {
        prev = item;
        item = item->next;
        if (item == nullptr) {
            return false;
        }
    }
    prev->next = item->next;
    delete item;
    return true;
}
