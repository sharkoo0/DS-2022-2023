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
void keepProducts(Node<T>* first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node<T>* l1 = first;
    Node<T>* l2 = first->next;
    Node<T>* current = first->next->next;

    while (current != nullptr) {
        if (current->data != l1->data + l2->data) {
            //current->data != l1->data + l2->data - makeFib
            Node<T>* toDelete = current;
            l2->next = current->next;
            delete toDelete;
            current = l2->next;
        } else {
            l1 = l2;
            l2 = current;
            current = current->next;
        }
    }
}

int main() {
    Node<int> *l1 = new Node<int>{1,
                        new Node<int>{1,
                            new Node<int>{2,
                                new Node<int>{2,
                                    new Node<int>{2,
                                        new Node<int>{3,
                                            new Node<int>{5,
                                                new Node<int>{9,nullptr}}}}}}}};

    print(l1);
    keepProducts(l1);
    print(l1);

    return 0;
}