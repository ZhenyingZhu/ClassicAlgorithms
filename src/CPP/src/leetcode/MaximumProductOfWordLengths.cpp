/*
 * [Source] https://leetcode.com/problems/maximum-product-of-word-lengths/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulate
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Use a bitset to indicate the char appears in the string. so that and operator of two bitsets can find if they have common char
// [Corner Case]: size_t in for loop cannot deal empty vector and decrease index. Don't use
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if (words.empty())
            return 0;

        vector<unsigned int> alphaBool(words.size(), 0U); // i bit of the int indicate 'a'+i shows in this string or not
        for (size_t i = 0; i < words.size(); ++i) {
            string& word = words[i];
            unsigned int bitArray = 0U;
            for (char& c : word)
                bitArray |= 1U << (c - 'a');

            alphaBool[i] = bitArray;
        }

        int maxp = 0;
        for (size_t i = 0; i < words.size() - 1; ++i) {
            for (size_t j = i + 1; j < words.size(); ++j) {
                if ( (alphaBool[i] & alphaBool[j]) == 0U )
                    maxp = max( maxp, (int)(words[i].length() * words[j].length()) );
            }
        }
        return maxp;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << sol.maxProduct(words) << endl;

    return 0;
}
