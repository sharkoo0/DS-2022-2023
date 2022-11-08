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

Node* createSequence(int n) {
    if (n == 1) {
        return new Node{1, nullptr};
    }

    Node* result = new Node{1, nullptr};
    int counter = 2;
    int elementCounter = 1;
    Node* current = result;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < counter && elementCounter < n; ++j, ++elementCounter) {
            current->next = new Node{counter, nullptr};
            current = current->next;
        }
        ++counter;
    }

    return result;
}

int main() {
    Node* first = createSequence(4);
    printList(first);

    return 0;
}