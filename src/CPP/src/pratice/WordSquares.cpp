#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: http://www.1point3acres.com/bbs/thread-220334-1-1.html
// https://leetcode.com/problems/word-squares/

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string> &words) {
        if (words.empty())
            return {};

        Trie trie;
        for (string &word : words)
            trie.insert(word);

        int len = words[0].length();
        vector<vector<string>> res;
        for (string &word : words) {
            vector<string> square = {word};
            helper(square, 1, trie, len, res);
        }
        return res;
    }

private:
    struct TrieNode {
        ~TrieNode() {
            for (auto it = children.begin(); it != children.end(); ++it)
                delete it->second;
        }

        unordered_map<char, TrieNode*> children;
        vector<string> words;
    };

    struct Trie {
        Trie() {
            root = new TrieNode;
        }

        ~Trie() {
            delete root;
        }

        void insert(string word) {
            TrieNode *run = root;
            for (char &c : word) {
                if (!run->children.count(c))
                    run->children[c] = new TrieNode;
                run = run->children[c];
                run->words.push_back(word);
            }
        }

        vector<string> search(string prefix) {
            TrieNode *run = root;
            for (char &c : prefix) {
                if (!run->children.count(c))
                    return {};
                run = run->children[c];
            }
            return run->words;
        }

        TrieNode *root;
    };

private:
    void helper(vector<string> &square, int idx, Trie &trie, int len, vector<vector<string>> &res) {
        if (idx == len) {
            res.push_back(square);
            return;
        }

        vector<char> prefix(idx);
        for (int i = 0; i < idx; ++i) {
            prefix[i] = square[i][idx];
        }

        vector<string> candidates = trie.search(string(prefix.begin(), prefix.end()));
        for (string &str : candidates) {
            square.push_back(str);
            helper(square, idx + 1, trie, len, res);
            square.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<string> words = {"area","lead","wall","lady","ball"};
    for ( vector<string> &square : sol.wordSquares(words) ) {
        for (string &str : square)
            cout << str << endl;
        cout << endl;
    }

    return 0;
}
