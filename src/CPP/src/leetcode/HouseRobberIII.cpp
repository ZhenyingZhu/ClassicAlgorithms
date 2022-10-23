/*
 * [Source] https://leetcode.com/problems/house-robber-iii/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: From left and right nodes, get 1. max of (rob this node and left and right nodes' subtree) and rob left and right nodes, 2. rob left and right nodes.
// [Corner Case]:
class Solution {
public:
    struct RobAmount {
        int robNode;
        int notRobNode;
    };

    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;

        RobAmount amt = robTree(root);
        return max(amt.robNode, amt.notRobNode);
    }

    RobAmount robTree(TreeNode *node) {
        if (node == NULL)
            return {0, 0};
        if (node->left == NULL && node->right == NULL)
            return {node->val, 0};

        RobAmount left = robTree(node->left);
        RobAmount right = robTree(node->right);

        int notRobNode = left.robNode + right.robNode;
        int robNode = max(notRobNode, node->val + left.notRobNode + right.notRobNode);
        return {robNode, notRobNode};
    }
};

// [Solution]:

int main() {
    Solution sol;

    //TreeNode n0(3), n1(2), n2(3), n3(3), n4(1);
    //n0.left = &n1; n0.right = &n2; n1.right = &n3; n2.right = &n4;
    TreeNode n0(3), n1(4), n2(5), n3(1), n4(3), n5(1);
    n0.left = &n1; n0.right = &n2; n1.right = &n3; n1.right = &n4; n2.right = &n5;
    cout << sol.rob(&n0) << endl;

    return 0;
}
