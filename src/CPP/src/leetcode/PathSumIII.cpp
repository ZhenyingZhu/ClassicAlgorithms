/*
 * [Source] https://leetcode.com/problems/path-sum-iii/
 * [Difficulty]: Easy
 * [Tag]: Tree
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;

        vector<int> sums = {0};
        return helper(root, sums, sum);
    }

    int helper(TreeNode *root, vector<int> &sums, int target) {
        int cnts = 0;
        int curSum = sums.back() + root->val;
        for (int &preSum : sums) {
            if (curSum - preSum == target)
                ++cnts;
        }

        sums.push_back(curSum);
        if (root->left != NULL)
            cnts += helper(root->left, sums, target);
        if (root->right != NULL)
            cnts += helper(root->right, sums, target);
        sums.pop_back();

        return cnts;
    }
};

int main() {
    Solution sol;
    /*
    TreeNode n0(10), n1(5), n2(-3), n3(3), n4(2), n5(11), n6(3), n7(-2), n8(1);
    n0.left = &n1; n0.right = &n2;
    n1.left = &n3; n1.right = &n4;
    n2.right = &n5;
    n3.left = &n6; n3.right = &n7;
    n4.right = &n8;
    cout << sol.pathSum(&n0, 8) << endl;
    */
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.right = &n2;
    n2.right = &n3;
    n3.right = &n4;
    n4.right = &n5;
    cout << sol.pathSum(&n1, 3) << endl;

    return 0;
}
