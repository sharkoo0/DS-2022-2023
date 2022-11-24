#include "DLL.h"

int main() {
    Node<int>* first = new Node<int>{1, nullptr, nullptr};
    pushFront(first, 0);
    // print(first);
    pushBack(first, 4);
    // print(first);
    pushAfter(first->next, 2);
    // print(first);
    pushBefore(first->next->next->next, 3);
    print(first);
    printReverse(first);

    // popFront(first);
    // // print(first);
    // popBack(first);
    // // print(first);
    // popBefore(first, first->next);
    // // print(first);
    // popAfter(first);
    // print(first);
    // printReverse(first);

    deleteList(first);
    print(first);

    return 0;
}