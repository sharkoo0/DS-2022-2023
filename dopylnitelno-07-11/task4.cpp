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

bool isSorted(Node* first) {
    while (first != nullptr) {
        if (first->next != nullptr) {
            if (first->data > first->next->data) {
                return false;
            }
        }
        first = first->next;
    }

    return true;
}

Node* findMiddleElementInList(Node* first, Node* end) {
    if (first == nullptr) {
        return first;
    }

    Node* slow = first;
    Node* fast = first->next;

    while (fast != nullptr && fast != end) {
        fast = fast->next;
        if (fast != nullptr && fast != end) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node* binarySearch(Node* first, int key, Node* last = nullptr) {
    if (first == nullptr) {
        return first;
    }

    Node* middle = findMiddleElementInList(first, last);
    if (key == middle->data) {
        return middle;
    } else if (key < middle->data) {
        return binarySearch(first, key, middle);
    } else {
        return binarySearch(middle->next, key);
    }
}

int main() {
    Node* first = new Node{1, 
                    new Node{2, 
                    new Node{3, 
                    new Node{4, 
                    new Node{5, nullptr}}}}};

    Node* found = binarySearch(first, 4);
    std::cout << found->next->data << std::endl;
    
    return 0;
}