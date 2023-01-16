#include <iostream>
#include <vector>

template <class T>
struct Node {
    T data;
    std::vector<Node<T>*> children;
};

template <class T>
void deleteNode(Node<T>*& root) {
    if (root == nullptr) {
        return;
    }

    for (Node<T>* el : root->children) {
        deleteNode(el);
    }

    delete root;
    root = nullptr;

    // root->children.clear();
}

template <class T>
void printTree(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << "(";
    for (Node<T>* el : root->children) {
        printTree(el);
    }
    std::cout << ") ";
}

template <class T>
void addElement(Node<T>* root, const T& data, const T& element) {
    if (root == nullptr) {
        return;
    }

    if (root->data == data) {
        root->children.push_back(new Node<T>{element, std::vector<Node<T>*>()});
        return;
    }

    for (Node<T>* el : root->children) {
        addElement(el, data, element);
    }
}

template <class T>
void removeElement(Node<T>* root, const T& toRemove) {
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < root->children.size(); ++i) {
        if (root->children[i]->data == toRemove) {
            
            deleteNode(root->children[i]);
            for (int j = i; j < root->children.size() - 1; ++j) {
                root->children[j] = root->children[j + 1];
            }
            root->children.pop_back();

            return;
        }
        removeElement(root->children[i], toRemove);
    }
}

int main() {
    Node<int>* root = new Node<int>{1};
    addElement(root, 1, 2);
    addElement(root, 1, 3);
    addElement(root, 1, 4);
    addElement(root, 1, 5);
    addElement(root, 2, 7);
    addElement(root, 2, 7);
    addElement(root, 2, 7);
    printTree(root);
    std::cout << std::endl;
    removeElement(root, 7);
    printTree(root);
    
    return 0;
}