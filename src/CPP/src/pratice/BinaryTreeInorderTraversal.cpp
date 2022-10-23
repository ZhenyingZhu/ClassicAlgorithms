#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/binary-tree-inorder-traversal/?tab=Description
// http://www.1point3acres.com/bbs/thread-229660-1-1.html

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<int> res;

        stack<TreeNode*> stack;
        TreeNode *cur = root;
        while (!stack.empty() || cur != NULL) {
            while (cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            }

            TreeNode *print = stack.top();
            stack.pop();
            res.push_back(print->val);
            cur = print->right;
        }

        return res;
    }
};

int main() {
    Solution sol;

    TreeNode n0(0), n1(1), n2(2);
    n0.left = &n1; n0.right = &n2;
    for (int &num : sol.inorderTraversal(&n0))
        cout << num << " ";
    cout << endl;

    return 0;
}
