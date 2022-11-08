#include <iostream>

struct Node {
    int data;
    Node* next;
};

Node* findMiddle(Node* first)
{
    if (!first)
        throw "Empty list.";

    Node* slow = first;
    Node* fast = first->next;

    while (fast && fast->next)
    {   
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printMiddleElement(Node* first) {
    try  {
        std::cout << findMiddle(first)->data << std::endl;
    } catch (const char* message) {
        std::cout << message << std::endl;
    }
}

void deleteMiddleElement(Node* first) {
    if(first == nullptr)
        return;

    Node* temp = first;
    Node* middle = findMiddle(first);

    while(temp->next != middle){
        temp = temp->next;
    }

    temp->next = middle->next;
    delete middle;
}

void deleteMiddleElement2(Node*& first) {
    if (first == nullptr) {
        return;
    }
    
    Node* slow = first;
    Node* fast = first->next;
    Node* toDelete = nullptr;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            toDelete = slow;
            slow = slow->next;
        }
    }

    if (toDelete == nullptr) {
        first = first->next;
        delete slow;
        return;
    }

    toDelete->next = slow->next;
    delete slow;
}

void printList(Node* first){
    if(first == nullptr){
        std::cout << "nullptr\n";
        return;
    }

    std::cout << first->data << " -> ";
    return printList(first->next);
}

void reverse(Node*& first)
{
    if (!first)
        return;

    Node* prev = nullptr;
    Node* curr = first;
    Node* next = first;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    first = prev;
}

void add1(Node*& first)
{
    if (!first)
    {
        first = new Node{1, nullptr};
        return;
    }

    reverse(first);
    Node* curr = first;
    while (curr)
    {
        if (curr->data + 1 >= 10)
            curr->data = 0;
        else
        {
            curr->data += 1;
            break;
        }
        curr = curr->next;
    }
    reverse(first);
    if (!curr)
    {
        first = new Node{1, first};
    }
}

void mergeAlternate(Node*& first, Node*& second) {
    Node* pCurrent = first;
    Node* qCurrent = second;
    Node* pNext;
    Node* qNext;

    while (pCurrent != nullptr && qCurrent != nullptr) {
        pNext = pCurrent->next;
        qNext = qCurrent->next;

        qCurrent->next = pNext;
        pCurrent->next = qCurrent;

        pCurrent = pNext;
        qCurrent = qNext;
    }

    second = qCurrent;
}

int main() {
    Node* first =   new Node{9, 
                    new Node{9, 
                    new Node{9, nullptr}}};

    Node* second =   new Node{1, 
                    new Node{1, 
                    new Node{1, 
                    new Node{1, 
                    new Node{1, 
                    new Node{1, nullptr}}}}}};
    mergeAlternate(first, second);
    printList(first);
    printList(second);
    // printMiddleElement(first);

    // deleteMiddleElement2(first);

    // printList(first);
    return 0;
}