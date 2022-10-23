/*
 * [Source] https://leetcode.com/problems/count-univalue-subtrees/
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

// [Solution]: The whole subtree has only one value. Use recursive call.
// [Corner Case]:
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL)
            return 0;

        int res = 0;
        helper(root, res);
        return res;
    }

    bool helper(TreeNode *root, int &res) {
        bool left = true, right = true;
        if (root->left != NULL)
            left = helper(root->left, res);
        if (root->right != NULL)
            right = helper(root->right, res);

        if (left && right) {
            bool same = true;
            if (root->left != NULL && root->left->val != root->val)
                same = false;
            if (root->right != NULL && root->right->val != root->val)
                same = false;

            if (same) {
                ++res;
                return true;
            }
        }

        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n0(5), n1(1), n2(5), n3(5), n4(5), n5(5);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.right = &n5;

    cout << sol.countUnivalSubtrees(&n0) << endl;

    return 0;
}
