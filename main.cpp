#include <iostream>
#include "linkedlist.h"

int main() {
    LinkedList<int> list;
    for (int i = 0; i <= 100; ++i) {
        list.Push(i);
    }
    for (int i = 1; i <= 50; ++i) {
        list.Remove(i);
    }
    for (int i = 1; i <= 25; ++i) {
        list.Set(i, 0);
    }
    for (int i = 0; i <= 50; ++i) {
        auto val = *list.Get(i);
        std::cout << std::to_string(val) << std::endl;
    }
    return 0;
}