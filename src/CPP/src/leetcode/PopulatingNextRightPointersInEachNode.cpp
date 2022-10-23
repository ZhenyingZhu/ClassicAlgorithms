/*
 * [Source] https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Maintain the knowledge about parent node. If it is left child, its next is right child, otherwise its parent next left child. Use DFS
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/PopulatingNextRightPointersInEachNodePerfectBinaryTree.java
 */

// [Solution]: Use BFS
/* Java solution
public class Solution {
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

int main() {
    Solution sol;

    return 0;
}
