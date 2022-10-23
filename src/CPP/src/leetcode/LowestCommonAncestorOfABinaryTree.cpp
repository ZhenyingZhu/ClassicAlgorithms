/*
 * [Source] https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use return node of root to indicate if p or q shows under root subtree.
// [Corner Case]: p or q not exist in the tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // cannot solve the problem when p or q not exist. Need a wrapper, and two flags to indicate if p and q both show up
        if (root == NULL || p == NULL || q == NULL)
            return NULL;

        if (root == p || root == q)
            return root;

        TreeNode* leftCommon = lowestCommonAncestor(root->left, p, q);
        if (leftCommon != NULL && leftCommon != p && leftCommon != q)
            return leftCommon;
        TreeNode* rightCommon = lowestCommonAncestor(root->right, p, q);
        if ( (leftCommon == p && rightCommon == q) || (leftCommon == q && rightCommon == p) )
            return root;

        return leftCommon == NULL ? rightCommon : leftCommon;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n0(0), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8), n9(9);
    n6.left = &n2; n6.right = &n8;
    n2.left = &n0; n2.right = &n4;
    n4.left = &n3; n4.right = &n5;
    n8.left = &n7; n8.right = &n9;

    cout << sol.lowestCommonAncestor(&n6, &n8, &n2)->val << endl;
    cout << sol.lowestCommonAncestor(&n6, &n2, &n4)->val << endl;
    return 0;
}
