#include <iostream>
// int* array = new int[16];

struct Node {
    int data;
    Node* left;
    Node* right;
};

void print(Node* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data << " ";

    print(root->left);
    print(root->right);
}

void insert(Node*& root, const char* path, int data) {
    if(root == nullptr && *path == '\0') {
        root = new Node{data, nullptr, nullptr};
        return;
    }
    if (root == nullptr && *path != '\0') {
        return;
    }

    if (*path == 'L') {
        insert(root->left, path + 1, data);
    }
    if (*path == 'R') {
        insert(root->right, path + 1, data);
    }
}

void remove(Node*& root, const char* path) {
    if (root == nullptr) {
        return;
    }
    if (root->left == nullptr && root->right == nullptr && *path == '\0') {
        delete root;
        root = nullptr;
        return;
    }

    if (*path == 'L') {
        remove(root->left, path + 1);
    }
    if (*path == 'R') {
        remove(root->right, path + 1);
    }
}

void insertBST(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node{data, nullptr, nullptr};
        return;
    }

    if (data > root->data) {
        insertBST(root->right, data);
    } else {
        insertBST(root->left, data);
    }
}

void removeHelper(Node*& root) {
    if (root == nullptr) {
        return;
    }

    removeHelper(root->left);
    removeHelper(root->right);
    delete root;
    root = nullptr;
}

void removeBST(Node*& root, int data) {
    if (root == nullptr) {
        return;
    }
    if (data < root->data) {
        removeBST(root->left, data);
        return;
    }
    if (data > root->data) {
        removeBST(root->right, data);
        return;
    }

    removeHelper(root);
}

Node* createTreeFromArray(Node*& root, int* array, int size) {
    if (array == nullptr || size <= 0) {
        return nullptr;
    }
    if (size == 0) {
        return root;
    }

    root = new Node{*array, nullptr, nullptr};
    --size;    

    if (*(array + 1) <= root->data) {
        return createTreeFromArray(root->left, array + 1, size);
    } else {
        return createTreeFromArray(root->right, array + 1, size);
    }
}

void createTreeFromArray2(Node*& root, int* array, int size) {
    if (array == nullptr || size < 1) {
        return;
    }

    root = new Node{*(array + size / 2), nullptr, nullptr};

    createTreeFromArray2(root->left, array, size / 2);
    createTreeFromArray2(root->right, array + size / 2 + 1, size - size / 2 - 1);
}

int main() {
    // Node* root = new Node{4, 
    //                 new Node{2, 
    //                     new Node{1, nullptr, nullptr}, 
    //                     new Node{3, nullptr, nullptr}}, 
    //                 new Node{5, nullptr, nullptr}};

    // print(root);
    // insert(root, "RL", 4);
    // print(root);
    // std::cout << std::endl;
    // remove(root, "LL");
    // print(root);

    Node* root = nullptr;
    insertBST(root, 10);
    insertBST(root, 7);
    insertBST(root, 15);
    insertBST(root, 5);
    insertBST(root, 8);
    insertBST(root, 8);
    insertBST(root, 4);
    insertBST(root, 6);
    insertBST(root, 3);
    insertBST(root, 11);
    insertBST(root, 17);
    insertBST(root, 16);
    insertBST(root, 18);
    insertBST(root, 9);
    insertBST(root, 6);
    insertBST(root, 4);

    print(root);
    std::cout << std::endl;

    int array[] = {10, 7, 5, 4, 3, 4, 6, 6, 8, 8, 9, 15, 11, 17, 16, 18};
    Node* root2 = nullptr;
    createTreeFromArray(root2, array, 16);
    print(root2);
    std::cout << std::endl;

    int sortedArray[] = {1, 2, 3, 4, 5};
    Node* root3 = nullptr;
    createTreeFromArray2(root3, sortedArray, 5);
    print(root3);
    // removeBST(root, 7);
    // print(root);




    return 0;
}