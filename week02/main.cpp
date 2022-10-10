#include <iostream>
#include "list.h"

int main() {
    SLL<int> list;
    list.pushFront(1);
    list.pushFront(2);
    list.pushFront(3);
    list.pushFront(4);

    list.print();

    list.popFront();
    list.popFront();
    list.popFront();
    list.popFront();
    list.print();

    SLL<int> secondList(list);
    secondList.print();

    return 0;
}