/*
 * [Source] https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * [Difficulty]: Easy
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

// [Solution]: Use the property of BST to check if two nodes are on different sides. 
// [Corner Case]:
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == NULL || q == NULL)
            return NULL;

        int large = max(p->val, q->val), small = min(p->val, q->val);
        if (root->val >= small && root->val <= large)
            return root;

        if (root->val > large)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
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
