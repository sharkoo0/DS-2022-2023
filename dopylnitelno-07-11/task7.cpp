#include <iostream>

struct Node {
    int data;
    Node* next;
};

void printList(Node* first) {
    while (first) {
        std::cout << first->data << " -> ";
        first = first->next;
    }
    std::cout << "nullptr\n";
}

Node* sortedMerge(Node* a, Node* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

    Node* result;

    if (a->data <= b->data) {
        result = new Node{a->data, nullptr};
        result->next = sortedMerge(a->next, b);
    } else {
        result = new Node{b->data, nullptr};
        result->next = sortedMerge(a, b->next);
    }

    return result;
}

void orderList(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* current = first->next;
    Node* prev = first;
    Node* holder = first;

    while (current != nullptr) {
        if (prev->data > current->data) {
            prev->next = nullptr;
            first = sortedMerge(holder, current);
            break;
        }
        current = current->next;
        prev = prev->next;
    }
}


int main() {
    Node* first = new Node{1, 
                    new Node{6, 
                    new Node{7, 
                    new Node{10, 
                    new Node{2, 
                    new Node{4, 
                    new Node{8, nullptr}}}}}}};

    orderList(first);
    printList(first);

    return 0;
}