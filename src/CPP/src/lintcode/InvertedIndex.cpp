/*
 * [Source] http://www.lintcode.com/en/problem/inverted-index/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Document {
public:
    int id;
    string content;
};

// [Corner Case]:
// [Solution]: Use hash map
class Solution {
public:
    /**
     * @param docs a list of documents
     * @return an inverted index
     */
    map<string, vector<int>> invertedIndex(vector<Document>& docs) {
        map<string, vector<int>> res;
        for (Document& doc : docs) {
            vector<string> words = split(doc.content);
            for (string& word : words) {
                if (res.find(word) == res.end()) {
                    res[word].push_back(doc.id);
                } else {
                    vector<int>& ids = res[word];
                    if (find(ids.begin(), ids.end(), doc.id) == ids.end()) {
                        ids.push_back(doc.id);
                    }
                }
            }
        }
        return res;
    }

private:
    vector<string> split(const string& str) {
        vector<string> res;
        size_t st = 0, find = str.find_first_of(' ');
        while (find != string::npos) {
            res.push_back(str.substr(st, find - st));
            st = find + 1;
            while (str[st] == ' ')
                ++st;
            find = str.find_first_of(' ', st);
        }
        res.push_back(str.substr(st, str.length() - st));
        return res;
    }

    // If need only alpha
    bool isAlpha(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    vector<string> splitWord(const string& str) {
        vector<string> res;
        size_t st = 0, ed = 0;
        while (ed < str.length()) {
            if (!isAlpha(str[ed])) {
                res.push_back(str.substr(st, ed - st));
                st = ed + 1;
                while (st < str.length() && !isAlpha(str[st]))
                    ++st;
                ed = st + 1;
            } else {
                ++ed;
            }
        }
        if (st < str.length())
            res.push_back(str.substr(st, str.length() - st));
        return res;
    }
};

// [Solution]:

int main() {
    Solution sol;

    vector<Document> docs = {
        {1, "This is the content of document1"},
        {2, "This is the content of document2 it is very long bilabial bilabial heheh hahaha ..."}
    };

    map<string, vector<int>> res = sol.invertedIndex(docs);
    for (auto it = res.begin(); it != res.end(); ++it) {
        cout << it->first << " : ";
        for (int& id : it->second) {
            cout << id << " ";
        }
        cout << endl;
    }

    return 0;
}
