#include <iostream>

using namespace std;

struct TreeNode {
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
    int val;
    TreeNode *left, *right;
};

// [Source]: https://leetcode.com/problems/count-complete-tree-nodes/
// http://www.1point3acres.com/bbs/thread-224069-1-1.html

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftHeight = 0;
        TreeNode *left = root;
        while (left != NULL) {
            ++leftHeight;
            left = left->left;
        }

        int rightHeight = 0;
        TreeNode *right = root;
        while (right != NULL) {
            ++rightHeight;
            right = right->right;
        }

        if (leftHeight == rightHeight) {
            /*
            int nodes = 1;
            int cnt = 0;
            for (int i = 0; i < leftHeight; ++i) {
                cnt += nodes;
                nodes *= 2;
            }
            return cnt;
            */
            // a better solution is
            return (1 << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Solution sol;

    TreeNode n0(0), n1(1);
    n0.right = &n1;
    cout << sol.countNodes(&n0) << endl;

    return 0;
}
