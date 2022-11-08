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

bool hasCycle(Node* first) { //endless loop
    if (first == nullptr) {
        return false;
    }

    Node* slow = first;
    Node* fast = first->next;

    while (fast != nullptr) {
        if (fast == slow) {
            return true;
        }
        fast = fast->next;
        if (fast != nullptr) {
            if (fast == slow) {
                return true;
            }
            fast = fast->next;
            slow = slow->next;
        }
        if (slow == nullptr) {
            return false;
        }
    }

    return fast == slow;
}

int main() {
    Node* first = new Node{1, new Node{2, nullptr}};
    Node* repeat = new Node{3, new Node{4, nullptr}};
    first->next->next = repeat;
    repeat->next->next = new Node{5, repeat};

    std::cout << hasCycle(first) << std::endl;

    return 0;
}