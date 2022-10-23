/*
 * [Source] https://leetcode.com/problems/word-search-ii/
 * [Difficulty]: Hard
 * [Tag]: Backtracking
 * [Tag]: Trie
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Solution]: Use trie.
// [Corner Case]: If there are two same strings in the result, even they are from different cells, return 1.
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0 || board[0].size() == 0)
            return res;
        int height = board.size(), width = board[0].size();

        root_ = new TrieNode();
        for (string& word : words)
            addWordToTrie(word);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                searchWords(board, i, j, root_, "", res);
            }
        }
        return res;
    }

private:
    class TrieNode {
    public:
        TrieNode() {
            isWordEnd_ = false;
        }

        bool isWordEnd() const {
            return isWordEnd_;
        }

        void setWordEnd() {
            isWordEnd_ = true;
        }

        TrieNode* getTrieNode(char c) {
            if (children_.find(c) == children_.end())
                return NULL;
            return children_[c];
        }

        TrieNode* addTrieNode(char c) {
            if (children_.find(c) == children_.end())
                children_[c] = new TrieNode();
            return children_[c];
        }

    private:
        bool isWordEnd_;
        unordered_map<char, TrieNode*> children_;
    };

    void addWordToTrie(string& word) {
        TrieNode* cur = root_;
        for (char& c : word)
            cur = cur->addTrieNode(c);
        cur->setWordEnd();
    }

    void searchWords(vector<vector<char>>& board, int i, int j, TrieNode* node, string pre, vector<string>& res) {
        if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size())
            return;

        char c = board[i][j];
        TrieNode* cur = node->getTrieNode(c);
        if (cur == NULL)
            return;

        pre += c;
        if (cur->isWordEnd()) {
            if (find(res.begin(), res.end(), pre) == res.end()) // No dup
                res.push_back(pre);
        }

        board[i][j] = '*'; // mark as visited
        searchWords(board, i - 1, j, cur, pre, res);
        searchWords(board, i + 1, j, cur, pre, res);
        searchWords(board, i, j - 1, cur, pre, res);
        searchWords(board, i, j + 1, cur, pre, res);
        board[i][j] = c;
    }

private:
    TrieNode* root_;
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> tmp = {"oaan", "etae", "ihkr", "iflv"};
    vector<vector<char>> board;
    for (string& s : tmp)
        board.push_back(vector<char>(s.begin(), s.end()));

    for (string& r : sol.findWords(board, words))
        cout << r << " ";
    cout << endl;

    return 0;
}
