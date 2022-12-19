#include "../toDottyFuncs.h"
#include <fstream>

template <class T>
void printNodesAtLevel(Node<T>* root, int k) {
    if(root == nullptr)
    {
        return;
    }
    if(k == 0){
        std::cout << root->data << " ";
        return;
    }
    printNodesAtLevel(root->left, k-1);
    printNodesAtLevel(root->right, k-1);
}

int main() {
    std::ofstream dot("task2.dot");
    Node<int>* root = new Node<int>{1,
                        nullptr, 
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                new Node<int>{7, nullptr, nullptr}, 
                                new Node<int>{4,
                                    nullptr,
                                    new Node<int>{5, nullptr, nullptr}}}}};

    toDotty(root, dot);

    printNodesAtLevel(root, 3);

}