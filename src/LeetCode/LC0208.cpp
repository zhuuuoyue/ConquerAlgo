#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/implement-trie-prefix-tree/description/
*/

struct TrieNode {
    char val;
    bool end{ false };
    std::unordered_map<char, TrieNode*> children;

    explicit TrieNode(char value) : val{ value } {}
    ~TrieNode() {
        for (auto iter = children.begin(); iter != children.end(); ++iter) {
            delete iter->second;
        }
    }
};

class Trie {
private:
    TrieNode* m_root{ nullptr };
public:
    Trie() {
        m_root = new TrieNode(' ');
    }

    ~Trie() {
        if (nullptr != m_root) {
            delete m_root;
            m_root = nullptr;
        }
    }

    void insert(string word) {
        TrieNode* pNode = m_root;
        for (char c : word) {
            if (pNode->children.find(c) == pNode->children.end()) {
                pNode->children[c] = new TrieNode(c);
            }
            pNode = pNode->children[c];
        }
        pNode->end = true;
    }

    bool search(string word) {
        TrieNode* pNode = m_root;
        for (char c : word) {
            if (pNode->children.find(c) == pNode->children.end()) {
                return false;
            }
            pNode = pNode->children[c];
        }
        return pNode->end;
    }

    bool startsWith(string prefix) {
        TrieNode* pNode = m_root;
        for (char c : prefix) {
            if (pNode->children.find(c) == pNode->children.end()) {
                return false;
            }
            pNode = pNode->children[c];
        }
        return true;
    }
};

TEST(T208, C1) {
    Trie dict;
    dict.insert("apple");
    bool ans = dict.search("apple");
    EXPECT_TRUE(ans);
    ans = dict.search("app");
    EXPECT_FALSE(ans);
    ans = dict.startsWith("app");
    EXPECT_TRUE(ans);
    dict.insert("app");
    ans = dict.search("app");
    EXPECT_TRUE(ans);
}
