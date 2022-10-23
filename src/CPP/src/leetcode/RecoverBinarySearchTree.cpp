/*
 * [Source] https://leetcode.com/problems/recover-binary-search-tree/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// [Solution]: Traverse the tree and find disordered values. Swap the first disordered value with the last disordered value
// [Corner Case]: 21, 321, 4231
class Solution {
private:
    void setReversePtr(TreeNode* cur, TreeNode*& pre, TreeNode*& left, TreeNode*& right) {
        if (pre != NULL && pre->val > cur->val) {
            if (left == NULL)
                left = pre;
            right = cur;
        }
        pre = cur;
    }

public:
    void recoverTree(TreeNode* root) {
        TreeNode* reverseLeft = NULL, * reverseRight = NULL;
        TreeNode* par = root, * run = NULL, * pre = NULL;

        while (par != NULL) {
            if (par->left == NULL) {
                setReversePtr(par, pre, reverseLeft, reverseRight);
                par = par->right;
            } else {
                run = par->left;
                while (run->right != NULL && run->right != par) {
                    run = run->right;
                }
                if (run->right == par) {
                    setReversePtr(par, pre, reverseLeft, reverseRight);
                    par = par->right;
                    run->right = NULL;
                } else {
                    run->right = par;
                    par = par->left;
                }
            }
        }

        swap(reverseLeft->val, reverseRight->val);
    }
};

// helper
void inorderTraverse(TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraverse(root->left);
    cout << root->val << "->";
    inorderTraverse(root->right);
}

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/RecoverBinarySearchTree.java
 */

/* Java solution
public class Solution {
    public void recoverTree(TreeNode root) {
        if(root==null) return;
        if(root.left==null && root.right==null) return;
        TreeNode prev=new TreeNode(Integer.MIN_VALUE); 
        boolean first=false; 
        TreeNode[] disOrder=new TreeNode[2];

        TreeNode ptr=root;
        TreeNode tmp=null;
        while(ptr!=null){
            if(ptr.left==null){
                //System.out.print(ptr.val+" ");
                if(!first){
                    if(ptr.val<prev.val){
                        disOrder[0]=prev; // Keep the largest value
                        disOrder[1]=ptr;
                        first=true;
                    }
                    else prev=ptr;
                }else{
                    if(ptr.val<prev.val){
                        disOrder[1]=ptr; 
                    }
                }
                
                ptr=ptr.right;
            }else{
                tmp=ptr.left;
                while(tmp.right!=null && tmp.right!=ptr){
                    tmp=tmp.right;
                }
                if(tmp.right==ptr){
                    //System.out.print(ptr.val+" ");
                    if(!first){
                        if(ptr.val<prev.val){
                            disOrder[0]=prev; // Keep the largest value
                            disOrder[1]=ptr;
                            first=true;
                        }
                        else prev=ptr;
                    }else{
                        if(ptr.val<prev.val){
                            disOrder[1]=ptr; 
                        }
                    }
                    
                    tmp.right=null;
                    ptr=ptr.right;
                }else{
                    tmp.right=ptr;
                    ptr=ptr.left;
                }
            }
        }
        int temp=disOrder[0].val;
        disOrder[0].val=disOrder[1].val;
        disOrder[1].val=temp;
    }
}
 */

int main() {
    Solution sol;

    TreeNode n1(5), n2(2), n3(3), n4(4), n5(1);
    n3.left = &n1; n3.right = &n5;
    n1.right = &n2;
    n5.left = &n4;
    sol.recoverTree(&n3);

    inorderTraverse(&n3); cout << endl;

    return 0;
}
