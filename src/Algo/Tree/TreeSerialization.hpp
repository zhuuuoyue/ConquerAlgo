#pragma once

#include <string>
#include <queue>
#include <vector>
#include "Tree.hpp"

std::string serialize(const TreeNode<int>* pRoot) {
    if (nullptr == pRoot) { return std::string{}; }

    std::vector<std::vector<const TreeNode<int>*>> clusters{
        std::vector<const TreeNode<int>*>{ pRoot }
    };
    std::queue<const TreeNode<int>*> nodes;
    nodes.push(pRoot);
    while (!nodes.empty()) {
        const TreeNode<int>* pNode = nodes.front();
        std::vector<const TreeNode<int>*> cluster;
        for (const TreeNode<int>* pChild : pNode->children) {
            nodes.push(pChild);
            cluster.emplace_back(pChild);
        }
        clusters.emplace_back(cluster);
        nodes.pop();
    }
    int first{ 0 };
    int last{ static_cast<int>(clusters.size()) - 1 };
    while (last >= first && clusters[last].empty()) {
        --last;
    }

    std::string result;
    for (int i = first; i <= last; ++i) {
        const std::vector<const TreeNode<int>*>& cluster = clusters[i];
        if (i) {
            result = result + ";";
        }
        for (std::size_t j = 0; j < cluster.size(); ++j) {
            if (j) {
                result = result + ",";
            }
            result += std::to_string(cluster[j]->data);
        }
    }
    return result;
}

TreeNode<int>* deserialize(const std::string& data) {
    std::vector<std::vector<int>> clusters;
    for (std::string::const_iterator i = data.cbegin(); i != data.cend();) {
        std::string::const_iterator j = i;
        while (j != data.cend() && *j != ';') { ++j; }
        std::vector<int> cluster;
        while (true) {
            std::string::const_iterator k = i;
            while (k != j && *k != ',') { ++k; }
            if (i != k) {
                std::string num(i, k);
                cluster.emplace_back(std::atoi(num.c_str()));
            }
            if (k == j) { break; }
            ++k;
            i = k;
        }
        clusters.emplace_back(cluster);
        if (j != data.cend()) {
            ++j;
        }
        i = j;
    }

    if (clusters.empty()) { return nullptr; }
    if (1 != clusters.front().size()) { return nullptr; }
    TreeNode<int>* pRoot = new TreeNode<int>(clusters.front().front());
    std::queue<TreeNode<int>*> nodes;
    nodes.push(pRoot);
    for (std::size_t i = 1; i < clusters.size() && !nodes.empty(); ++i) {
        const std::vector<int>& cluster = clusters[i];
        TreeNode<int>* pNode = nodes.front();
        for (int value : cluster) {
            TreeNode<int>* pChild = new TreeNode<int>(value);
            pNode->children.emplace_back(pChild);
            nodes.push(pChild);
        }
        nodes.pop();
    }
    return pRoot;
}