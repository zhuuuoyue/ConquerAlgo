#include "gtest/gtest.h"
#include "leetcode.hpp"

/*
* https://leetcode.cn/problems/replace-words/description/
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

    std::string prefix(const std::string& word) const {
        TrieNode* pNode = m_root;
        for (int i = 0; i < word.size(); ++i) {
            if (pNode->children.find(word[i]) == pNode->children.end()) {
                return word;
            }
            pNode = pNode->children[word[i]];
            if (pNode->end) {
                return std::string(word.begin(), word.begin() + i + 1);
            }
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (const std::string& word : dictionary) {
            trie.insert(word);
        }

        std::string ans;
        auto iter = sentence.begin();
        while (iter != sentence.end()) {
            auto end = iter;
            while (end != sentence.end() && *end != ' ') { ++end; }
            std::string word = std::string(iter, end);
            std::string prefix = trie.prefix(word);
            if (!ans.empty()) { ans += ' '; }
            ans += prefix;
            if (end != sentence.end()) { ++end; }
            iter = end;
        }
        return ans;
    }
};

TEST(T648, C1) {
    std::vector<std::string> dict{ "cat", "bat", "rat" };
    std::string ans = Solution().replaceWords(dict, "the cattle was rattled by the battery");
    EXPECT_EQ(ans, "the cat was rat by the bat");
}

TEST(T648, C2) {
    std::vector<std::string> dict{ "a", "b", "c" };
    std::string ans = Solution().replaceWords(dict, "aadsfasf absbs bbab cadsfafs");
    EXPECT_EQ(ans, "a a b c");
}
