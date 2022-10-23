/*
 * [Source] https://leetcode.com/problems/combination-sum-ii/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Backtracking
 */

#include <iostream>

using namespace std;

// [Solution]: Sort. Add, try and remove.
// [Corner Case]: Dup value.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/CombinationSum.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        Arrays.sort(num);
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(num.length<=0 || num[0]>target) return result;
        int ed=num.length-1;
        while(ed>=0 && num[ed]>target) ed--;
        if(num[ed]==target){
            List<Integer> one=new ArrayList<Integer>();
            one.add(target); // Add those equals target number, so the subfunction must use two number
            result.add(one);
        }
        while(ed>=0 && num[ed]==target) ed--;
        List<Integer> list=new ArrayList<Integer>();
        combination(num, target, 0, ed, list, result);
        return result;
    }

    public void combination(int[] num, int target, int st, int ed, List<Integer> prev, List<List<Integer>> result){
        List<Integer> list=new ArrayList<Integer>(prev);
        list.add(num[st]);
        if(st>=ed) return;
        int find=target-num[st];
        int pt=ed;
        while(pt>st && num[pt]>find) pt--; // pt cannot == st
        int newSt=st+1;
        while(newSt<pt && num[newSt]==num[st]) newSt++;
        combination(num, target, newSt, pt, prev, result); // the next same number add, pt cannot -1
        combination(num, find, st+1, pt, list, result); // the +1 number add
        if(pt!=st && num[pt]==find){
            list.add(num[pt]);
            result.add(list);
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
