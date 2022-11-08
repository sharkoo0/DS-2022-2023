#include <algorithm>
#include <iostream>
#include <cmath>
#include <stack>

template <typename T>
struct Node{
    T data;
    Node* next;
};

void print(Node<int>* n){
    while(n != nullptr){
        std::cout << n->data << " -> ";
        n = n->next;
    }
    std::cout << "nullptr"<< std::endl;
}

template <class T>
void deleteList(Node<T>*& node) {
    Node<T>* temp = node;
    while (node != nullptr) {
        node = node->next;
        delete temp;
        temp = node;
    }
}

template<class T>
void reverse(Node<T>*& first, Node<T>* curr, Node<T>* prev, Node<T>* next){
    if(curr == nullptr){
        first = prev;
        return;
    }

    next = curr->next;
    curr->next = prev;
    return reverse(first, next, curr, next);
}

template <class T>
Node<T>* copy(Node<T>* first){
    if(first == nullptr){
        return nullptr;
    }
    return new Node<T>{first->data, copy(first->next)};
}

//TASK 1
void task1(Node<int>* first){
    Node<int>* current = first->next;
    Node<int>* previous = first;

    Node<int>* temp = first;
    int size = 0;
    while(temp != nullptr){
        temp = temp->next;
        size++;
    }
    temp = first;
    for(int i = size - 1; i>= 0; i--){
        for(int j = 0; j < i; j++){
            if(abs(current->data) < abs(previous->data)){
                std::swap(current->data, previous->data);
            }

            current = current->next;
            previous = previous->next;
        }
        current = first->next;
        previous = first;
    }
}

void task1_2(Node<int>*& head) {
    Node<int>* curr = head;
    while(curr->next != nullptr) {
        if (curr->next->data < 0) {
            Node<int>* temp = curr->next;
            curr->next = temp->next;
            temp->next = head;
            head = temp;
        }
        else {
            curr = curr->next;
        }
    }
}

//TASK 2
template <typename T>
bool isPalindrome(Node<T>* first)
{
    if(first == nullptr)
    {
        return true;
    }

    std::stack<T> stack;
    Node<T>* temp = first;

    while(temp != nullptr)
    {
        stack.push(temp->data);
        temp = temp->next;
    }

    temp = first;

    while(temp != nullptr && !stack.empty())
    {
        if(temp->data != stack.top())
        {
            return false;
        }
        stack.pop();
        temp = temp->next;
    }

    return true;
}

template<class T>
bool isPalindromeNoStack(Node<T>* first){
    if(first == nullptr || first->next == nullptr)
        return true;

    Node<T>* temp = copy(first);
    reverse<T>(temp, temp, nullptr, temp);
    while(first != nullptr){
        if(first->data != temp->data){
            return false;
        }
        first = first->next;
        temp = temp->next;
    }
    return true;
}

//TASK 3 
template<typename T>
bool task3(Node<T>* first)
{
    if (first==nullptr || first->next == nullptr)
    {
        return false;
    }
    
    Node<T>* slow = first;
    Node<T>* fast = first->next->next;
    while (slow && fast && fast->next)
    {
        if (slow == fast)
        {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    

    return false;
}

//TASK 4
template <class T>
Node<T>* binarySearch(Node<T>* head, T value, Node<T>* tail = nullptr)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node<T>* slow = head;
    Node<T>* fast = head->next;
    while(fast != tail)
    {
        fast = fast->next;
        if (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    if (value > slow->data)
    {
        return binarySearch(slow->next, value);
    }
    else if (value < slow->data)
    {
        return binarySearch(head, value, slow);
    }
    return slow;
}

//TASK 6
Node<int>* createRow(int k)
{
    if (k <= 0)
        return nullptr;

    Node<int>* head = new Node<int> {1 , nullptr};
    Node<int>* listIter = head;

    int enteredNums = 1;

    for (int i = 2; i < k; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if(enteredNums >= k)
                return head;

            listIter->next = new Node<int> {i, nullptr};
            listIter = listIter->next;
            enteredNums++;
        }
    }

    return head;
}

//TESTS
void TEST_TASK_1() {
    Node<int> * n = new Node<int>{-3, 
                    new Node<int>{1, 
                    new Node<int>{2, 
                    new Node<int>{10, 
                    new Node<int>{11, 
                    new Node<int>{-7, nullptr}}}}}};

    std::cout << "===============\n";
    std::cout << "TEST TASK 1\n";
    std::cout << "===============\n";
    std::cout << "Sort the following list by absolute values: ";
    print(n);
    std::cout << "Sorted by absolute values: ";
    task1(n);
    print(n);
    std::cout << "Swapping the element to get a fully sorted list: ";
    task1_2(n);
    print(n);
}

void TEST_TASK_2() {
    Node<int>* palindrome = new Node<int>{2, 
                            new Node<int>{4, 
                            new Node<int>{1, 
                            new Node<int>{4, 
                            new Node<int>{2, nullptr}}}}};

    Node<int>* notPalindrome = new Node<int>{1, 
                                new Node<int>{2, 
                                new Node<int>{3, 
                                new Node<int>{4, 
                                new Node<int>{5, nullptr}}}}};

    std::cout << "===============\n";
    std::cout << "TEST TASK 2\n";
    std::cout << "===============\n"; 
    std::cout << "Test with following list: ";
    print(palindrome);
    std::cout << "Is the list palindrome(with stack): " << std::boolalpha << isPalindrome(palindrome) << std::endl;
    std::cout << "Is the list palindrome(without stack): " << std::boolalpha << isPalindrome(palindrome) << std::endl;

    std::cout << "Test with following list: ";
    print(notPalindrome);
    std::cout << "Is the list palindrome(with stack): " << std::boolalpha << isPalindrome(notPalindrome) << std::endl;
    std::cout << "Is the list palindrome(without stack): " << std::boolalpha << isPalindrome(notPalindrome) << std::endl;
}

void TEST_TASK_3() {
    Node<int>* first = new Node<int>{1, new Node<int>{2, nullptr}};
    Node<int>* repeat = new Node<int>{3, new Node<int>{4, nullptr}};
    first->next->next = repeat;
    repeat->next->next = new Node<int>{5, repeat};
    //To make the list without cycle, just change the next pointer of the repeat->next->next to be nullptr

    std::cout << "===============\n";
    std::cout << "TEST TASK 3\n";
    std::cout << "===============\n"; 
    std::cout << "Has cycle: " << std::boolalpha << task3(first) << std::endl;
}

void TEST_TASK_4() {
    Node<int>* first = new Node<int>{1, 
                        new Node<int>{2, 
                        new Node<int>{3, 
                        new Node<int>{4, 
                        new Node<int>{4, 
                        new Node<int>{4, 
                        new Node<int>{5, nullptr}}}}}}};

    std::cout << "===============\n";
    std::cout << "TEST TASK 4\n";
    std::cout << "===============\n"; 
    std::cout << "We are searching for '4' in the following list using binary search method: ";
    print(first);
    Node<int>* result = binarySearch<int>(first, 4);
    std::cout << "Element found: " << std::boolalpha << ((result == nullptr) ? false : true) << std::endl;
    std::cout << "We are searching for '123' in the following list using binary search method: ";
    print(first);
    result = binarySearch<int>(first, 123);
    std::cout << "Element found: " << std::boolalpha << ((result == nullptr) ? false : true) << std::endl;
}

void TEST_TASK_6() {
    Node<int>* result = createRow(15);
    
    std::cout << "===============\n";
    std::cout << "TEST TASK 6\n";
    std::cout << "===============\n"; 
    std::cout << "From the following row we want a list with first 15 elements: 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 ...\n";
    print(result);
    std::cout << "From the following row we want a list with first -1 elements: 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 ...\n";
    result = createRow(-1);
    print(result);
}

void RUN_TESTS() {
    TEST_TASK_1();
    TEST_TASK_2();
    TEST_TASK_3();
    TEST_TASK_4();
    TEST_TASK_6();
}

int main() {
    RUN_TESTS();
}