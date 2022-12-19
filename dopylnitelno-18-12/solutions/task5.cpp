#include "../toDottyFuncs.h"
#include <fstream>

template <typename T>
void reverse(Node<T>* root){
    if(root == nullptr){
        return;
    }
    Node<T>* temp = root->left;

    root->left = root->right;
    root->right = temp;
    reverse(root->left);
    reverse(root->right);
}

int main() {
    std::ofstream dot("reverseTree.dot");

    Node<int>* root = new Node<int>{1, 
                        new Node<int>{10,
                            new Node<int>{6, nullptr, nullptr},
                            new Node<int>{2, nullptr, nullptr}},
                        new Node<int>{7, 
                            nullptr, 
                            new Node<int>{5, nullptr, nullptr}}};

    reverse(root);
    toDotty(root, dot);

    return 0;
}