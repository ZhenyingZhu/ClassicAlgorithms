/*
 * [Source] https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
 * [Difficulty]: Medium
 * [Tag]: Stack
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: Use a global index. If the left subtree and right subtree are valid, then the tree is valid. When check each node, move index forward 1.
// [Corner Case]: When the tree is valid, there is no more nodes
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes = split(preorder);
for (string &s : nodes)
    cout << s << " ";
cout << endl;
        int idx = 0;
        return isBinaryTree(nodes, idx) && idx == (int)nodes.size() - 1;
    }

    bool isBinaryTree(vector<string> &nodes, int &idx) {
        if (idx >= (int)nodes.size())
            return false;
        if (nodes[idx] == "#")
            return true;

        bool left = isBinaryTree(nodes, ++idx);
        bool right = isBinaryTree(nodes, ++idx);
        return left && right;
    }

    vector<string> split(string &sequance) {
        vector<string> res;
        int st = 0, found = sequance.find_first_of(",");
        while (found != (int)string::npos) {
            res.push_back(sequance.substr(st, found - st));
            st = found + 1;
            found = sequance.find_first_of(",", st);
        }
        res.push_back(sequance.substr(st));
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    //string preorder = "1,#";
    string preorder = "9,#,#,1";
    cout << sol.isValidSerialization(preorder) << endl;

    return 0;
}
