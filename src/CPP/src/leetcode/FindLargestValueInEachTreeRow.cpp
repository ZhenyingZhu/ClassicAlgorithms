/*
 * [Source] https://leetcode.com/problems/find-largest-value-in-each-tree-row
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            res.push_back(INT_MIN);
            for (int i = 0; i < size; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->val > res.back())
                    res.back() = cur->val;

                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n0(1), n1(3), n2(2), n3(5), n4(3), n5(9);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.right = &n5;
    for (int &num : sol.largestValues(&n0))
        cout << num << ", ";
    cout << endl;

    return 0;
}
