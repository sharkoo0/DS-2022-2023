#include "../toDottyFuncs.h"
#include <fstream>

template<class T>
bool areEqual(Node<T>* root1, Node<T>* root2){
    if(root1 == nullptr && root2 == nullptr){
        return true;
    }

    if(root1 == nullptr || root2 == nullptr){
        return false;
    }

    return root1->data == root2->data && 
            areEqual(root1->left, root2->left) &&
            areEqual(root1->right, root2->right);
}

template<class T>
bool isSubTree(Node<T>* tree, Node<T>* subtree){
    if(subtree == nullptr){
        return true;
    }
    if(tree == nullptr){
        return false;
    }

    bool flag = false;
    if (tree->data == subtree->data) {
        flag = areEqual(tree, subtree);
    }

    return flag || isSubTree(tree->left, subtree) || isSubTree(tree->right, subtree);
}

int main() {
    std::ofstream dot("tree.dot");
    Node<int>* root = new Node<int>{1,
                        nullptr, 
                        new Node<int>{2, 
                            nullptr, 
                            new Node<int>{3,
                                new Node<int>{7, nullptr, nullptr}, 
                                new Node<int>{4,
                                    nullptr,
                                    new Node<int>{5, nullptr, nullptr}}}}};

    Node<int>* source = new Node<int>{4, 
                            nullptr,
                            new Node<int>{5, nullptr, nullptr}};

    std::cout << std::boolalpha << isSubTree(root, source) << std::endl; 
    
    toDotty(root, dot);


    return 0;
}