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
Node<T>* copyList(Node<T>* first) {
    if (first == nullptr) {
        return first;
    }

    Node<T>* result = new Node<T>{first->data, nullptr};
    Node<T>* current = result;
    first = first->next;

    while (first != nullptr) {
        current->next = new Node<T>{first->data, nullptr};
        first = first->next;
        current = current->next;
    }

    return result;
}

template <class T>
void reverse(Node<T>*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* prev = nullptr;
    Node<T>* current = first;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    first = prev;
}

template <class T>
void mirror(Node<T>* first) {
    if (first == nullptr) {
        return;
    }

    Node<T>* copyFirst = copyList(first);
    reverse(copyFirst);

    while (first->next != nullptr) {
        first = first->next;
    }

    first->next = copyFirst;
}

template <class T>
void mirror2(Node<T>*& first) {
    if (first == nullptr) {
        return;
    }

    reverse(first);

    Node<T>* current = first;

    while (current != nullptr) {
        first = new Node<T>{current->data, first};
        current = current->next;
    }
}

int main() {
    Node<int> *l1 = new Node<int>{1,
                         new Node<int>{3,
                             new Node<int>{5,nullptr}}};

    print(l1);
    mirror2(l1);
    print(l1);

    return 0;
}