/*
 * [Source] https://leetcode.com/problems/add-and-search-word-data-structure-design/
 * [Difficulty]: Medium
 * [Tag]: Backtracking
 * [Tag]: Trie
 * [Tag]: Design
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]: Use a trie tree to store the dictionary. When reach a ".", try from "a" to "z"
// [Corner Case]:

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        trie_.insertWord(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
       return trie_.isWordIn(word);
    }

private:
    class TrieNode {
    public:
        TrieNode() {
            isWordEnd_ = false;
        }

        TrieNode* addTrieNode(char c) {
            if (children_.find(c) == children_.end())
                children_[c] = new TrieNode();
            return children_[c];
        }

        TrieNode* getTrieNode(char c) {
            if (children_.find(c) == children_.end())
                return NULL;
            return children_[c];
        }

        void setWordEnd() {
            isWordEnd_ = true;
        }

        bool isWordEnd() const {
            return isWordEnd_;
        }

    private:
        bool isWordEnd_;
        unordered_map<char, TrieNode*> children_;
    };

    class Trie {
    public:
        Trie() {
            root_ = new TrieNode();
        }

        void insertWord(string& word) {
            TrieNode* cur = root_;
            for (char& c : word) {
                cur = cur->addTrieNode(c);
            }
            cur->setWordEnd();
        }

        bool isWordIn(string& word) const {
            TrieNode* node = root_;
            return isWordRegIn_(word, 0, node);
        }

    private:
        bool isWordRegIn_(string& word, size_t idx, TrieNode* node) const {
            if (idx == word.length())
                return node->isWordEnd();

            if (word[idx] == '.') {
                for (char c = 'a'; c <= 'z'; ++c) {
                    TrieNode* next = node->getTrieNode(c);
                    if (next != NULL && isWordRegIn_(word, idx + 1, next))
                        return true;
                }
                return false;
            } else {
                TrieNode* next = node->getTrieNode(word[idx]);
                return next != NULL && isWordRegIn_(word, idx + 1, next);
            }
        }

    private:
        TrieNode *root_;
    };

private:
    Trie trie_;
};

class Solution {
public:
    void test() {
// Your WordDictionary object will be instantiated and called as such:
        WordDictionary wordDictionary;
        wordDictionary.addWord("bad");
        wordDictionary.addWord("dad");
        wordDictionary.addWord("mad");
        coutBool(wordDictionary.search("pad"));
        coutBool(wordDictionary.search("bad"));
        coutBool(wordDictionary.search(".ad"));
        coutBool(wordDictionary.search("b.."));
        coutBool(wordDictionary.search("b..."));
    }

private:
    void coutBool(bool b) {
        if (b)
            cout << "True" << endl;
        else
            cout << "False" << endl;
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
