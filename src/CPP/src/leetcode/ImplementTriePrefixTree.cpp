/*
 * [Source] https://leetcode.com/problems/implement-trie-prefix-tree/
 * [Source] http://www.lintcode.com/en/problem/implement-trie/
 * [Difficulty]: Medium
 * [Tag]: Design
 * [Tag]: Trie
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: Mostly tree structure use a hash map to store children. Need add a flag to indicate if current word is actually a word or just a prefix
// [Corner Case]:
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
    }

    unordered_map<char, TrieNode*>& getChildren() {
        return children;
    }

    bool isWordEnd() const {
        return isEnd;
    }

    void setWordEnd() {
        isEnd = true;
    }

private:
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        root->setWordEnd();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (const char& c : word) {
cout << c << endl;
            unordered_map<char, TrieNode*>& children = cur->getChildren();
            if (children.find(c) == children.end()) {
                children[c] = new TrieNode();
            }
            cur = children[c];
        }

        cur->setWordEnd();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (const char& c: word) {
//cout << c << endl;
           unordered_map<char, TrieNode*>& children = cur->getChildren();
           if (children.find(c) == children.end()) {
               return false;
           }
           cur = children[c];
        }
        return cur->isWordEnd();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (const char& c: prefix) {
           unordered_map<char, TrieNode*>& children = cur->getChildren();
           if (children.find(c) == children.end()) {
               return false;
           }
           cur = children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class Solution {
public:
    void test() {
        Trie trie;
        trie.insert("abc");
        cout << (trie.search("abc")?"True":"False") << endl;
        cout << (trie.search("ab")?"True":"False") << endl;
        cout << (trie.startsWith("ab")?"True":"False") << endl;
        cout << (trie.startsWith("abc")?"True":"False") << endl;
        cout << (trie.startsWith("abd")?"True":"False") << endl;
        cout << (trie.startsWith("abcd")?"True":"False") << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    sol.test();

    return 0;
}
