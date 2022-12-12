#include "toDottyFuncs.h"
#include <fstream>
#include <vector>

//TASK 1
template <class T>
int treeHeight(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

//TASK 2
template <class T>
bool isLeaf(Node<T>* root) {
    return root->left == nullptr && root->right == nullptr;
}

template <class T>
void printAllPathsToLeaf(Node<T>* root, std::vector<T>& path) {
    if (root == nullptr) {
        return;
    }

    path.push_back(root->data);

    if (isLeaf(root)) {
        for (T data : path) {
            std::cout << data << " -> ";
        }
        std::cout << "nullptr\n";
    }

    printAllPathsToLeaf(root->left, path);
    printAllPathsToLeaf(root->right, path);

    path.pop_back();
}

//TASK 3
template <class T>
T sumElements(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }

    return root->data + sumElements(root->left) + sumElements(root->right);
}

template <class T>
bool isSumTree(Node<T>* root) {
    if (root == nullptr) {
        return true;
    }

    if (isLeaf(root)) {
        return true;
    }

    T sum = sumElements(root) - root->data;

    return root->data == sum && isSumTree(root->left) && isSumTree(root->right);
}

//TASK 4
template <class T>
void convert(Node<T>* root) {
    if ( root == nullptr) {
        return;
    }
    T sum = sumElements(root) - root->data;
    root->data = sum;
    convert(root->left);
    convert(root->right);
}

//TASK 5
template <class T>
bool isSymmetricHelper(Node<T>* left, Node<T>* right) {
    if (left == nullptr && right == nullptr) {
        return true;
    }

    if (left != nullptr && right == nullptr) {
        return false;
    }
    
    if (left == nullptr && right != nullptr) {
        return false;
    }

    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

template <class T>
bool isSymmetric(Node<T>* root) {
    if (root == nullptr) {
        return true;
    }

    return isSymmetricHelper(root->left, root->right);
}
int main() {

    std::ofstream ofs("binaryTree.dot");

    Node<int>* root = new Node<int>{43,
                        new Node<int>{9,
                            new Node<int>{4, nullptr, nullptr},
                            new Node<int>{5, nullptr, nullptr}},
                        new Node<int>{13, 
                            new Node<int>{6, nullptr, nullptr},
                            new Node<int>{7, nullptr, nullptr}}};

    std::ofstream dot("binaryTree.dot");
    toDotty(root, dot);

    std::cout << treeHeight(root) << std::endl;

    std::vector<int> v;
    printAllPathsToLeaf(root, v);

    std::cout << isSumTree(root) << std::endl;

    convert(root);

    toDotty(root, dot);

    convert(root);

    toDotty(root, dot);

    std::cout << std::boolalpha << isSymmetric(root) << std::endl;

    return 0;
}