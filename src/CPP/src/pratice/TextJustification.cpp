#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/text-justification/?tab=Description

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (words.empty())
            return {};

        vector<string> res;
        int width = words[0].length(); // 1. first word no space
        vector<string> line = {words[0]};
        for (int i = 1; i < (int)words.size(); ++i) {
            string &word = words[i];
            width += 1 + word.length(); // 2. words need space between

            if (width <= maxWidth) {
                line.push_back(word);
                continue;
            }

            res.push_back(constructLine(line, maxWidth));
            line = {word}; // 1. first word no space
            width = word.length();
        }
        res.push_back(constructLastLine(line, maxWidth));

        return res;
    }

private:
    string constructLine(vector<string> &line, int width) {
        if (line.size() == 1) { // 3. only 1 word on a line
            return line[0] + string(width - line[0].length(), ' ');
        }

        int totalLen = 0;
        for (string &word : line)
            totalLen += word.length();

        int intervals = line.size() - 1;
        int spaces = width - totalLen;
        int eachSpaceWidth = spaces / intervals;
        int extraSpaceNeeded = spaces % intervals;

        string res;
        int i = 0;
        for (; i < extraSpaceNeeded; ++i) {
            res += line[i] + string(eachSpaceWidth + 1, ' ');
        }
        for (; i < (int)line.size(); ++i) {
            if (i == (int)line.size() - 1)
                res += line[i];
            else
                res += line[i] + string(eachSpaceWidth, ' ');
        }
        return res;
    }

    string constructLastLine(vector<string> &line, int width) {
        string res;
        for (int i = 0; i < (int)line.size(); ++i) {
            res += line[i];
            if (i != (int)line.size() - 1)
                res += ' ';
        }
        
        int spaces = width - res.length();
        return res + string(spaces, ' ');
    }
};

int main() {
    Solution sol;

    //vector<string> words = {"aaa", "aaa"}; int maxWidth = 6;
    //vector<string> words = {"aaa", "aa"}; int maxWidth = 6;
    //vector<string> words = {"aaa", "aa", "a", "a"}; int maxWidth = 6;
    vector<string> words = {"aaa", "aa", "a", "a"}; int maxWidth = 9;

    for (string &line : sol.fullJustify(words, maxWidth))
        cout << line << "'" << endl;

    return 0;
}
