/*
 * [Source] https://leetcode.com/problems/inorder-successor-in-bst/
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

// [Solution]: Inorder traverse with stack.
// [Corner Case]:
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->left;
        }

        bool returnNext = false;
        while (!stk.empty()) {
            TreeNode *cur = stk.top();
            stk.pop();
            if (returnNext)
                return cur;
            if (cur == p)
                returnNext = true;

            cur = cur->right;
            while (cur != NULL) {
                stk.push(cur);
                cur = cur->left;
            }
        }
        return NULL;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
