/*
 * [Source] https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * [Difficulty]: Hard
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// [Solution]: Cannot use DFS, need use BFS. Thus parents are already linked together. Check the next not-null node.
// [Corner Case]: not parent->next but next next. DFS can only get next.
class Solution {
private:
    void connectHelper(TreeLinkNode *parent, TreeLinkNode *cur) {
        vector<TreeLinkNode*> candidates;
        if (cur == parent->left) {
            if (parent->right != NULL) {
                cur->next = parent->right;
                return;
            }
        }

        while (parent->next != NULL) {
            if (parent->next->left != NULL) {
                cur->next = parent->next->left;
                return;
            }
            if (parent->next->right != NULL) {
                cur->next = parent->next->right;
                return;
            }
            parent = parent->next;
        }
    }

public:
    void connect(TreeLinkNode *root) {
        if (root == NULL)
            return;
        queue<TreeLinkNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeLinkNode *par = queue.front();
            queue.pop();

            if (par->left != NULL) {
                connectHelper(par, par->left);
                queue.push(par->left);
            }
            if (par->right != NULL) {
                connectHelper(par, par->right);
                queue.push(par->right);
            }
        }
    }
};

// [Solution]: Use DFS but link children first. Do it from right to left.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/PopulatingNextRightPointersInEachNode.java
 */

// [Solution]: Level order traverse
/* Java solution
public class Solution { // Wrong, not constant extra space
    public void connect(TreeLinkNode root) {
        if(root==null) return;
        int level=0;
        ArrayList<TreeLinkNode> array=new ArrayList<TreeLinkNode>();
        array.add(root);
        int size=1;
        while(!array.isEmpty()){
            int cnt=0;
            for(int i=0; i<size; i++){
                TreeLinkNode cur=array.get(i);
                if(cur.left!=null){
                    array.add(cur.left); 
                    cnt++;
                }
                if(cur.right!=null){
                    array.add(cur.right);
                    cnt++;
                }
            }
            for(int i=0; i<size; i++){
                array.remove(0);
            }
            size=cnt;
            if(cnt<=1) continue;
            TreeLinkNode tail=array.get(cnt-1);
            for(int j=cnt-2; j>=0; j--){
                TreeLinkNode node=array.get(j);
                node.next=tail;
                tail=node;
            }
        }
    }
}
 */

// Helper
void printList(TreeLinkNode *n) {
    while (n != NULL) {
        cout << n->val << "->";
        n = n->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    /*
    TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    n3.left = &n7;

    TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    */
    TreeLinkNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n6.right = &n8;

    sol.connect(&n1);

    printList(&n1); printList(&n2); printList(&n4); printList(&n7);

    return 0;
}
