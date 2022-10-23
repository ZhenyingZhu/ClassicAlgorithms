/*
 * [Source] https://leetcode.com/problems/clone-graph/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first search
 * [Tag]: Graph
 */

#include <iostream>

using namespace std;

// [Solution]: Use a hash table to record node mapping. Key is the node in the origin graph, and value is the new node. Do DFS on the old graph and copy nodes.
// [Corner Case]:
class Solution {
};

/* Java solution
public class Solution {
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if(node==null) return node;
		HashMap<UndirectedGraphNode, UndirectedGraphNode> map=new HashMap<UndirectedGraphNode, UndirectedGraphNode>();
		return clone(node, map);
    }
	
	public UndirectedGraphNode clone(UndirectedGraphNode node, HashMap<UndirectedGraphNode, UndirectedGraphNode> map){
		// DFS
		if(map.containsKey(node)) return map.get(node);
		UndirectedGraphNode copy=new UndirectedGraphNode(node.label);
		map.put(node, copy); // So if there is a cycle for self, wont make dup copy
		for(UndirectedGraphNode neighbor: node.neighbors){
			copy.neighbors.add(clone(neighbor, map));
		}
		return copy; 
	}
}
 */

// [Solution]: BFS
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/CloneGraphBFS.java
 */

int main() {
    Solution sol;

    return 0;
}
