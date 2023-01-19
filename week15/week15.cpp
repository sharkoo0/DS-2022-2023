#include <iostream>
#include <vector>
#include "graph.h"

struct Node {
    char data;
    Node* left;
    Node* right;
};

void printAllPaths(std::vector<std::vector<char>>& paths) {
    for (int i = 0; i < paths.size(); ++i) {
        for (int j = 0; j < paths[i].size(); ++j) {
            std::cout << paths[i][j] << " -> ";
        }
        std::cout << std::endl;
    }
}

void findAllPaths(Node* root, std::vector<char>& path, std::vector<std::vector<char>>& allPaths){
    if (root == nullptr) {
        return;
    }

    path.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr) {
        allPaths.push_back(std::vector<char>(path));
        path.pop_back();
    } else if (root->left == nullptr) {
        findAllPaths(root->right, path, allPaths);
        path.pop_back();
        return;
    } else if (root->right == nullptr) {
        findAllPaths(root->left, path, allPaths);
        path.pop_back();
        return;
    } else {
        findAllPaths(root->left, path, allPaths);
        findAllPaths(root->right, path, allPaths);
        path.pop_back();
    }
}

bool printPath(const Graph<char, int>& g, const std::vector<char>& path) {
    if (path.size() == 0) {
        std::cout << std::endl;
        return true;
    }

    for (int i = 0; i < path.size() - 1; ++i) {
        if (!g.hasVertex(path[i])) {
            return false;
        }
        if (!g.hasEdge(path[i], path[i + 1])) {
            return false;
        }
    }

    for (int i = 0; i < path.size() - 1; ++i) {
        std::cout << path[i] << " -> ";
    }
    std::cout << path.back() << std::endl;
    return true;
}

void findPath(const Graph<char, int>& g, const std::vector<std::vector<char>>& paths) {
    for (int i = 0; i < paths.size(); ++i) {
        if (std::cout << "Path found\n" && printPath(g, paths[i])) {
            return;
        }
    }
}




int sumEvenLeftLeafes ( Node* root, int level) {
    if (root == nullptr) {
        return 0;
    }

    if ( root->left != nullptr && root->right == nullptr && level % 2 == 0) {
        return root->data + sumEvenLeftLeafes( root->left, level + 1);
    }
    return sumEvenLeftLeafes(root->left,level + 1 ) +
           sumEvenLeftLeafes(root->right,level + 1 );


}

Graph<char, int> createGraph() {
    Graph<char, int> g;

    g.addVertex('a');
    g.addVertex('b');
    g.addVertex('c');
    g.addVertex('d');
    g.addVertex('e');
    g.addVertex('f');
    g.addVertex('g');
    g.addVertex('h');

    g.addEdge('a', 'f', 0);
    g.addEdge('a', 'd', 0);
    g.addEdge('b', 'h', 0);
    g.addEdge('c', 'h', 0);
    g.addEdge('d', 'e', 0);
    g.addEdge('e', 'h', 0);
    g.addEdge('f', 'c', 0);
    g.addEdge('f', 'h', 0);
    g.addEdge('g', 'e', 0);
    g.addEdge('g', 'b', 0);

    return g;
}

Node* createBinaryTree() {
    Node* root = new Node{'a', 
                    new Node{'e', 
                        new Node{'d', 
                            new Node{'b', nullptr, nullptr}, 
                            nullptr},
                        new Node{'g', nullptr, nullptr}}, 
                    new Node{'f', 
                        nullptr, 
                        new Node{'c',
                            new Node{'h', nullptr, nullptr},
                            nullptr}
                    }};
    
    return root;
}

void deleteBinaryTree(Node*& root) {
    if (root == nullptr) {
        return;
    }

    deleteBinaryTree(root->left);
    deleteBinaryTree(root->right);

    delete root;
    root = nullptr;
}

int main() {
    // Node* root = new Node{1, 
    //                 new Node{2,
    //                     new Node{4, 
    //                         new Node{6, 
    //                             new Node{7, 
    //                                 new Node{9, 
    //                                     nullptr,
    //                                     nullptr},
    //                                 nullptr},
    //                             nullptr},
    //                         nullptr}, 
    //                     new Node{5 ,
    //                         nullptr, 
    //                         new Node{11,
    //                             new Node{12,
    //                                 nullptr, 
    //                                 nullptr}, 
    //                             nullptr}}},
    //                 new Node{3, 
    //                     nullptr,
    //                     new Node{8, 
    //                         new Node{10, 
    //                             nullptr, 
    //                             nullptr}, 
    //                         nullptr}}};

    // std::cout << sumEvenLeftLeafes(root, 0) << std::endl;
    Node* root = createBinaryTree();
    Graph<char, int> g = createGraph();

    std::vector<char> path;
    std::vector<std::vector<char>> allPaths;

    findAllPaths(root, path, allPaths);
    printAllPaths(allPaths);

    findPath(g, allPaths);

    // deleteBinaryTree(root);

    // sumEvenLeftLeafes(root, 2);
    return 0;
}