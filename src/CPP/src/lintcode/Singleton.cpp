/*
 * [Source] http://www.lintcode.com/en/problem/singleton/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>

using namespace std;

// [Corner Case]:
// [Solution]: What the F**k is this?! Don't learn this s**t
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        if (solution == NULL) {
            solution = new Solution;
        }
        return solution;
    }
    static Solution *solution;

private:
    Solution() { }
};

Solution *Solution::solution = NULL;

// [Solution]:

int main() {
    Solution *a = Solution::getInstance();
    Solution *b = Solution::getInstance();
    cout << a << " " << b << endl;

    return 0;
}
