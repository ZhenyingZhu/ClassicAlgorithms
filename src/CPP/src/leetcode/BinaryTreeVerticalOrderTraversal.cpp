/*
 * [Source] https://leetcode.com/problems/binary-tree-vertical-order-traversal/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use a hash map to record level
// [Corner Case]:
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        unordered_map<TreeNode*, int> nodeLevelMap;
        nodeLevelMap[root] = 0;

        unordered_map<int, vector<int>> levelVectorMap;
        int minLevel = 0;
        helper(root, nodeLevelMap, levelVectorMap, minLevel);

        for (int i = minLevel; levelVectorMap.count(i); ++i) {
cout << i << ": ";
for (int &n : levelVectorMap[i]) cout << n << " ";
cout << endl;
            res.push_back(levelVectorMap[i]);
        }
        return res;
    }

    void helper(TreeNode *root, unordered_map<TreeNode*, int> &nodeLevelMap, unordered_map<int, vector<int>> &levelVectorMap, int &minLevel) {
        nodeLevelMap[root] = 0;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            int level = nodeLevelMap[node];
            minLevel = min(level, minLevel);
            levelVectorMap[level].push_back(node->val);

            if (node->left != NULL) {
                nodeLevelMap[node->left] = level - 1;
                q.push(node->left);
            }

            if (node->right != NULL) {
                nodeLevelMap[node->right] = level + 1;
                q.push(node->right);
            }
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    /*
    TreeNode n0(3), n1(9), n2(20), n3(15), n4(7);
    n0.left = &n1; n0.right = &n2;
    n2.left = &n3; n2.right = &n4;
    */
    TreeNode n0(3), n1(9), n2(8), n3(4), n4(0), n5(1), n6(7);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.left = &n5; n2.right = &n6;

    for (vector<int> &vec : sol.verticalOrder(&n0)) {
        for (int &i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
