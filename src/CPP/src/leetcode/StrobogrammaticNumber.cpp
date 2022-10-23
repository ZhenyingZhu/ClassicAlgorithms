/*
 * [Source] https://leetcode.com/problems/strobogrammatic-number/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// [Solution]: A map between strobogrammatic numbers
// [Corner Case]:
class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> pairs;
        pairs['0'] = '0';
        pairs['1'] = '1';
        pairs['6'] = '9';
        pairs['8'] = '8';
        pairs['9'] = '6';

        int st = 0, ed = num.size() - 1;
        while (st <= ed) {
            if (pairs[ num[st++] ] != num[ed--])
                return false;
        }

        return true;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.isStrobogrammatic("69") << endl;
    cout << sol.isStrobogrammatic("88") << endl;
    cout << sol.isStrobogrammatic("818") << endl;
    cout << sol.isStrobogrammatic("828") << endl;

    return 0;
}
