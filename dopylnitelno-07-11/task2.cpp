#include <iostream>
#include <stack>

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

bool isPalindromeWithStack(Node* first) {
    if (first == nullptr || first->next == nullptr) {
        return true;
    }

    std::stack<int> s;
    Node* current = first;
    Node* holder = first;
    while (current != nullptr) {
        s.push(current->data);
        current = current->next;
    }

    // current = first;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        if (temp != holder->data) {
            return false;
        }
        holder = holder->next;
    }

    return true;
}

bool equalLists(Node* first, Node* second) {
    Node* currentFirst = first;
    Node* currentSecond = second;

    while (currentFirst != nullptr) {
        if (currentSecond == nullptr) {
            return false;
        }
        if (currentFirst->data != currentSecond->data) {
            return false;
        }
        currentFirst = currentFirst->next;
        currentSecond = currentSecond->next;
    }

    return true;
}

void reverseList(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* current = first;
    Node* prev = nullptr;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    first = prev;
}

bool isPalindromeWithoutStack(Node* first) {
    Node* reversedList = first;
    reverseList(reversedList);
    return equalLists(first, reversedList);
}

int main() {
    Node* palindrome = new Node{2, 
                        new Node{3, 
                        new Node{3, 
                        new Node{2, nullptr}}}};

    std::cout << isPalindromeWithStack(palindrome) << std::endl;
    std::cout << isPalindromeWithoutStack(palindrome) << std::endl;

    return 0;
}