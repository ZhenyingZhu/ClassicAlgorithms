package algorithms.treeandgraph; 

import java.util.*; 
import lib.UndirectedGraphNode; 

public class GraphPathBetweenNodes {
    /* Function: Find if there is a path between two nodes. 
     * Solution: BFS. 
     */ 
    
    public boolean hasRoute(UndirectedGraphNode src, UndirectedGraphNode des) {
        if (src == null || des == null) {
            return false; 
        }
        
        Set<UndirectedGraphNode> set = new HashSet<UndirectedGraphNode>(); 
        Queue<UndirectedGraphNode> queue = new LinkedList<UndirectedGraphNode>(); 
        queue.offer(src); 
        
        while (!queue.isEmpty()) {
            UndirectedGraphNode cur = queue.poll(); 
            for (UndirectedGraphNode nei : cur.neighbors) { 
                if (nei == des) {
                    return true; 
                }
                
                if (!set.contains(nei)) {
                    set.add(nei); 
                    queue.offer(nei); 
                }
            }
        }
        
        return false; 
    }
} 