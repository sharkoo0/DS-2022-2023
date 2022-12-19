#include "../toDottyFuncs.h"
#include <fstream>

template <class T>
void insertIntoBST(Node<T>*& root, const T& value) {
    if (root == nullptr) {
        root = new Node<T>{value, nullptr, nullptr};
        return;
    }

    if (value <= root->data) {
        insertIntoBST(root->left, value);
    } else {
        insertIntoBST(root->right, value);
    }
}

template <class T>
void deleteBST(Node<T>*& root) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        delete root;
        root = nullptr;
        return;
    }

    deleteBST(root->left);
    deleteBST(root->right);
}

template <class T>
void convertToBSTHelper(Node<T>* root, Node<T>*& result) {
    if (root == nullptr) {
        return;
    }

    insertIntoBST(result, root->data);
    convertToBSTHelper(root->left, result);
    convertToBSTHelper(root->right, result);
}

template <class T>
void convertToBST(Node<T>*& root) {
    Node<T>* result = nullptr;
    convertToBSTHelper(root, result);

    deleteBST(root);
    root = result;
}

int main() {
    std::ofstream dot("convert.dot");
    Node<int>* root = new Node<int>{10,
                        nullptr, 
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                new Node<int>{17, nullptr, nullptr}, 
                                new Node<int>{14,
                                    nullptr,
                                    new Node<int>{-5, nullptr, nullptr}}}}};
// toDotty(root, dot);
    convertToBST(root);

    toDotty(root, dot);
    return 0;
}