/*
 * [Source] https://leetcode.com/problems/sort-transformed-array/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Two Pointers
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// [Solution]: It always break into two parts, one increasing, one decreasing. If a > 0, first decreasing.
// [Corner Case]: two numbers are same
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty())
            return {};

        vector<int> tmp;
        for (int &num : nums) {
            tmp.push_back( a * num * num + b * num + c );
        }
        if (tmp.size() == 1)
            return tmp;

        // first trend is greater
        bool greater = a < 0;
        int mid = nums.size();
        for (int i = 2; i < (int)tmp.size(); ++i) {
            if ( (greater && tmp[i] < tmp[i - 1]) || (!greater && tmp[i] > tmp[i - 1]) ) { 
                mid = i;
                break;
            }   
        }

        if (!greater) {
            reverse(tmp.begin(), tmp.begin() + mid);
        } else {
            reverse(tmp.begin() + mid, tmp.end());
        }


        return merge(tmp, 0, mid);
    }

    vector<int> merge(vector<int> &vec, int st1, int st2) {
        int ed1 = st2, ed2 = vec.size();
        vector<int> res;
        while (st1 < ed1 && st2 < ed2) {
            if (vec[st1] < vec[st2])
                res.push_back(vec[st1++]);
            else
                res.push_back(vec[st2++]);
        }

        while (st1 != ed1)
            res.push_back(vec[st1++]);
        while (st2 != ed2)
            res.push_back(vec[st2++]);

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {-95,-95,-93,-92,-89,-89,-88,-82,-81,-79,-71,-71,-66,-66,-65,-65,-62,-61,-60,-54,-54,-51,-50,-48,-47,-45,-43,-37,-35,-35,-32,-32,-29,-24,-24,-22,-20,-20,-17,-14,-13,-12,-12,-4,1,8,11,14,16,16,22,24,26,28,28,28,29,30,31,36,44,46,49,60,60,60,62,64,65,73,76,86,87,89,91,92,93,94,94,96,96,97};
    for ( int &i : sol.sortTransformedArray(nums, 41, 45, -89) )
        cout << i << " ";
    cout << endl;

    return 0;
}
