/*
 * [Source] https://leetcode.com/problems/sum-of-left-leaves/
 * [Difficulty]: Easy
 * [Tag]: Tree 
 */

#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL)
            return 0;

        int sum = 0;
        TreeNode dummy(0);
        dummy.right = root;
        helper(&dummy, root, sum);
        return sum;
    }

    void helper(TreeNode *parent, TreeNode *node, int &sum) {
        if (node->left == NULL && node->right == NULL) {
            if (node == parent->left)
                sum += node->val;
            return;
        }

        if (node->left != NULL)
            helper(node, node->left, sum);
        if (node->right != NULL)
            helper(node, node->right, sum);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n0(3), n1(9), n2(20), n3(15), n4(7);
    n0.left = &n1; n0.right = &n2;
    n2.left = &n3; n2.right = &n4;

    cout << sol.sumOfLeftLeaves(&n0) << endl;

    return 0;
}
