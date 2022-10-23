/*
 * [Source] https://leetcode.com/problems/combination-sum/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Sort. Add current until larger than target, then remove the last added and try next one.
// [Corner Case]: though same value can use repeatly, if array has dup, it will create dup results
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/CombinationSumRepeatChoose.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(candidates.length<=0 || candidates[0]>target) return result;
        List<Integer> list=new ArrayList<Integer>();
        combination(candidates, target, 0, 0, list, result);
        return result;
    }

    public void combination(int[] num, int target, int sum, int idx, List<Integer> prev, List<List<Integer>> result){
        if(sum>target) return;
        if(sum==target){
            if(!result.contains(prev)){
                List<Integer> list=new ArrayList<Integer>(prev);
                result.add(list);
            }
            return;
        }
        for(int i=idx; i<num.length; i++){
            prev.add(num[i]);
            combination(num, target, sum+num[i], i, prev, result);
            prev.remove(prev.size()-1);
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
