#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Trie and DFS on each cell
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (board.empty() || board[0].empty() || words.empty())
            return {};

        root = new TrieNode;
        for (string &word : words)
            insertWord(word);

        h = board.size();
        w = board[0].size();

        unordered_set<string> res;
        dirs = {-1, 0, 1, 0, -1};
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dfs(board, i, j, root, res);
            }
        }

        delete root;
        return vector<string>(res.begin(), res.end());
    }

private:
    struct TrieNode {
        vector<TrieNode*> children;
        string word;
        TrieNode() {
            children.resize(27, NULL);
        }

        ~TrieNode() {
            for (TrieNode *pt : children) {
                if (pt != NULL)
                    delete pt;
            }
        }
    };

    TrieNode *root;
    int h, w;
    vector<int> dirs;

    void insertWord(string &word) {
        TrieNode *run = root;
        for (char &c : word) {
            int idx = c - 'a';
            if (run->children[idx] == NULL)
                run->children[idx] = new TrieNode;
            run = run->children[idx];
        }
        run->word = word;
    }

    void dfs(vector<vector<char>> &board, int stX, int stY, TrieNode *run, unordered_set<string> &res) {
        if (stX < 0 || stX >= h || stY < 0 || stY >= w)
            return;

        char cur = board[stX][stY];
        if (run->children[cur - 'a'] == NULL)
            return;

        board[stX][stY] = 'a' + 26;
        run = run->children[cur - 'a'];
        if (run->word != "")
            res.insert(run->word);

        for (int i = 0; i < 4; i++) {
            int x = stX + dirs[i], y = stY + dirs[i + 1];
            dfs(board, x, y, run, res);
        }
        board[stX][stY] = cur;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};

    for (string &str : sol.findWords(board, words))
        cout << str << ", ";
    cout << endl;

    return 0;
}
