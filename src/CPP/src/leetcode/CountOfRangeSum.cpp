/*
 * [Source] https://leetcode.com/problems/count-of-range-sum/
 * [Difficulty]: Hard
 * [Tag]: Divide and Couquer
 * [Tag]: Binary Search Tree
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: sum[ed]-sum[st] equals to sum of st+1 to ed. Now need lower<=sum[ed]-sum[st]<=upper, needs sum[ed]-upper<=sum[st]<=sum[ed]-lower. Put sum[st] in an sorted array and find for every sum[ed], how many st<ed fit the condition. Use multiset because multiset can have equal values
// [Corner Case]:
class SolutionMultiset {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sums(nums.size() + 1, 0);
        for (size_t i = 1; i <= nums.size(); ++i)
            sums[i] = sums[i - 1] + nums[i - 1];

        multiset<long> stSums;
        stSums.insert(0);

        int cnt = 0;
        for (int ed = 1; ed < (int)sums.size(); ++ed) {
            long stLower = sums[ed] - upper;
            long stUpper = sums[ed] - lower;
            int stNum = distance( stSums.lower_bound(stLower), stSums.upper_bound(stUpper) );
cout << stLower << "-" << stUpper << ":" << stNum << endl;
            cnt += stNum;

            stSums.insert(sums[ed]);
        }

        return cnt;
    }
};

// [Solution]: Combine merge sort with count sum. The trick is only count sums in the second half for each one in the first half
class Solution {
public:
    int lower_, upper_;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower_ = lower;
        upper_ = upper;

        vector<long> sums(nums.size() + 1, 0);
        for (size_t i = 1; i <= nums.size(); ++i)
            sums[i] = sums[i - 1] + nums[i - 1];

        return countAndMergeSort(sums, 0, (int)sums.size());
    }

    int countAndMergeSort(vector<long>& sums, int st, int ed) {
        // ed is the next of last
        if (st + 1 >= ed)
            return 0;

        int md = st + (ed - st) / 2;
        int cnt = countAndMergeSort(sums, st, md) + countAndMergeSort(sums, md, ed);

        // now st to md-1 and md to ed-1 are sorted
        // for sum[i] in first half, find sum[j] in second half that lower<=sum[j]-sum[i]<=upper
        int jLower = md, jUpper;
        for (int i = st; i < md; ++i) {
            while (jLower < ed && sums[jLower] - sums[i] < lower_)
                ++jLower;
            jUpper = jLower;
            while (jUpper < ed && sums[jUpper] - sums[i] <= upper_)
                ++jUpper;

            cnt += jUpper - jLower;
        }

        // merge sort
        vector<int> tmp;
        int i = st, j = md;
        while (i < md && j < ed) {
            if (sums[i] < sums[j])
                tmp.push_back(sums[i++]);
            else
                tmp.push_back(sums[j++]);
        }
        while (i < md)
            tmp.push_back(sums[i++]);

        copy(tmp.begin(), tmp.end(), sums.begin() + st);

for (int sum : sums)
    cout << sum << " ";
cout << endl;
        return cnt;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-2, 5, -1};
    cout << sol.countRangeSum(nums, -2, 2) << endl;
    //vector<int> nums = {2147483647,-2147483648,-1,0};
    //cout << sol.countRangeSum(nums, -1, 0) << endl;

    return 0;
}
