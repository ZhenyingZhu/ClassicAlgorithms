/*
 * [Source] https://leetcode.com/problems/reverse-vowels-of-a-string/
 * [Difficulty]: Easy
 * [Tag]: Two Pointers
 * [Tag]: String
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "aeiouAEIOU";
        vector<char> res(s.begin(), s.end());
        vector<int> vowelIdx;
        vector<char> vowelArr;
        for (int i = 0; i < (int)res.size(); ++i) {
            if (vowels.find(res[i]) != string::npos) {
                vowelIdx.push_back(i);
                vowelArr.push_back(res[i]);
            }
        }

        for (int j = 0; j < (int)vowelIdx.size(); ++j) {
            int idx = vowelIdx[j];
            char c = vowelArr[vowelIdx.size() - j - 1];
            res[idx] = c;
        }

        return string(res.begin(), res.end());
    }
};

// [Solution]:

int main() {
    Solution sol;

    cout << sol.reverseVowels("hello") << endl;

    return 0;
}
