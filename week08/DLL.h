#pragma once
#include <iostream>

template <class T>
struct Node {
    T data;
    Node* next;
    Node* prev;
};

template <class T>
void pushFront(Node<T>*& first, const T& element) {
    if (first == nullptr) {
        first = new Node<T>{element, nullptr, nullptr};
        return;
    }

    // Node<T>* holder = first;
    // first = new Node<T>{element, holder, nullptr};
    // holder->prev = first;

    Node<T>* newNode = new Node<T>{element, first, first->prev};
    first->prev = newNode;
    first = newNode;
}

template <class T>
void pushBefore(Node<T>* before, const T& element) {
    if (before == nullptr) {
        return;
    }
    
    if (before->prev == nullptr) {
        pushFront(before, element);
        return;
    }

    Node<T>* newBefore = before->prev;
    Node<T>* newNode = new Node<T>{element, before, newBefore};
    newBefore->next = newNode;
    before->prev = newNode;
}

template <class T>
void pushAfter(Node<T>* after, const T& element) {
    if (after == nullptr) {
        return;
    }
    if (after->next == nullptr) {
        pushBack(after, element);
        return;
    }
    Node<T>* newNext = after->next;
    Node<T>* newNode = new Node<T>{element, newNext, after};
    newNext->prev = newNode;
    after->next = newNode;
}

template <class T>
void pushBack(Node<T>*& first, const T& element) {
    if (first == nullptr) {
        first = new Node<T>{element, nullptr, nullptr};
        return;
    }

    Node<T>* temp = first;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new Node<T>{element, nullptr, temp};
}

template <class T>
void popFront(Node<T>*& first) {
    if (first == nullptr) {
        return;
    }
    if (first->next == nullptr) {
        delete first;
        first = nullptr;
        return;
    }

    first = first->next;
    delete first->prev;
    first->prev = nullptr;
}

template <class T>
void popBack(Node<T>*& first) {
    if (first == nullptr) {
        return;
    }
    if (first->next == nullptr) {
        delete first;
        first = nullptr;
        return;
    }

    Node<T>* temp = first;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;
}

template <class T>
void popBefore(Node<T>*& first, Node<T>*& before) {
    if (before == nullptr || before->prev == nullptr) {
        return;
    }

    Node<T>* toDelete = before->prev;

    Node<T>* newBefore = toDelete->prev;
    before->prev = newBefore;
    if (newBefore != nullptr) {
        newBefore->next = before;
    }
    
    if (first == toDelete) {
        first = before;
    }
    delete toDelete;
}

template <class T>
void popAfter(Node<T>* after) {
    if (after == nullptr || after->next == nullptr) {
        return;
    }

    Node<T>* toDelete = after->next;
    after->next = toDelete->next;

    if (after->next != nullptr) {
        after->next->prev = after;
    }

    delete toDelete;
}

template <class T>
void print(Node<T>* first) {
    if (first == nullptr) {
        std::cout << "nullptr\n";
        return;
    }

    std::cout << first->data << " -> ";
    print(first->next);
}

template <class T>
void printReverse(Node<T>* first) {
    Node<T>* last = first;
    while (last->next != nullptr) {
        last = last->next;
    }

    while (last != nullptr) {
        std::cout << last->data << " <- ";
        last = last->prev;
    }

    std::cout << "nullptr\n";
}

template <class T>
void deleteList(Node<T>*& first) {
    while (first != nullptr) {
        popFront(first);
        popBack(first);
    }
}