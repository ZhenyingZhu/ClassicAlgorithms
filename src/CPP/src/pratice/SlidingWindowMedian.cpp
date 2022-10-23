#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/sliding-window-median/#/description
// http://www.1point3acres.com/bbs/thread-226035-1-1.html

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<long> larger;
        multiset<long, greater<long>> smaller;
        for (int i = 0; i < k; i++) {
            insert(nums[i], larger, smaller);
        }

        vector<double> res;
        res.push_back(getMedian(larger, smaller));
        for (int i = 0; i < (int)nums.size() - k; i++) {
            erase(nums[i], larger, smaller);
            insert(nums[i + k], larger, smaller);
            res.push_back(getMedian(larger, smaller));
        }
        return res;
    }

    void insert(long num, multiset<long> &larger, multiset<long, greater<long>> &smaller) {
        if (num >= *larger.begin())
            larger.insert(num);
        else
            smaller.insert(num);

        while (larger.size() > smaller.size() + 1) {
            long val = *larger.begin();
            larger.erase(larger.begin());
            smaller.insert(val);
        }

        while (larger.size() < smaller.size()) {
            long val = *smaller.begin();
            smaller.erase(smaller.begin());
            larger.insert(val);
        }
    }

    void erase(long val, multiset<long> &larger, multiset<long, greater<long>> &smaller) {
        if (larger.count(val)) {
            auto it = larger.find(val);
            larger.erase(it);
        } else {
            auto it = smaller.find(val);
            smaller.erase(it);
        }
    }

    double getMedian(multiset<long> &larger, multiset<long, greater<long>> &smaller) {
        if (larger.size() == smaller.size()) {
            return (double)(*larger.begin() + *smaller.begin()) / 2;
        } else {
            return (double)*larger.begin();
        }
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1,3,-1,-3,5,3,6,7}; int k = 3;
    vector<int> nums = {INT_MAX, INT_MAX}; int k = 2;
    for (double &median : sol.medianSlidingWindow(nums, k))
        cout << median << ", ";
    cout << endl;

    return 0;
}
