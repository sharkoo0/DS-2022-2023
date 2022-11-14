#include <iostream>

template <class T>
struct Node {
    T data;
    Node* next;
};

template <class T>
void print(Node<T>* first) {
    if (first == nullptr) {
        std::cout << "nullptr\n";
        return;
    }

    std::cout << first->data << " ";
    print(first->next);
}

template <class T>
void reverse(Node<T>*& first, int n) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* prev = nullptr;
    Node<T>* current = first;
    Node<T>* next = nullptr;
    int counter = 0;

    while (counter < n && current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        ++counter;
    }

    Node<T>* holder = prev;
    while (holder->next != nullptr) {
        holder = holder->next;
    }

    first = prev;
    holder->next = next;
}

template <class T>
void reverseTwoPointers(Node<T>*& first, Node<T>* end = nullptr) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* prev = end;
    Node<T>* current = first;
    Node<T>* next = nullptr;

    while (current != end) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

template <class T>
void reverseN(Node<T>*& first, int n) {
    if (first == nullptr) {
        return;
    }

    Node<T>* current = first;
    int counter = 0;
    while (counter < n && current != nullptr) {
        current = current->next;
        ++counter;
    }

    reverseTwoPointers(first, current);
}

int main() {
    Node<int> *l1 = new Node<int>{1,
                         new Node<int>{2,
                             new Node<int>{3,
                                 new Node<int>{4,
                                      nullptr}}}};
    Node<int>* temp1 = new Node<int>{5, new Node<int>{6,
                                              new Node<int>{7,
                                                  new Node<int>{8,nullptr}}}};

    l1->next->next->next->next = temp1;

    print(l1);
    // reverse(l1, 4);
    // print(l1);
    reverseN(l1, 4);
    print(l1);

    return 0;
}