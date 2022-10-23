#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.meetqun.net/thread-44981-1-1.html
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    string serialize(TreeNode *root) {
        if (root == NULL)
            return "";

        string res;
        preorder(root, res);
        return res.substr(0, res.length() - 1);
    }

    void preorder(TreeNode *node, string &res) {
        // no need to check if node is null
        res += to_string(node->val) + ",";
        if (node->left != NULL)
            preorder(node->left, res);
        if (node->right != NULL)
            preorder(node->right, res);
    }

    TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        vector<int> nodes = split(data, ",");
        return helper(nodes, 0, nodes.size() - 1);
    }

    TreeNode* helper(vector<int> &nodes, int st, int ed) {
        if (st > ed)
            return NULL;
        TreeNode *node = new TreeNode(nodes[st]);
        if (st == ed)
            return node;

        int mid = st + 1;
        while (mid <= ed && nodes[mid] <= nodes[st])
            ++mid;

        node->left = helper(nodes, st + 1, mid - 1);
        node->right = helper(nodes, mid, ed);

        return node;
    }

    vector<int> split(string &data, string token) {
        vector<int> res;

        int st = 0;
        size_t pos = data.find_first_of(token);
        while (pos != string::npos) {
            res.push_back( stoi(data.substr(st, pos - st)) );
            st = pos + 1;
            pos = data.find_first_of(token, st);
        }
        res.push_back( stoi(data.substr(st)) );

        return res;
    }
};

void traverse(TreeNode *root) {
    if (root == NULL)
        return;
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
}

int main() {
    TreeNode n0(0), n1(1), n2(3), n3(3), n4(4);
    n3.left = &n1; n3.right = &n4;
    n1.left = &n0; n1.right = &n2;

    Solution sol;
    string res = sol.serialize(&n3);
    cout << res << endl;
    TreeNode *root = sol.deserialize(res);
    traverse(root);
    cout << endl;

    return 0;
}
