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
        const int val = *list.Get(i);
        int target;
        if (i <= 25) target = 0;
        else target = i * 2;
        std::cout << "val: " << std::to_string(val) << " target: "<< std::to_string(target) << std::endl;
        if (target != val) {
            std::exit(1);
        }
    }
    return 0;
}
