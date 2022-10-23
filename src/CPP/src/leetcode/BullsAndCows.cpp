/*
 * [Source] https://leetcode.com/problems/bulls-and-cows/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// [Solution]: Don't forget to minus bull from cow
// [Corner Case]:
class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        unordered_map<char, int> appears;
        for (size_t i = 0; i < secret.length(); ++i) {
            ++appears[secret[i]];
            if (secret[i] == guess[i])
                ++bull;
        }

        int cow = 0;
        for (size_t i = 0; i < secret.length(); ++i) {
            char& c = guess[i];
            if (appears.find(c) != appears.end() && appears[c] > 0) {
                ++cow;
                --appears[c];
            }
        }

        return to_string(bull) + "A" + to_string(cow - bull) + "B";
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.getHint("1807", "7810") << endl;
    cout << sol.getHint("1123", "0111") << endl;

    return 0;
}
