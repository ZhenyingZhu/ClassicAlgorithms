/*
 * [Source] https://leetcode.com/problems/next-permutation/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Find the first number that is larger than its successor from end, swap it with the first number that is larger than it, and sort numbers after it.
// [Corner Case]: dup. last num
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty())
            return;

        int p = nums.size() - 2;
        for (; p >= 0 && nums[p] >= nums[p + 1]; p--);

        if (p >= 0) {
            int i = p + 1;
            for (; i < (int)nums.size() && nums[p] < nums[i]; i++);
            swap(nums[i - 1], nums[p]);
        }
        reverse(nums.begin() + p + 1, nums.end());
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/NextPermutation.java
 */

/* Java solution
public class Solution {
    public void nextPermutation(int[] num) {
        if(num == null || num.length <= 1) {
            return; 
        }
        int i, j; 
        for(i = num.length - 2; i >= 0; --i) {
            if(num[i] < num[i + 1]) {
                break; 
            }
        }
        if(i < 0) { // Alreay at the end. 
            Arrays.sort(num); 
            return; 
        }
        int key = num[i]; 
        for(j = num.length - 1; j >= 0; --j) {
            if(num[j] > key) {
                break; // At least i + 1 
            }
        }
        // swap
        num[i] = num[j]; 
        num[j] = key; 
        Arrays.sort(num, i + 1, num.length); 
    }
}
 */

int main() {
    Solution sol;

    //vector<int> vec = {4,5,3,2,1};
    //vector<int> vec = {3,2,1};
    //vector<int> vec = {1,1,2};
    //vector<int> vec = {1,2,1};
    //vector<int> vec = {1,2,2};
    vector<int> vec = {2,1,2};
    sol.nextPermutation(vec);
    for (int &num : vec)
        cout << num << ", ";
    cout << endl;

    return 0;
}
