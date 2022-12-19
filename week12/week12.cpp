#include "toDottyFuncs.h"
#include <fstream>
#include <queue>
#include <vector>

template <class T>
void printLeftView(Node<T>* root, int level, std::vector<T>& v) {
    if (root == nullptr) {
        return;
    }

    if (v.size() <= level) {
        v.push_back(root->data);
    }

    printLeftView(root->right, level + 1, v);
    printLeftView(root->left, level + 1, v);
}

template <class T>
void printVector(const std::vector<T>& v) {
    for (T element : v) {
        std::cout << element << " ";
    }
}

template <class T>
void printLeftView2(Node<T>* root) {
    std::queue<Node<T>*> q;
    q.push(root);
    q.push(nullptr);
    std::cout << root->data << " ";

    while(!q.empty()) {
        Node<T>* temp = q.front();
        q.pop();

        if (temp == nullptr) {
            if (q.empty()) {
                break;
            }
            q.push(nullptr);
            std::cout << q.front()->data << " "; 
        } else {
            if (temp->left != nullptr) {
                q.push(temp->left);
            }

            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
    }
}

template <class T>
bool identical(Node<T>* root1, Node<T>* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    
    if (root1 == nullptr || root2 == nullptr) {
        return false;
    }

    return root1->data == root2->data &&
            identical(root1->left, root2->left) &&
            identical(root1->right, root2->right);
}

template <class T>
bool subtree(Node<T>* target, Node<T>* source) {
    if (source == nullptr) {
        return true;
    }

    if (target == nullptr) {
        return false;
    }

    if (identical(target, source)) {
        return true;
    }

    return subtree(target->left, source) || subtree(target->right, source);
}

template <class T>
void insert(Node<T>*& root, T element) {
    if (root == nullptr) {
        root = new Node<T>{element, nullptr, nullptr};
        return;
    }

    if (element <= root->data) {
        insert(root->left, element);
    } else {
        insert(root->right, element);
    }
}

template <class T>
void arrayToTree(Node<T>*& root, const std::vector<T>& v) {
    for (T element : v) {
        insert(root, element);
    }
}

template <class T>
bool comparePreOrder(Node<T>* root, const std::vector<T> &sequence, int& index) {
    if (root == nullptr) {
        return true;
    }

    if (sequence[index] != root->data) {
        return false;
    }

    ++index;

    return comparePreOrder(root->left, sequence, index) &&
            comparePreOrder(root->right, sequence, index);
}

template <class T>
int smallestSum(Node<T>* root, int k, int& count) {
    if (root == nullptr) {
        return 0;
    }

    if (count > k) {
        return 0;
    }

    int result = smallestSum(root->left, k, count);

    if (count >= k) {
        return result;
    }

    result += root->data;
    std::cout << root->data << " ";

    ++count;

    if (count == k) {
        return result;
    }

    return result + smallestSum(root->right, k, count);
}

// template <class T>
// bool findUniversalValueSubtree(Node<T>* root, const T& data) {
//     if (root == nullptr) {
//         return true;
//     }

//     // if (root->left != nullptr && root->right != nullptr && root->data == root->left->data && root->data == root->right->data) {
//     //     return findUniversalValueSubtree(root->left, 0) && findUniversalValueSubtree(root->right, 0);
//     // }

//     // if (root->left != nullptr && root->right != nullptr && root->data == root->left->data || root->data == root->right->data) {
//     //     return false;
//     // }

//     // if (root->left == nullptr && root->right == nullptr) {
//     //     return true;
//     // }


// }

template<class T>
bool hasSameData(Node<T> *root, const T &data) {
    if (!root) {
        return true;
    }
    return root->data == data && hasSameData(root->left, data) && hasSameData(root->right, data);
}

template<class T>
int findUniversalTreeHelper(Node<T> *root) {
    if (!root) {
        return 0;
    }

    // if (root->left == nullptr && root->right == nullptr) {
    //     return 0;
    // }

    return (hasSameData(root, root->data) ? 1 : 0) + findUniversalTreeHelper(root->left) + findUniversalTreeHelper(root->right);
}

int main() {
    Node<int>* root = new Node<int>{1,
                        new Node<int>{2, nullptr, nullptr},
                        new Node<int>{3, 
                            new Node<int>{5,
                                new Node<int>{7, nullptr, nullptr},
                                new Node<int>{8, 
                                    nullptr,
                                    new Node<int>{10, nullptr, nullptr}}},
                            new Node<int>{6, nullptr, nullptr}}};

    Node<int>* root2 = new Node<int>{15, 
                            new Node<int>{10,
                                new Node<int>{10, nullptr, nullptr},
                                new Node<int>{10, nullptr, nullptr}},
                            new Node<int>{25, 
                                new Node<int>{25, nullptr, nullptr},
                                new Node<int>{25, nullptr, nullptr}}};

    std::ofstream dot("tree.dot");
    

    // printLeftView2(root);
    // std::vector<int> v;
    // printLeftView(root, 0, v);
    // printVector(v);

    // subtree(root2, new Node<int>{26, nullptr, nullptr});

    // int array[] = {15, 10, 8, 12, 20, 16, 25};
    std::vector<int> v;
    v.push_back(15);
    v.push_back(10);
    v.push_back(8);
    v.push_back(12);
    v.push_back(20);
    v.push_back(16);
    v.push_back(25);
    int index = 0;

    std::cout << comparePreOrder(root2, v, index) << std::endl;

//     Node<int>* root3;
//     arrayToTree(root3, v);
    toDotty(root2, dot);

    index = 0;
    // std::cout << "\n" << smallestSum(root2, 4, index) << std::endl;
    // smallestSum(root2, 3, index);

    std::cout << findUniversalTreeHelper(root2) << std::endl;
 
    //5 7 8 10

    return 0;
}