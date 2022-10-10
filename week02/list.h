#pragma once
#include <iostream>

template <class T>
class SLL {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* first;

private:
    void copy(const SLL& other) {
        if (other.first == nullptr) {
            first = nullptr;
            return;
        }
        first = new Node{other.first->data, nullptr};
        Node* temp = first;
        Node* otherTemp = other.first->next;

        while(otherTemp != nullptr) {
            temp->next = new Node{otherTemp->data, nullptr};
            temp = temp->next;
            otherTemp = otherTemp->next;
        }
    }
    void erase() {
        if (first == nullptr) {
            return;
        }
        Node* holder = first->next;
        while(holder != nullptr) {
            delete first;
            first = holder;
            holder = holder->next;
        }
        delete first;
    }
    void printHelper(Node* first) const {
        if (first == nullptr) {
            std::cout << "nullptr\n";
            return;
        }

        std::cout << first->data << " -> ";
        printHelper(first->next);
    }

public:
    SLL() : first(nullptr) {}
    SLL(const T& element) : first(new Node{element, nullptr}) {}
    SLL(const SLL& other) { 
        copy(other);
    }
    SLL& operator=(const SLL& other) {
        if (this != &other) {
            erase();
            copy(other);
        }

        return *this;
    }
    ~SLL() {
        erase();
    }

    void pushFront(const T& element) {
        first = new Node{element, first};
    }
    void popFront() {
        if (first == nullptr) {
            return;
        }
        Node* holder = first;
        first = first->next;
        delete holder;
    }

    void push(const T& element, int index);
    void pop();

    void pushBack(const T& element);
    void popBack();

    void print() const {
        printHelper(first);
    }

    void reverse() {
        Node* holder = first;
        Node* temp = nullptr;
        Node* prev = nullptr;

        while (holder != nullptr) {
            temp = holder->next;
            holder->next = prev;
            prev = holder;
            holder = temp;
        }
        first = prev;
    }
};