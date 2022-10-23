/*
 * [Source] https://leetcode.com/problems/3sum/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Sort the array, then fix the first element and do two sum in the leaving elements. If two consective elements are same, skip.
// [Corner Case]: Same values.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/ThreeSum.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (num == null || num.length < 3) {
            return res; 
        }
        Arrays.sort(num); 
        List<Integer> list = new ArrayList<Integer>(); 
        for (int i = 0; i < num.length - 2; ++i) {
            if (num[i] > 0) {
                break; 
            }
            if (i != 0 && num[i] == num[i - 1]) {
                continue; 
            }
            list.add(num[i]); 
            twoSum(num, i + 1, list, res, -num[i]); 
            list.remove(0); 
        }
        return res; 
    }
    
    private void twoSum(int[] num, int st, List<Integer> prev, List<List<Integer>> res, int target) {
        int ed = num.length - 1; 
        while (st < ed) {
            if (num[st] + num[ed] == target) {
                List<Integer> list = new ArrayList<Integer>(prev); 
                list.add(num[st]); 
                list.add(num[ed]); 
                res.add(list); 
                do{
                    ++st; 
                } while (st < ed && num[st] == num[st - 1]); 
                do {
                    --ed; 
                } while (st < ed && num[ed] == num[ed + 1]); 
            } else if (num[st] + num[ed] > target) {
                --ed; 
            } else {
                ++st; 
            }
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
