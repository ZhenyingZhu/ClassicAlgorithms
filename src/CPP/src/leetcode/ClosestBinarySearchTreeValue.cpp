/*
 * [Source] https://leetcode.com/problems/closest-binary-search-tree-value/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Binary Search
 */

#include <iostream>
#include <climits>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Actually no need to find both upper and lower. as if root>target, any right subtree is not needed.
// [Corner Case]:
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int lower = INT_MIN;
        bool lowerUpdate = false;
        TreeNode *cur = root;
        while (cur != NULL) {
            if ((double)cur->val > target) {
                cur = cur->left;
            } else {
                lowerUpdate = true;
                lower = cur->val;
                cur = cur->right;
            }
        }

        int upper = INT_MAX;
        bool upperUpdate = false;
        cur = root;
        while (cur != NULL) {
            if ((double)cur->val < target) {
                cur = cur->right;
            } else {
                upperUpdate = true;
                upper = cur->val;
                cur = cur->left;
            }
        }

        double diffLow = lowerUpdate ? target - (double)lower : numeric_limits<double>::max();
        double diffUp = upperUpdate ? (double)upper - target : numeric_limits<double>::max();
        if (diffLow < diffUp)
            return lower;
        return upper;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n5.left = &n4; n5.right = &n7;
    n4.left = &n2;
    n2.left = &n1; n2.right = &n3;
    n7.left = &n6;

    for (double i = 1.0; i <= 8.0; i += 0.5)
        cout << sol.closestValue(&n5, i) << endl;

    return 0;
}
