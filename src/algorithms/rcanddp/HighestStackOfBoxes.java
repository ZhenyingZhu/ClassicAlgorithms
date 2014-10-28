package algorithms.rcanddp; 

import java.util.*; 

public class HighestStackOfBoxes {
    /* Function: Box can only be placed on the box that is larger on height, length, width together. 
     * Solution: Need to return a list, so the value of hashmap is list. 
     */ 
    
    public List<Box> createStack(Box[] boxes) {
        List<Box> res = new ArrayList<Box>(); 
        if (boxes == null || boxes.length == 0) {
            return res; 
        }
        
        Arrays.sort(boxes); 
        
        Map<Box, List<Box>> map = new HashMap<Box, List<Box>>(); 
        res = boxHelper(boxes, -1, map); 
        return res; 
    }
    
    private List<Box> boxHelper(Box[] boxes, int idx, Map<Box, List<Box>> map) {
        List<Box> res = new ArrayList<Box>(); 
        if (idx == boxes.length) {
            return res; 
        }
        
        Box key = idx == -1 ? new Box(Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE) : boxes[idx]; 
        if (map.containsKey(key)) {
            return map.get(key); 
        }
        
        int maxHeight = 0; 
        Box max = null;  
        for (int i = idx + 1; i < boxes.length; ++i) {
            if (boxes[i].l >= key.l || boxes[i].h >= key.h) {
                continue; 
            }
            
            List<Box> upper = boxHelper(boxes, i, map); 
            if (maxHeight < getHeight(upper)) {
                maxHeight = getHeight(upper); 
                max = boxes[i]; 
            }
        }
        
        if (idx != -1) {
            res.add(key); 
        }
        if (max != null) {
            res.addAll(map.get(max)); 
        }
        
        map.put(key, res); 
        return res; 
    }
    
    private int getHeight(List<Box> boxes) {
        int height = 0; 
        for (Box box : boxes) {
            height += box.h; 
        }
        return height; 
    }
}

class Box implements Comparable<Box> {
    int h; 
    int w; 
    int l; 
    
    public Box(int l, int w, int h) {
        this.l = l; 
        this.w = w; 
        this.h = h; 
    }
    
    public int compareTo(Box box) {
        if (box == null) {
            return -1; 
        }
        
        return box.w - this.w; 
    }
    
    public String toString() {
        return "(" + l + ", " + w + ", " + h + ") "; 
    }
}