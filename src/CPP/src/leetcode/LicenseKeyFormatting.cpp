/*
 * [Source] https://leetcode.com/problems/license-key-formatting/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Count the actual length first.
// [Corner Case]: So many corner case. Should first create a string without dashes, then part it into groups from the end, then insert dashes
class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        // count dashs and convert lowercase to uppercase
        int dashs = 0;
        for (int i = 0; i < (int)S.length(); ++i) {
            if (S[i] == '-')
                ++dashs;
            else if (S[i] >= 'a' && S[i] <= 'z')
                S[i] = S[i] + 'A' - 'a';
        }

        int actualLen = S.length() - dashs;
        if (actualLen == 0)
            return "";

        int first = actualLen % K;
        int newDashs = actualLen / K - 1 + (first == 0 ? 0 : 1);
        int totalLen = actualLen + newDashs;

        vector<char> vec(totalLen);
        int pt = 0;
        int i = 0;
        for (; i < first; ++i) {
            while (S[pt] == '-')
                ++pt;
            vec[i] = S[pt++];
        }

        if (i == totalLen) // only first part
            return string(vec.begin(), vec.end());

        if (first > 0)
            vec[i++] = '-';
        int cnt = 0;
        for (; i < totalLen; ++i) {
            if (cnt == K) {
                vec[i] = '-';
                cnt = 0;
            } else {
                ++cnt;
                while (S[pt] == '-')
                    ++pt;
                vec[i] = S[pt++];
            }
        }

        return string(vec.begin(), vec.end());
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.licenseKeyFormatting("2-4A0r7-4k", 3) << endl;
    //cout << sol.licenseKeyFormatting("2", 3) << endl;
    //cout << sol.licenseKeyFormatting("---", 3) << endl;
    //cout << sol.licenseKeyFormatting("2-4A0r7-4k", 4) << endl;
    cout << sol.licenseKeyFormatting("--a-a-a-a--", 2) << endl;

    return 0;
}
