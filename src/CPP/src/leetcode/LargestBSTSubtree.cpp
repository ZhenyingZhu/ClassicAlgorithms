/*
 * [Source] https://leetcode.com/problems/largest-bst-subtree/
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

// [Solution]: Use metadata to pass out max subtree nodes, smallest number and largest number. If both left and right subtrees are valid and they are valid to the root node, then add up nodes. Otherwise pick the largest nodes from left or right subtree
// [Corner Case]:
class Solution {
public:
    struct BSTMetadata {
        // no matter valid or not, nodes indicate the largest subtree size
        bool valid;
        int smallest;
        int largest;
        int nodes;
    };

    int largestBSTSubtree(TreeNode* root) {
        if (root == NULL)
            return 0;

        BSTMetadata m = helper(root);
        return m.nodes;
    }

    BSTMetadata helper(TreeNode *root) {
        if (root->left == NULL && root->right == NULL) {
            return {true, root->val, root->val, 1};
        }

        bool valid = true;
        int smallest = root->val, largest = root->val;
        int leftNodes = 0, rightNodes = 0;
        if (root->left != NULL) {
            BSTMetadata left = helper(root->left);
            if (!left.valid || left.largest >= root->val) {
                valid = false;
            } else {
                smallest = left.smallest;
            }
            leftNodes = left.nodes;
        }
        if (root->right != NULL) {
            BSTMetadata right = helper(root->right);
            if (!right.valid || right.smallest < root->val) {
                valid = false;
            } else {
                largest = right.largest;
            }
            rightNodes = right.nodes;
        }

        if (valid)
            return {true, smallest, largest, 1 + leftNodes + rightNodes};
        else
            return {false, smallest, largest, max(leftNodes, rightNodes)};
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n0(10), n1(5), n2(15), n3(1), n4(8), n5(7);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.right = &n5;

    cout << sol.largestBSTSubtree(&n0) << endl;

    return 0;
}
