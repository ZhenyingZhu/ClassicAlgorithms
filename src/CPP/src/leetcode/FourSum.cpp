/*
 * [Source] https://leetcode.com/problems/4sum/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Hash Table
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Sort the array. Fix first two elements, and use two sum.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/FourSum.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> fourSum(int[] num, int target) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        if (num == null || num.length < 4) {
            return result;
        }
        Arrays.sort(num);
        for (int i = 0; i < num.length - 3; ++i) {
            if (i != 0 && num[i] == num[i-1]) {
                continue;
            }
            List<Integer> list = new ArrayList<Integer>();
            list.add(num[i]);
            threeSum(num, target - num[i], i + 1, list, result);
        }
        return result;
    }

    private void threeSum(int[] num, int target, int start, List<Integer> prev, List<List<Integer>> result) {
        for (int i = start; i < num.length - 2; ++i) {
            if (i != start && num[i] == num[i-1]) {
                continue;
            }
            List<Integer> list = new ArrayList<Integer>(prev);
            list.add(num[i]);
            twoSum(num, target - num[i], i + 1, list, result);
        }
    }

    private void twoSum(int[] num, int target, int start, List<Integer> prev, List<List<Integer>> result) {
        int head = start;
        int tail = num.length - 1;
        int tmp;
        while (head < tail) {
            if (num[head] + num[tail] == target) {
                List<Integer> list = new ArrayList<Integer>(prev);
                list.add(num[head]);
                list.add(num[tail]);
                result.add(list);
                tmp = num[head];
                while (num[head] == tmp && head < tail) {
                    ++head;
                }
                tmp = num[tail];
                while (num[tail] == tmp && tail > head) {
                    --tail;
                }
            } else if (num[head] + num[tail] > target) {
                tmp = num[tail];
                while (num[tail] == tmp && tail > head) {
                    --tail;
                }
            } else { // < num[head] + num[tail] < target
                tmp = num[head];
                while (num[head] == tmp && head < tail) {
                    ++head;
                }
            }
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
