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
void fillGaps(Node<T>* first) {
    if (first == nullptr ||first->next == nullptr) {
        return;
    }

    Node<T>* current = first;

    while (current->next != nullptr) {
        if (current->data / 2 != current->next->data) {
            // Node<T>* temp = new Node<T>{current->data / 2, current->next};
            // current->next = temp;
            current->next = new Node<T>{current->data / 2, current->next};
        }
        current = current->next;
    }
}

int main() {
    Node<int> *l1 = new Node<int>{256,
                         new Node<int>{32,
                             new Node<int>{16,
                                new Node<int>{1,nullptr}}}};


    print(l1);
    fillGaps(l1);
    print(l1);

    return 0;
}