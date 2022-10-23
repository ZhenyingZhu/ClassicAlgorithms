/*
 * [Source] http://www.lintcode.com/en/problem/trie-serialization/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <map>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode() {}
    map<char, TrieNode*> children;
};

// [Corner Case]:
// [Solution]:
class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a trie which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TrieNode* root) {
        string res;
        serializeTrieTree(root, res);
        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TrieNode* deserialize(string data) {
        size_t idx = 0;
        return deserializeTrieTree(data, idx);
    }

private:
    void serializeTrieTree(TrieNode* cur, string& res) {
        res += "<";
        for (map<char, TrieNode*>::iterator it = cur->children.begin(); it != cur->children.end(); ++it) {
            res += it->first;
            serializeTrieTree(it->second, res);
        }
        res += ">";
    }

    TrieNode* deserializeTrieTree(string& data, size_t& idx) {
        if (data[idx++] != '<') {
            cout << data << " IDX " << idx << "is not <" << endl;
            return NULL; // throw exception
        }

        TrieNode* cur = new TrieNode();
        char c = data[idx];
        while (c != '>') {
            cur->children[c] = deserializeTrieTree(data, ++idx);
           c = data[idx];
        }
        ++idx;
        return cur;
    }
};

// [Solution]:

int main() {
    TrieNode* root = new TrieNode();
    root->children['a'] = new TrieNode();
    TrieNode* a = root->children['a'];
    a->children['b'] = new TrieNode();
    a->children['c'] = new TrieNode();
    a->children['d'] = new TrieNode();
    TrieNode* b = a->children['b'];
    b->children['e'] = new TrieNode();
    TrieNode* d = a->children['d'];
    d->children['f'] = new TrieNode();

    Solution sol;
    string s1 = sol.serialize(root);
    TrieNode* r2 = sol.deserialize(s1);
    string s2 = sol.serialize(r2);
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
