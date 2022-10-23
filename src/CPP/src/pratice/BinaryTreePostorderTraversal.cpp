#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// [Source]: https://leetcode.com/problems/binary-tree-postorder-traversal/

struct TreeNode {
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    vector<int> postOrderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> stack;
        TreeNode *run = root;
        stack.push(run);

        while (!stack.empty()) {
            // push root of each subtree to stack twice
            // first traverse all left nodes
            while (run != NULL) {
                stack.push(run);
                run = run->left;
            }

            TreeNode *prev = NULL;
            run = stack.top();
            stack.pop();

            while (!stack.empty()) {
                if (run->right == prev) {
                    // right is visited, run can be print
                    res.push_back(run->val);
                    prev = run;
                    run = stack.top();
                    stack.pop();
                } else {
                    // deal with the right subtree
                    stack.push(run);
                    run = run->right;
                    break;
                }
            }
        }

        return res;
    }
};

int main() {
    Solution sol;

    TreeNode n0(0), n1(1), n2(2), n3(3), n4(4);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    for (int &n : sol.postOrderTraversal(&n0))
        cout << n << "->";
    cout << endl;

    return 0;
}
