#include <iostream>

//Sorting visualizations
//https://www.sortvisualizer.com/customsort/
//https://www.toptal.com/developers/sorting-algorithms
//https://visualgo.net/en/sorting?slide=1

//quick sort
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int* arr, int left, int right) {
    int pivot = arr[right]; //Червено
    int low = left - 1; //Зелено

    for (int i = left; i <= right - 1; ++i) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[low + 1]);
            ++low;
        }
    }

    swap(arr[right], arr[low + 1]);
    return low + 1;
}

void quickSort(int* arr, int left, int right) {
    for (int j = left; j < right; ++j) {
        int newPivot = partition(arr, left, right);

        quickSort(arr, left, newPivot - 1);
        quickSort(arr, newPivot + 1, right);
    }
}

void printArr(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

//merge sort
struct Node {
    int data;
    Node* next;
};

void split(Node* first, Node*& a, Node*& b) {
    if (first == nullptr) {
        return;
    }
    Node* fast = first->next;
    Node* slow = first;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
            slow = slow->next; 
        }
    }

    a = first;
    b = slow->next;
    slow->next = nullptr;
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

void mergeSort(Node*& first) {
    if (first == nullptr || first->next == nullptr) {
        return;
    }

    Node* a;
    Node* b;

    split(first, a, b);

    mergeSort(a);
    mergeSort(b);

    first = sortedMerge(a, b);
}

int main() {

    int arr[10] = {5, 3, 10, 7, 18, 234, 4, 1, 8, 9};
    printArr(arr, 10);
    quickSort(arr, 0, 9);
    printArr(arr, 10);


    return 0;
}