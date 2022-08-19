package algorithms.treeandgraph; 

import java.util.*; 

public class WordLadder {
    /* Function: Given start and end string and a dict, each time change one char, find the length 
     *     of path to change start to end. If not exist, return 0. 
     * Solution: BFS. 
     */ 
    
    public int ladderLength(String start, String end, Set<String> dict) {
        if (start == null || end == null || dict == null || dict.size() == 0) {
            return 0; 
        }
        
        dict.add(end); 
        HashMap<String, Integer> map = new HashMap<String, Integer>(); 
        map.put(start, 1); 
        
        Queue<String> queue = new LinkedList<String>(); 
        queue.offer(start); 
        while (!queue.isEmpty()) {
            if (map.containsKey(end)) {
                return map.get(end); 
            }
            
            String cur = queue.poll(); 
            int level = map.get(cur); 
            
            for (int i = 0; i < cur.length(); ++i) {
                char[] arr = cur.toCharArray(); 
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == cur.charAt(i)) {
                        continue; 
                    }
                    arr[i] = c; 
                    
                    if (dict.contains(new String(arr))) {
                        String node = new String(arr); 
                        map.put(node, level + 1); 
                        dict.remove(node); 
                        queue.offer(node); 
                    }
                }
            }
        }
        
        return 0; 
    }
}
