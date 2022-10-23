/*
 * [Source] https://leetcode.com/problems/fizz-buzz/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        if (n <= 0)
            return {};

        vector<string> res;
        for (int i = 1; i <= n; ++i) {
            string tmp;
            if (i % 3 == 0)
                tmp += "Fizz";
            if (i % 5 == 0)
                tmp += "Buzz";
            if (tmp == "")
                tmp = to_string(i);
            res.push_back(tmp);
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (string &s : sol.fizzBuzz(15))
        cout << s << " ";
    cout << endl;

    return 0;
}
