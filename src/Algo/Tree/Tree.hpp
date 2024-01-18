#pragma once

#include <queue>

template<class T>
struct TreeNode {
    T data;
    std::vector<TreeNode*> children;
    explicit TreeNode(const T& d) :data{ d } {}
};

template<class T>
class Tree {
public:

    TreeNode<T>* root;

    Tree() = default;
    Tree(const Tree&) = delete;
    Tree(Tree&&) = delete;
    Tree& operator=(const Tree&) = delete;
    Tree& operator=(Tree&&) = delete;

    ~Tree() {
        if (root) {
            using Node = TreeNode<T>;
            std::queue<Node*> nodes;
            nodes.push(root);
            while (!nodes.empty()) {
                std::size_t n = nodes.size();
                while (n) {
                    Node* node = nodes.front();
                    nodes.pop();
                    --n;
                    if (!node) { continue; }
                    for (Node* child : node->children) {
                        nodes.push(child);
                    }
                    delete node;
                }
            }
            root = nullptr;
        }
    }
};