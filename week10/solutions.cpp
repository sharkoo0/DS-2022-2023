#include "toDottyFuncs.h";
#include <fstream>
#include <vector>

template <class T>
int treeHeight(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr) {
        return 1 + treeHeight(root->right);
    }
    if (root->right == nullptr) {
        return 1 + treeHeight(root->left);
    }

    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

template <class T>
bool isLeaf(Node<T>* root) {
    return root->left == nullptr && root->right == nullptr;
}

template <class T>
void printPathsToLeaf(Node<T>* root, std::vector<T>& paths) {
    if (root == nullptr) {
        return;
    }

    paths.push_back(root->data);

    if (isLeaf(root)) {
        for (int data : paths) {
            std::cout << data << " -> ";
        }
        std::cout << "nullptr\n";
    }

    printPathsToLeaf(root->left, paths);
    printPathsToLeaf(root->right, paths);

    paths.pop_back();
}

template <class T>
int sumTreeHelper(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }

    int left = sumTreeHelper(root->left);
    int right = sumTreeHelper(root->right);

    if (left != INT32_MIN && right != INT32_MIN && root->data == left + right) {
        return 2 * root->data;
    }

    return INT32_MIN;
}

template <class T>
bool isSumTree(Node<T>* root) {
    return sumTreeHelper(root) != INT32_MIN;
}

template <class T>
int transform(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    int left = transform(root->left);
    int right = transform(root->right);

    int old = root->data;

    root->data = left + right;

    return root->data + old;
}

template <class T>
bool isTreeSymmetricHelper(Node<T>* left, Node<T>* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }

    return (left != nullptr && right != nullptr) 
            && isTreeSymmetricHelper(left->left, right->right)
            && isTreeSymmetricHelper(left->right, right->left);
}

template <class T>
bool isTreeSymmetric(Node<T>* root) {
    if (root == nullptr) {
        return true;
    }

    return isTreeSymmetricHelper(Root->left, root->right);
}

int main() {
    std::ofstream ofs("binaryTree.dot");

    Node<int>* root = new Node<int>{44,
                    new Node<int>{9,
                        new Node<int>{4, nullptr, nullptr},
                        new Node<int>{5, nullptr, nullptr}},
                    new Node<int>{13, 
                        new Node<int>{6, nullptr, nullptr},
                        new Node<int>{7, nullptr, nullptr}}};

    std::cout << isSumTree(root) << std::endl;
    transform(root);

    // std::cout << treeHeight(root) << std::endl;

    toDotty<int>(root, ofs);

    std::vector<int> v;
    printPathsToLeaf(root, v);

    
    
    

    return 0;
}