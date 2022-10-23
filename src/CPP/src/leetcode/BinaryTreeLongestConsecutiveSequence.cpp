/*
 * [Source] https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/
 * [Difficulty]: Medium
 * [Tag]: Tree
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Traverse the tree
// [Corner Case]:
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)
            return 0;

        unordered_map<TreeNode*, int> lens; // no need to use hash map. Just pass in a number is enough
        int maxLen = 1;
        lens[root] = 1;
        if (root->left != NULL)
            traverse(root, root->left, lens, maxLen);
        if (root->right != NULL)
            traverse(root, root->right, lens, maxLen);
        return maxLen;
    }

    void traverse(TreeNode *par, TreeNode *child, unordered_map<TreeNode*, int> &lens, int &maxLen) {
        if (child->val == par->val + 1) {
            lens[child] = lens[par] + 1;
            maxLen = max(lens[par] + 1, maxLen);
        } else {
            lens[child] = 1;
        }

        if (child->left != NULL)
            traverse(child, child->left, lens, maxLen);
        if (child->right != NULL)
            traverse(child, child->right, lens, maxLen);
    }
};

int main() {
    Solution sol;

    /*
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.right = &n3;
    n3.left = &n2; n3.right = &n4;
    n4.right = &n5;
    */
    TreeNode n1(2), n2(3), n3(2), n4(1);
    n1.right = &n2;
    n2.left = &n3;
    n3.left = &n4;

    cout << sol.longestConsecutive(&n1) << endl;

    return 0;
}
