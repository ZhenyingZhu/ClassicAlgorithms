/*
 * [Source] https://leetcode.com/problems/word-squares/
 * [Difficulty]: Hard
 * [Tag]: Backtracking
 * [Tag]: Trie
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Use backtracking on each prefix of existing words to find next candidate word. Use a trie to fastern the search
// [Corner Case]:
class Solution {
public:
    struct TrieNode {
        TrieNode() {
            c = '*';
        }

        ~TrieNode() {
//cout << "Deleting " << c << endl;
            for (auto it = children.begin(); it != children.end(); ++it)
                // delete will call destructor
                delete it->second;
        }

        char c;
        unordered_map<char, TrieNode*> children;
        vector<string> startwith; // strings that has prefix of this node
    };

    struct Trie {
        Trie(vector<string> &words) {
            root = new TrieNode;
            for (string &word : words) {
                insert(word);
            }
        }

        ~Trie() {
            delete root;
        }

        void insert(string &word) {
            TrieNode *cur = root;
            for (char &c : word) {
                if (cur->children.count(c) == 0)
                    cur->children[c] = new TrieNode;
                cur->children[c]->c = c;
                cur->children[c]->startwith.push_back(word); // should do it here so that the last char has also updated
                cur = cur->children[c];
            }
        }

        vector<string> search(string prefix) {
            TrieNode *cur = root;
            for (char &c : prefix) {
                if (cur->children.count(c) == 0)
                    return {};
                cur = cur->children[c];
            }
            return cur->startwith;
        }

        TrieNode *root;
    };

    vector<vector<string>> wordSquares(vector<string>& words) {
        if (words.empty())
            return {};

        Trie trie(words);
//for (string &str : trie.search("l")) cout << str << " "; cout << endl;
        vector<vector<string>> res;
        for (string &word : words) {
            vector<string> wordSquare = {word};
            helper(wordSquare, trie, res);
        }
        return res;
    }

    void helper(vector<string> &wordSquare, Trie &trie, vector<vector<string>> &res) {
        if (wordSquare.size() == wordSquare[0].length()) {
            res.push_back(wordSquare);
            return;
        }

        int len = wordSquare.size(); // it is the prefix len, as well as the index of char in each string
        string prefix = "";
        for (int i = 0; i < len; ++i)
            prefix += wordSquare[i][len];
//cout << prefix << endl;
        for ( string &candidate : trie.search(prefix) ) {
            wordSquare.push_back(candidate);
            helper(wordSquare, trie, res);
            wordSquare.pop_back();
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> words = {"area","lead","wall","lady","ball"};
    for (vector<string> &wordSquare : sol.wordSquares(words)) {
        for (string &str : wordSquare)
            cout << str << endl;
        cout << endl;
    }

    return 0;
}
