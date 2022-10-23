/*
 * [Source] https://leetcode.com/problems/construct-the-rectangle/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int st = 1, ed = sqrt(area);
        for (int i = ed; i >= st; --i) {
            if (area % i == 0)
                return {area / i, i};
        }
        return {area, 1}; // shoud not reach here
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //for (int &i : sol.constructRectangle(5))
    //for (int &i : sol.constructRectangle(4))
    for (int &i : sol.constructRectangle(18))
        cout << i << " ";
    cout << endl;

    return 0;
}
