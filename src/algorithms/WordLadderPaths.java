package algorithms; 

import java.util.*; 

public class WordLadderPaths {
    /* Function: Give a string and a set of strings, find all ways to change it to another 
     * string, by only change one character each time. 
     * Solution: Level order traversal, but not delete nodes until finish this level. 
    */
    public List<List<String>> findLadders(String start, String end, Set<String> dict) {
        List<List<String>> res = new ArrayList<List<String>>(); 
        if (start == null || end == null || dict == null || dict.size() == 0) {
            return res; 
        }
        
        dict.add(end); 

        HashMap<String, List<String>> map = new HashMap<String, List<String>>(); 
        Queue<String> queue = new LinkedList<String>(); 
        queue.offer(start); 
        map.put(start, null); 
        
        List<String> level = new ArrayList<String>(); 
        while (!queue.isEmpty()) {
            if (map.containsKey(end)) {
                break; 
            }
            
            level.clear(); 
            while (!queue.isEmpty()) {
                String cur = queue.poll(); 
                dict.remove(cur); 
                level.add(cur); 
            }
            
            for (String parent : level) {
                List<String> children = findChild(parent, dict);
                for (String child : children) {
                    if (!map.containsKey(child)) {
                        map.put(child, new ArrayList<String>()); 
                        queue.offer(child); 
                    }
                    map.get(child).add(parent); 
                }
            }
        }
        
        if (!map.containsKey(end)) {
            return res; // No path there. 
        }
        
        List<String> list = new ArrayList<String>(); 
        list.add(end); 
        createPath(map, end, list, res); 
        return res; 
    }
    
    private List<String> findChild(String parent, Set<String> dict) {
        List<String> children = new ArrayList<String>(); 
        for (int i = 0; i < parent.length(); ++i) {
            char[] tmp = parent.toCharArray(); 
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == parent.charAt(i)) {
                    continue; 
                }
                tmp[i] = c; 
                if (dict.contains(new String(tmp))) {
                    children.add(new String(tmp)); 
                }
            }
        }
        
        return children; 
    }
    
    private void createPath(HashMap<String, List<String>> map, String end, List<String> list, List<List<String>> res) {
        List<String> parents = map.get(end); 
        if (parents == null) { // Start
            res.add(list); 
            return; 
        }
        
        for (String par : parents) {
            List<String> path = new ArrayList<String>(list); 
            path.add(0, par); 
            createPath(map, par, path, res); 
        }
    }
}
