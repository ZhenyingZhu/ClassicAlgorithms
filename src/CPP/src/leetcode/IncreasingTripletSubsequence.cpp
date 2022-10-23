/*
 * [Source] https://leetcode.com/problems/increasing-triplet-subsequence/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: Find longest common subsequence between sorted and original vector. It is wrong because duplicate value.
class SolutionLCS {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> inorder(nums.begin(), nums.end());
        sort(inorder.begin(), inorder.end());

        vector<vector<int>> commons(nums.size() + 1, vector<int>(nums.size() + 1, 0));
        for (int i = 1; i <= (int)nums.size(); ++i) {
            for (int j = 1; j <= (int)nums.size(); ++j) {
                if (nums[i - 1] == inorder[j - 1]) {
                    commons[i][j] = commons[i - 1][j - 1] + 1;
                } else {
                    commons[i][j] = max(commons[i - 1][j], commons[i][j - 1]);
                }
            }
        }

        return commons[nums.size()][nums.size()] >= 3;
    }
};

// [Solution]: Brute force. Too tired. Didn't see it needs O(n) and O(1) time/space complexity
class SolutionBF {
public:
    bool increasingTriplet(vector<int>& nums) {
        unordered_map<int, vector<int>> bucket;
        for (int i = 0; i < (int)nums.size(); ++i) {
            bucket[nums[i]].push_back(i);
        }

        vector<int> nodup;
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            nodup.push_back(it->first);
            sort(it->second.begin(), it->second.end());
vector<int> &v = it->second;
for (int &n : v)
    cout << n << " ";
cout << endl;
        }
        sort(nodup.begin(), nodup.end());
for (int &n : nodup)
    cout << n << " ";
cout << endl;

        for (int i = 0; i < (int)nodup.size() - 2; ++i) {
cout << "1." << nodup[i] << endl;
            int first = bucket[nodup[i]].front(); // always the smallest idx
            for (int j = i + 1; j < (int)nodup.size() - 1; ++j) {
cout << "2." << nodup[j] << endl;
                int second = findFirstLarger(bucket[nodup[j]], first);
                if (second == -1)
                    continue;
                for (int k = j + 1; k < (int)nodup.size(); ++k) {
cout << "3." << nodup[k] << endl;
                    int third = findFirstLarger(bucket[nodup[k]], second);
cout << first << " " << second << " " << third << endl;
                    if (third != -1)
                        return true;
                }
            }
        }
        return false;
    }

    int findFirstLarger(const vector<int> &indexes, int index) {
        int st = 0, ed = (int)indexes.size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (indexes[md] < index) {
                st = md;
            } else {
                ed = md;
            }
        }
        if (indexes[st] > index)
            return indexes[st];
        if (indexes[ed] > index)
            return indexes[ed];
        return -1;
    }
};

// [Solution]: Acually it is LIS 
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> threeIncreasing(3, INT_MAX);
        for (int &num : nums) {
            if (num <= threeIncreasing[0]) { // must <=, otherwise three same numbers can return true
                threeIncreasing[0] = num;
            } else if (num <= threeIncreasing[1]) {
                threeIncreasing[1] = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums 
        //= {1, 2, 3, 4, 5};
        //= {5, 4, 3, 2, 1};
        //= {2, 1, 2, 3, 2};
        //= {0,4,2,1,0,-1,-3};
        = {1, 1, 1, 1};
    cout << sol.increasingTriplet(nums) << endl;

    return 0;
}
