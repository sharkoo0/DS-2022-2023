#pragma once
#include <iostream>

template <class T = int>
struct Node {
    T data;
    Node* nextChild;
    Node* nextSibling;
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

    printDotStatements(root->nextChild,out);
    printDotStatements(root->nextSibling,out);

    out << (long)root << "[label=\"" << root->data << "\"];\n";

    if(root->nextSibling != nullptr)
    {
        out << (long)root << "->" << (long)(root->nextSibling) << "[color=\"blue\",label=\"R\"];" << std::endl;
    }
    if(root->nextChild != nullptr)
    {
        out << (long)root << "->" << (long)(root->nextChild) << "[color=\"red\",label=\"L\"];" << std::endl;
    }
}
