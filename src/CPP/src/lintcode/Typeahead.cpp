/*
 * [Source] http://www.lintcode.com/en/problem/typeahead/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

// [Corner Case]:
// [Solution]:
class Typeahead {
public:
    // @param dict: A dictionary of words dict
    Typeahead(unordered_set<string> &dict) {
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            string str = *it;
            for (size_t st = 0; st != str.length(); ++st) {
                for (size_t ed = st + 1; ed <= str.length(); ++ed) {
                    string sub = str.substr(st, ed - st);
                    substrToDict[sub].insert(str);
cout << sub << ": " << str << endl;
                }
            }
        }
    }
    
    // @param str: a string
    // @return a set of words
    vector<string> search(string &str) {
        if (substrToDict.find(str) == substrToDict.end())
            return vector<string>();
        return vector<string>(substrToDict[str].begin(), substrToDict[str].end());
    }

    unordered_map<string, unordered_set<string>> substrToDict;
};

// [Solution]:

int main() {
    vector<string> vec = {"Jason Zhang", "James Yu", "Bob Zhang", "Larry Shi"};
    unordered_set<string> dict(vec.begin(), vec.end());

    Typeahead t(dict);
    //string pattern = "Zhang";
    string pattern = "James";
    vector<string> res = t.search(pattern);
    for (string& s : res)
        cout << s << " ";
    cout << endl;

    return 0;
}
