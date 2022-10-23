/*
 * [Source] https://leetcode.com/problems/count-of-smaller-numbers-after-self/
 * [Difficulty]: Hard
 * [Tag]: Divide and Conquer
 * [Tag]: Binary Indexed Tree
 * [Tag]: Segment Tree
 * [Tag]: Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>

using namespace std;

// [Solution]: Use tree nodes. The node counts how many showed numbers in its left tree. So that when a larger number comes, add its left tree nodes, and itself to the result.
// [Corner Case]:
class Solution {
public:
    struct Node {
        Node(int v): val(v), smallerCnt(0), left(NULL), right(NULL) { }
        int val;
        int smallerCnt; // left nodes count not smaller numbers count
        Node *left, *right;
    };

    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return {};

        vector<int> res(nums.size());
        res.back() = 0;
        Node *root = new Node(nums.back());

        for (int i = nums.size() - 2; i >= 0; --i) {
            Node *node = new Node(nums[i]);
            res[i] = insert(root, node);
        }


        return res;
    }

    int insert(Node *root, Node *node) {
        if (root->val > node->val) {
            ++root->smallerCnt;
            if (root->left == NULL) {
                root->left = node;
                return 0;
            } else {
                return insert(root->left, node);
            }
        } else {
            if (root->right == NULL) {
                root->right = node;
                return root->smallerCnt + (root->val < node->val ? 1 : 0); // deal with same value
            } else {
                return insert(root->right, node) + root->smallerCnt + (root->val < node->val ? 1 : 0);
            }
        }
    }
};

// [Solution]: Construct a sort array in fly, so that BS the array can return the index which indicate how many numbers are smaller. Then insert the number to the array
class SolutionArray {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> sortNums;

        vector<int> res(nums.size(), 0);
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            int pos = findLargestSmaller(sortNums, nums[i]);
            res[i] = pos;
            sortNums.insert(sortNums.begin() + pos, nums[i]);
        }
        return res;
    }

    int findLargestSmaller(vector<int>& nums, int val) {
        if (nums.size() == 0)
            return 0;
        int st = 0, ed = (int)nums.size() - 1;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (nums[md] >= val) {
                ed = md;
            } else {
                st = md;
            }
        }
        if (nums[ed] < val)
            return ed + 1;
        if (nums[st] < val)
            return st + 1;
        return 0; // when val smaller than the first element
    }
};

class WrongSolution {
public:
    // Wrong because if not simply decrease, the result is wrong
    vector<int> countSmallerWrong(vector<int>& nums) {
        vector<int> res(nums.size());

        unordered_map<int, int> numCnt;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            ++numCnt[nums[i]];
            int cnt = 0;
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                if (nums[j] < nums[i]) {
                    cnt = numCnt[nums[j]] + res[j];
                    break;
                }
            }
            res[i] = cnt;
        }

        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> nums = {5, 2, 6, 1};
    //vector<int> nums = {5, 3, 3, 3, 2, 2, 1};
    vector<int> nums = {5, 3, 2, 3, 1};
    for (int& cnt : sol.countSmaller(nums))
        cout << cnt << " ";
    cout << endl;

    return 0;
}
