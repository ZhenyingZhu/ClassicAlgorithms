#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <map>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224520-1-1.html
// https://leetcode.com/problems/implement-trie-prefix-tree/
// with frequency count and return a vector of string from more freqent to less

class Trie {
public:
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
        }
        ++run->freq;
    }

    bool search(string word) {
        TrieNode *endNode = getNode(word);
        if (endNode == NULL)
            return false;
        return endNode->freq > 0;
    }

    vector<string> startsWith(string prefix) {
        TrieNode *node = getNode(prefix);
        if (node == NULL)
            return {};

        map<int, vector<string>, greater<int>> freqWordsMap;
        vector<char> pre(prefix.begin(), prefix.end());
        dfs(node, pre, freqWordsMap);

        vector<string> res;
        for (auto it = freqWordsMap.begin(); it != freqWordsMap.end(); ++it) {
            res.insert(res.end(), it->second.begin(), it->second.end());
        }
        return res;
    }

private:
    struct TrieNode {
        TrieNode(): freq(0) { }

        ~TrieNode() {
            for (auto it = children.begin(); it != children.end(); ++it)
                delete it->second;
        }

        int freq;
        unordered_map<char, TrieNode*> children;
    };

private:
    TrieNode* getNode(string &prefix) {
        TrieNode *run = root;
        for (char &c : prefix) {
            if (!run->children.count(c))
                return NULL;
            run = run->children[c];
        }
        return run;
    }

    void dfs(TrieNode *node, vector<char> &pre, map<int, vector<string>, greater<int>> &res) {
        if (node == NULL)
            return;

        if (node->freq > 0) {
            res[node->freq].push_back( string(pre.begin(), pre.end()) );
        }

        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            pre.push_back(it->first);
            dfs(it->second, pre, res);
            pre.pop_back();
        }
    }

private:
    TrieNode *root;
};

int main() {
    Trie trie;

    trie.insert("abcde");
    trie.insert("abcde");
    trie.insert("abfgh");
    trie.insert("ab");
    trie.insert("ab");
    trie.insert("ab");
    cout << trie.search("abcde") << endl;
    cout << trie.search("abc") << endl;
    for (string &str : trie.startsWith("ab"))
        cout << str << endl;
}
