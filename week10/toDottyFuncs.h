#pragma once
#include <iostream>

template <class T>
struct Node{
    T data;
    Node* left;
    Node* right;
};

template <typename T>
void toDotty(Node<T> *root, std::ostream &out)
{
    out << "Digraph G{\n";
    printDotStatements(root,out);
    out << "}";
}

template <typename T>
void printDotStatements(Node<T> *root, std::ostream &out)
{
    if(root==nullptr)
    {
        return;
    }

    printDotStatements(root->left,out);
    printDotStatements(root->right,out);

    out << (long)root << "[label=\"" << root->data << "\"];\n";

    if(root->right != nullptr)
    {
        out << (long)root << "->" << (long)(root->right) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->left != nullptr)
    {
        out << (long)root << "->" << (long)(root->left) << "[color=\"red\",label=\"L\"];" << std::endl;
    }
}
