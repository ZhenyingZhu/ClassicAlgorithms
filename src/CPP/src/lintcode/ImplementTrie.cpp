/*
 * [Source]: http://www.lintcode.com/en/problem/implement-trie/
 * [Source]: https://leetcode.com/problems/implement-trie-prefix-tree/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Corner Case]:
// [Solution]:
class TrieNode {
public:
    TrieNode() {
        isEnd = false;
        children.clear();
    }

    bool isEnd;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char& c : prefix) {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// [Solution]:

int main() {

    return 0;
}
