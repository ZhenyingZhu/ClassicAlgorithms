/*
 * [Source] https://leetcode.com/problems/concatenated-words/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 * [Tag]: Trie
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Solution]: Sort the string from short to long. Then try break current string with previous strings
// [Corner Case]:
class SolutionSet {
public:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.empty())
            return {};

        sort(words.begin(), words.end(), compare);
        unordered_set<string> wordSet;
        wordSet.insert(words[0]);
        int minLen = words[0].length();

        vector<string> res;
        for (int i = 1; i < (int)words.size(); ++i) {
            string &str = words[i];
            if (canConstruct(str, minLen, wordSet)) {
                res.push_back(str); // no need to insert this word into wordset
            }
            wordSet.insert(str);
        }
        return res;
    }

    bool canConstruct(string str, int minLen, unordered_set<string> &wordSet) {
        int len = str.length();
        if (len == 0)
            return true;
        if (len < minLen)
            return false;

        for (int width = minLen; width <= len; ++width) {
            if (wordSet.count( str.substr(0, width) ) == 0)
                continue;
            if ( canConstruct(str.substr(width), minLen, wordSet) )
                return true;
        }
        return false;
    }
};

// [Solution]: use trie tree to store previous words. now check current string is first part of it is in the trie. if so, from next char, search from the root again
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), compare);

        vector<string> res;
        root = new TrieNode();
        for (string &str : words) {
            if (str.empty())
                continue;

            if ( dfs(root, str, 0, 0) ) {
                res.push_back(str);
            } else {
                insert(str);
            }
        }

        delete root;
        return res;
    }

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;

        TrieNode(): isWord(false) { }

        ~TrieNode() {
            for (auto it = children.begin(); it != children.end(); ++it)
                delete it->second;
        }
    };

private:
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    void insert(string &word) {
        TrieNode *run = root;
        for (char &c : word) {
            if ( run->children.count(c) == 0 )
                run->children[c] = new TrieNode();
            run = run->children[c];
        }
        run->isWord = true;
    }

    bool dfs(TrieNode *node, string &word, int pos, int wordNum) {
        if (pos == (int)word.length()) {
            if (node->isWord && wordNum >= 1)
                return true;
            return false;
        }

        char c = word[pos];
        if (node->children.count(c) == 0)
            return false;

        TrieNode *run = node->children[c];
        if (run->isWord) {
            if (dfs(root, word, pos + 1, wordNum + 1)) // start a new word
                return true;
        }

        if (dfs(run, word, pos + 1, wordNum))
            return true;
        return false;
    }

private:
    TrieNode *root;
};

int main() {
    Solution sol;

    //vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    //vector<string> words = {"cat","dog","catdog"};
    vector<string> words = {"","a","a","ab"};
    for (string &str : sol.findAllConcatenatedWordsInADict(words))
        cout << str << " ";
    cout << endl;

    return 0;
}
