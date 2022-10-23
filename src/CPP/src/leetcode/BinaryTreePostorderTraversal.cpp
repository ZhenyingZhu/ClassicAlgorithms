/*
 * [Source] https://leetcode.com/problems/binary-tree-postorder-traversal/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Stack
 */

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Use a stack and a hash map to track how many times a node is pushed into the stack. If it pushed 1 times, push its left; 2 right; 3 pop.
// [Corner Case]:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        unordered_map<TreeNode*, int> popFreq;

        while (!nodeStack.empty()) {
            TreeNode* cur = nodeStack.top();
            ++popFreq[cur];
            if (popFreq[cur] == 3) {
                res.push_back(cur->val);
                nodeStack.pop();
            } else if (popFreq[cur] == 1) {
                if (cur->left != NULL) {
                    nodeStack.push(cur->left);
                }
            } else {
                if (cur->right != NULL) {
                    nodeStack.push(cur->right);
                }
            }
        }

        return res;
    }
};

// [Solution]:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
            return {};

        vector<int> res;
        stack<TreeNode*> stack;
        TreeNode *run = root;
        while (!stack.empty() || run != NULL) {
            while (run != NULL) {
                stack.push(run);
                run = run->left;
            }

            TreeNode *prev = NULL;
            while (!stack.empty()) {
                run = stack.top();
                if (run->right == prev) {
                    res.push_back(run->val);
                    prev = run;
                    stack.pop();
                    run = NULL;
                } else {
                    run = run->right;
                    break;
                }
            }
        }
        return res;
    }
};

// [Solution]: Push root into stack twice. First push all left. Then get the last one, and check if its right is NULL. Then in a loop get all printable nodes. Push the right child of last node and continue.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreePostorderTraversal.java
 */

/* Java solution
public class Solution {
    public List<Integer> postorderTraversal(TreeNode root) {
		// Left, right, mid
		List<Integer> list=new ArrayList<Integer>();
		if(root==null) return list;
		Stack<TreeNode> stack=new Stack<TreeNode>();
		TreeNode current=root;
		stack.push(current);
		while(!stack.isEmpty()){
			while(current!=null){
				stack.push(current);
				current=current.left;
			}
			TreeNode visited=null;
			current=stack.pop();
			while(!stack.isEmpty()){
				if(current.right==visited){
					list.add(current.val);
					visited=current;
					current=stack.pop();
				}else{
					stack.push(current);
					current=current.right;
					break;
				}
			}
		}
		return list;
	}
}
 */

int main() {
    Solution sol;

    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n4;
    n3.left = &n5; n3.right = &n6;
    n6.left = &n7;

    for (int& val : sol.postorderTraversal(&n1)) {
        cout << val << "->";
    }
    cout << endl;

    return 0;
}
