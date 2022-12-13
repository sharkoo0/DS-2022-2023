#include "toDottyFuncs.h"
#include <fstream>

template <class T>
void addSibling(Node<T>* root, const T& siblingData, int level, int currentLevel = 0) {
    if (level == 0) {
        return;
    }

    if (root == nullptr) {
        return;
    }

    if (level == currentLevel) {
        root->nextSibling = new Node<T>{siblingData, nullptr, root->nextSibling};
        return;
    }

    addSibling(root->nextChild, siblingData, level, currentLevel + 1);
}

template <class T>
void addChild(Node<T>* root, const T& childData) {
    if (root == nullptr) {
        return;
    }

    if (root->nextChild == nullptr) {
        root->nextChild = new Node<T>{childData, nullptr, nullptr};
        return;
    }

    addChild(root->nextChild, childData);
}

template <class T>
void removeSibling(Node<T>* root,const T& data) {
    if (root == nullptr) {
        return;
    }

    Node<T>* currentSibling = root;
    while (currentSibling->nextSibling != nullptr) {
        if (currentSibling->nextSibling->data == data) {
            Node<T>* toDelete = currentSibling->nextSibling;
            currentSibling->nextSibling = currentSibling->nextSibling->nextSibling;
            delete toDelete;
            toDelete = nullptr;
            return;
        } else {
            currentSibling = currentSibling->nextSibling;
        }
    }
    
    removeSibling(root->nextChild, data);
}

template <class T>
void deleteSiblings(Node<T>*& root) {
    Node<T>* temp = root;
    while (temp != nullptr) {
        root = root->nextSibling;
        delete temp;
        temp = root;
    }
    root = nullptr;
}

template <class T>
void removeChild(Node<T>* root, const T& data) {
    if (root == nullptr) {
        return;
    }

    if (root->nextChild != nullptr && root->nextChild->data == data) {
        Node<T>* toDelete = root->nextChild;
        root->nextChild = toDelete->nextChild;
        deleteSiblings(toDelete);
        return;
    }

    removeChild(root->nextChild, data);
}

template <class T>
void deleteTree(Node<T>*& root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->nextChild);
    deleteSiblings(root);
}

template <class T>
Node<T>* findElement(Node<T>* root, const T& element) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == element) {
        return root;
    }

    Node<T>* temp = root->nextSibling;
    while (temp != nullptr) {
        if (temp->data == element) {
            return temp;
        }
        temp = temp->nextSibling;
    }
    return findElement(root->nextChild, element);
}

int main() {
    Node<int>* root = new Node<int> {0, new Node<int>{1, new Node<int>{5, nullptr, nullptr}, nullptr}, nullptr};
    addSibling(root, 3, 1);
    addChild(root, 7);
    addSibling(root, 3, 1);
    addSibling(root, 4, 1);
    addSibling(root, 5, 2);
    addSibling(root, 6, 2);
    addSibling(root, 3, 2);
    addSibling(root, 8, 2);
    removeSibling(root, 3);
    removeChild(root, 0);
    // removeSibling(root, 9);
    // deleteTree(root);

    Node<int>* found = findElement(root, 7);
    found->data = 17;
    std::cout << (found == nullptr) << std::endl;
    std::cout << (found->nextChild == nullptr) << " " << (found->nextSibling == nullptr) << std::endl;

    std::ofstream dot("n-aryTree.dot");
    toDotty(root, dot);

    return 0;
}