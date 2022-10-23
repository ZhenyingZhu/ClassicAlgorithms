/*
 * [Source] https://leetcode.com/problems/longest-absolute-file-path/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// [Solution]: Use a vector to store previous dirs length. If current path is a file, update maxLen. Otherwise update next dirs length.
// [Corner Case]: 1. in C++ \n is a char. 2. first dir doesn't need /
class Solution {
public:
    int lengthLongestPath(string input) {
        if (input.length() == 0)
            return 0;

        unordered_map<int, int> folderLevelLenMap;

        vector<string> lines = split(input);
for (string &part : lines)
    cout << part << " ";
cout << endl;
        int maxFileLen = 0;
        for (string &path : lines) {
            int level = getLevel(path);
            string name = path.substr(level * 1); // level means how many \t at the begining
cout << path << " " << level << " " << name.length() << endl;

            int absolutePathLen = level == 0 ? name.length() : folderLevelLenMap[level - 1] + 1 + name.length(); // dir + / + currentPathLen
cout << absolutePathLen << endl;
            if (isFolder(name)) {
                // always override previous length
                folderLevelLenMap[level] = absolutePathLen;
            } else {
                maxFileLen = max(maxFileLen, absolutePathLen);
            }
        }
        return maxFileLen;
    }

    vector<string> split(string &input) {
        vector<string> res;
        size_t start = 0;
        size_t found = input.find_first_of("\n");
        while (found != string::npos) {
            res.push_back(input.substr(start, found - start));
            start = found + 1;
            found = input.find_first_of("\n", start);
        }
        res.push_back(input.substr(start));
        return res;
    }

    int getLevel(string &filename) {
        int level = 0;
        int st = 0;
        while ( st < (int)filename.length() && (filename[st] == '\t') ) {
            ++level;
            ++st;
        }
        return level;
    }

    bool isFolder(string &filename) {
        return filename.find(".") == string::npos;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    cout << sol.lengthLongestPath("") << endl;

    return 0;
}
