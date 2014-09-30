package algorithms; 

import java.util.*; 

public class TopologicalSorting {
    /* Function: Input a string array show dependency, return the order. 
     * Solution: DFS to record the end time, and sort from bigger to smaller. 
    */
    private class Node {
        char label; 
        int st = 0, ed = 0; 
        List<Node> neighbors = new ArrayList<Node>(); 
        public Node(char c) {
            label = c; 
        }
    }
    
    public List<Character> orderChar(String[] inputs) {
        List<Character> res = new ArrayList<Character>(); 
        if (inputs == null || inputs.length == 0) {
            return res; 
        }
        
        HashMap<Character, Node> map = new HashMap<Character, Node>(); 
        for (int i = 0; i < inputs.length; ++i) {
            char fir = inputs[i].charAt(0); 
            char sec = inputs[i].charAt(1); 
            if (!map.containsKey(fir)) {
                map.put(fir, new Node(fir)); 
            }
            if (!map.containsKey(sec)) {
                map.put(sec, new Node(sec)); 
            }
            
            Node n0 = map.get(fir); 
            Node n1 = map.get(sec); 
            n0.neighbors.add(n1); 
        }
        
        topologicalSorting(map, res); 
        return res; 
    }
    
    private void topologicalSorting(HashMap<Character, Node> map, List<Character> res) {
        Queue<Node> heap = new PriorityQueue<Node>(map.size(), NodeComparator); 
        int time = 0; 
        for (Node node : map.values()) {
            if (heap.contains(node)) {
                continue; 
            }
            time = dfs(node, heap, time); 
        }
        
        if (time == -1) {
            res.clear(); 
            return; 
        }
        while (!heap.isEmpty()) {
            res.add(0, heap.poll().label); 
        }
    }
    
    private Comparator<Node> NodeComparator = new Comparator<Node>() {
        public int compare(Node n0, Node n1) {
            return n0.ed - n1.ed; 
        }
    }; 
    
    private int dfs(Node node, Queue<Node> heap, int time) {
        node.st = ++time; 
        for (Node nei : node.neighbors) {
            if (nei.st != 0) {
                if (nei.ed == 0) {
                    return -1; // Cycle
                }
            } else {
                time = dfs(nei, heap, time); 
                if (time == -1) {
                    return -1; 
                }
            }
        }
        
        node.ed = ++time; 
        heap.offer(node); 
        return time; 
    }
}
