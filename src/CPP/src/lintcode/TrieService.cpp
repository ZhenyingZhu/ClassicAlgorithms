/*
 * [Source] http://www.lintcode.com/en/problem/trie-service/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode() {}
    map<char, TrieNode*> children;
    vector<int> top10;
};

// [Corner Case]:
// [Solution]: This service is used for typeahead. When user input a char, the brower search the trie and return the most freqent next char
class TrieService {
private:
    TrieNode* root;

public:
    TrieService() {
        root = new TrieNode();
    }

    ~TrieService() {
        // not implemented
    }

    TrieNode* getRoot() {
        // Return root of trie root
        return root;
    }

    void insert(string& word, int frequency) {
        TrieNode* cur = root;
        for (char& c : word) {
            if (cur->children.find(c) == cur->children.end()) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            insertFreq(cur->top10, frequency);
        }
    }

private:
    void insertFreq(vector<int>& vec, int frequency) {
        vec.push_back(frequency);
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        if (vec.size() > 10)
            vec.pop_back();
    }
};


// [Solution]:

int main() {

    return 0;
}
