/*
 * [Source] https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use DFS, find the max sum of path to leaf, then combine two paths of left and right child together
// [Corner Case]: if node->val < 0, the max sum of path is 0
class Solution {
private:
    int maxPath;

    int maxPathToLeaf(TreeNode* node) {
        if (node == NULL)
            return 0;

        int left = maxPathToLeaf(node->left);
        int right = maxPathToLeaf(node->right);
        maxPath = max(left + right + node->val, maxPath);
        return max(0, node->val + max(left, right));
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPath = INT_MIN;
        maxPathToLeaf(root);
        return maxPath;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreeMaximumPathSum.java
 */

/* Java solution
public class Solution {
    int max;
    public int maxPathSum(TreeNode root) {
        max=Integer.MIN_VALUE;
        maxRootLeaf(root);
        return max;
    }
    
    public int maxRootLeaf(TreeNode root){
        if(root==null) return 0;
        int lSingle=maxRootLeaf(root.left);
        int rSingle=maxRootLeaf(root.right);
        // If parent is not included in the max path
        if(lSingle+rSingle+root.val>max) max=lSingle+rSingle+root.val; 
        // If left larger or right larger; 
        int single=Math.max(lSingle+root.val, rSingle+root.val);
        // Dont need a negative path
        if(single<0) return 0;
        return single;
    }
 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n2; n1.right = &n3;
    cout << sol.maxPathSum(&n1) << endl;

    return 0;
}
