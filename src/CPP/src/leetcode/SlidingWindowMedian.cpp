/*
 * [Source] https://leetcode.com/problems/sliding-window-median/
 * [Difficulty]: Hard
 * [Tag]: 
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

// [Solution]: Use two multiset to work as two stacks.
// [Corner Case]:
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k == 0 || nums.empty())
            return {};
        vector<double> res;

        int size = nums.size();
        multiset<long> upperset;
        for (int i = 0; i < k && i < size; ++i)
            upperset.insert(nums[i]);
        
        bool even = (upperset.size() % 2 == 0);
        int mid = upperset.size() / 2;
        multiset<long> lowerset;
        for (int i = 0; i < mid; ++i) {
            lowerset.insert(*upperset.begin());
            upperset.erase(upperset.begin());
        }
        insert(even, upperset, lowerset, res);

        for (int st = 0; st < size - k; ++st) {
            int ed = st + k; // the number to insert
            int &next = nums[ed];
            if (next > (int)res.back())
                upperset.insert((long)next);
            else
                lowerset.insert((long)next);

            int &prev = nums[st];
cout << "prev :" << prev << " next :" << next << endl;
            if (upperset.count(prev)) { // prev can be in upperset or lowerset.
                upperset.erase(upperset.find(prev)); // don't use erase on number because it remove all occurance
            } else {
                lowerset.erase(lowerset.find(prev));
            }

cout << lowerset.size() << " vs " << upperset.size() << endl;

            if (lowerset.size() + 1 < upperset.size()) {
                lowerset.insert(*upperset.begin());
                upperset.erase(upperset.begin());
            } else if (lowerset.size() > upperset.size()) {
                upperset.insert(*(--lowerset.end()));
cout << *upperset.begin() << endl;
                lowerset.erase(--lowerset.end());
            }

            insert(even, upperset, lowerset, res);
        }

        return res;
    }

    void insert(bool even, multiset<long> &upperset, multiset<long> &lowerset, vector<double> &res) {
        if (even)
            res.push_back( ((double)(*upperset.begin()) + (double)(*(--lowerset.end()))) / 2 );
        else
            res.push_back(*upperset.begin());
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> nums = {2147483647,1,2,3,4,5,6,7,2147483647};
    for (double &num : sol.medianSlidingWindow(nums, 2))
        cout << num << " ";
    cout << endl;

    return 0;
}
