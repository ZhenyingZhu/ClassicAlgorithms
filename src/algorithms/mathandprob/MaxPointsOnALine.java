package algorithms.mathandprob; 

import java.util.*; 
import lib.Point; 

public class MaxPointsOnALine {
    /* Function: Given a set of points, find the max number of points on a line. 
     * Solution: Compare each two once. Be careful: 1. Duplicate node; 2. double 0.0
     *     != -0.0. 
     */ 
    
    public int maxPoints(Point[] points) {
        if (points == null || points.length == 0) {
            return 0; 
        }
        
        int max = 1; 
        HashMap<Double, Integer> map = new HashMap<Double, Integer>(); 
        for (int i = 0; i < points.length - 1; ++i) {
            map.clear(); 
            Point st = points[i]; 
            int overlap = 1; // points equal to start
            for (int j = i + 1; j < points.length; ++j) {
                Point ed = points[j]; 
                if (st.x == ed.x && st.y == ed.y) {
                    ++overlap; 
                } else {
                    double slope = computeSlope(st, ed); 
                    if (!map.containsKey(slope)) {
                        map.put(slope, 0); 
                    }
                    map.put(slope, map.get(slope) + 1); 
                }
            }
            
            max = Math.max(max, overlap); 
            for (double key : map.keySet()) {
                max = Math.max(max, map.get(key) + overlap); 
            }
        }
        
        return max; 
    }
    
    private double computeSlope(Point st, Point ed) {
        if (st.x == ed.x) {
            return Double.MAX_VALUE; 
        }
        
        return 0.0 + (double)(ed.y - st.y)/(double)(ed.x - st.x); 
    }
}
