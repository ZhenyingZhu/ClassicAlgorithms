/*
 * [Source] https://leetcode.com/problems/path-sum-ii/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: DFS with back tracking.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/PathSumSolutions.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> result=new ArrayList<List<Integer>>();
        if(root==null) return result;
        List<Integer> prev=new ArrayList<Integer>();
        pathSum(root, sum, prev, result);
        return result;
    }
    
    public void pathSum(TreeNode root, int sum, List<Integer> prev, List<List<Integer>> result){
        if(root==null) return;
        List<Integer> path=new ArrayList<Integer>(prev);
        path.add(root.val);
        if((sum-root.val)==0 && root.left==null && root.right==null) result.add(path); // should be leaf
        pathSum(root.left, sum-root.val, path, result);
        pathSum(root.right, sum-root.val, path, result);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
