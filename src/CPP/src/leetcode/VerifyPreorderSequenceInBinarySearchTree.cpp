/*
 * [Source] https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Stack
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Solution]: Use Binary Search to find the seperate point of left and right subtree, and then verify the left max value and right min value.
// [Corner Case]:
class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        if (preorder.empty())
            return true;
        return helper(preorder, 0, preorder.size() - 1)[0] != INT_MAX;
    }

    vector<int> helper(vector<int> &preorder, int st, int ed) {
        if (st == ed)
            return {preorder[st], preorder[st]};

        int &root = preorder[st];
        int rightSubtreeSt = findFirstLarger(preorder, root, st + 1, ed);

        vector<int> left = {INT_MIN, root}, right = {root, INT_MAX}; // the default right value
        if (rightSubtreeSt > st + 1) {
            left = helper(preorder, st + 1, rightSubtreeSt - 1);
            if (left[0] == INT_MAX)
                return {INT_MAX, INT_MAX};
        }

        if (rightSubtreeSt <= ed) {
            right = helper(preorder, rightSubtreeSt, ed);
            if (right[0] == INT_MAX)
                return {INT_MAX, INT_MAX};
        }

        if (left[1] > root || right[0] < root)
            return {INT_MAX, INT_MAX}; // invalid

        int min = left[0] == INT_MIN ? root : left[0];
        int max = right[1] == INT_MAX ? root : right[1];
        return {min, max};
    }

    int findFirstLarger(vector<int> &preorder, int target, int st, int ed) {
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            int val = preorder[md];
            if (val > target) {
                ed = md;
            } else {
                st = md;
            }
        }
        if (preorder[st] > target)
            return st;
        if (preorder[ed] > target)
            return ed;
        return ed + 1; // not find
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> preorder = {5,4,2,1,3,7,6};
    //vector<int> preorder = {5,7,4};
    //vector<int> preorder = {1,3,4,2};
    cout << sol.verifyPreorder(preorder) << endl;

    return 0;
}
