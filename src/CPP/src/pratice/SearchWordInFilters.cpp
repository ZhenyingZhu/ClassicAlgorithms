#include <iostream>
#include <unordered_map>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-220333-1-1.html
// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    Solution() {
        root = new TrieNode;
    }

    void addFilter(string filter) {
        TrieNode *run = root;
        for (char &c : filter) {
            if (!run->children.count(c))
                run->children[c] = new TrieNode;
            run = run->children[c];
        }
        run->isEnd = true;
    }

    bool isWordBlacklisted(string word) {
        int len = word.length();

        TrieNode *run = root, *star = NULL;
        int pt = 0, match = 0;

        while (pt < len) {
            if (run != NULL && run->children.count(word[pt])) {
                run = run->children[word[pt]];
                ++pt;
            } else if (run != NULL && run->children.count('*')) {
                run = run->children['*'];
                star = run;
                match = pt;
            } else if (star != NULL) {
                pt = ++match;
                run = star;
            } else {
                return false;
            }
        }
        while (run->children.count('*'))
            run = run->children['*'];
        return run->isEnd;
    }

private:
    struct TrieNode {
        TrieNode(): isEnd(false) { }

        ~TrieNode() {
            for (auto it = children.begin(); it != children.end(); ++it)
                delete it->second;
        }

        unordered_map<char, TrieNode*> children;
        bool isEnd;
    };

    TrieNode *root;
};

int main() {
    Solution sol;

    sol.addFilter("aa");
    sol.addFilter("c*a*b");
    sol.addFilter("x**");
    sol.addFilter("d**d");
    cout << sol.isWordBlacklisted("a") << endl;
    cout << sol.isWordBlacklisted("aa") << endl;
    cout << sol.isWordBlacklisted("cabab") << endl;
    cout << sol.isWordBlacklisted("cabab") << endl;
    cout << sol.isWordBlacklisted("xcabab") << endl;
    cout << sol.isWordBlacklisted("dcabab") << endl;

    return 0;
}
