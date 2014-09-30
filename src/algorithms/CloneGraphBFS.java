package algorithms; 

import java.util.*; 
import lib.UndirectedGraphNode; 

public class CloneGraphBFS {
    /* Function: Check if a string is interleaving combined by two strings. 
     * Solution: DP. 
    */
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null || node.neighbors == null) {
            return node; 
        }
        
        HashMap<UndirectedGraphNode, UndirectedGraphNode> map = new HashMap<UndirectedGraphNode, UndirectedGraphNode>(); 
        UndirectedGraphNode root = new UndirectedGraphNode(node.label); 
        map.put(node, root); 
        
        Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>(); 
        queue.offer(node); 
        while (!queue.isEmpty()) {
            UndirectedGraphNode cur = queue.poll(); 
            UndirectedGraphNode cpy = map.get(cur); 
            if (cur.neighbors != null) {
                for (UndirectedGraphNode nei : cur.neighbors) {
                    if (!map.containsKey(nei)) {
                        map.put(nei, new UndirectedGraphNode(nei.label)); 
                        queue.offer(nei); 
                    }
                    cpy.neighbors.add(map.get(nei)); 
                }
            }
        }
        
        return root; 
    }
}
