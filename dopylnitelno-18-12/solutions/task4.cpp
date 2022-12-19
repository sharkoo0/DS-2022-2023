#include "../toDottyFuncs.h"

int sumTree(Node<int>* root)
{
    if (!root)
        return 0;

    return root->data + sumTree(root->left) + sumTree(root->right);
}

int countSubTrees(Node<int>* root, int k)
{
    if(!root)
        return 0;
    
    if (sumTree(root) == k)
    {
        return 1 + countSubTrees(root->left, k) + countSubTrees(root->right, k);
    }

    return countSubTrees(root->left, k) + countSubTrees(root->right, k);
}

int main() {
    Node<int>* root = new Node<int>{7, 
                            new Node<int>{3,
                                new Node<int>{2, nullptr, nullptr},
                                new Node<int>{6, nullptr, nullptr}},
                            new Node<int>{2, 
                                nullptr, 
                                new Node<int>{11, nullptr, nullptr}}};

    std::cout << countSubTrees(root, 100) << std::endl;


    return 0;
}

