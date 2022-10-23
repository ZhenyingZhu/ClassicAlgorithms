#include <iostream>

using namespace std;

// [Source]: https://leetcode.com/problems/validate-binary-search-tree/
// http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=212481

struct TreeNode {
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;

        return helper(root).isValid;
    }

private:
    struct MinMaxVal {
        bool isValid;
        int minVal;
        int maxVal;
    };

    MinMaxVal helper(TreeNode *node) {
        int minVal = node->val, maxVal = node->val;

        if (node->left != NULL) {
            MinMaxVal left = helper(node->left);
            if (!left.isValid || left.maxVal >= node->val)
                return {false, 0, 0};
            minVal = left.minVal;
        }

        if (node->right != NULL) {
            MinMaxVal right = helper(node->right);
            if (!right.isValid || right.minVal <= node->val)
                return {false, 0, 0};
            maxVal = right.maxVal;
        }

        return {true, minVal, maxVal};
    }
};
