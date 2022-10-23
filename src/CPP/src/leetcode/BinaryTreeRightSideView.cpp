/*
 * [Source] https://leetcode.com/problems/binary-tree-right-side-view/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Level order traverse
// [Corner Case]: root is null.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            res.push_back(q.front()->val);
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->right != NULL)
                    q.push(cur->right);
                if (cur->left != NULL)
                    q.push(cur->left);
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

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n5;
    n3.right = &n4;
    for (int& i : sol.rightSideView(&n1)) 
        cout << i << " ";
    cout << endl;

    return 0;
}
