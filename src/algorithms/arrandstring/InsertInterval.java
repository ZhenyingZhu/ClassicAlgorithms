package algorithms.arrandstring; 

import java.util.*; 
import lib.Interval; 

public class InsertInterval {
    /* Function: Given a list of intervals and a new interval, merge them. 
     * Solution: First find the first interval that ed>=new.ed. This interval
     *     need to be merged. Then find the first interval that st>new.ed. Previous
     *     intervals need to be merged. The edge case is that if these two are one 
     *     interval, then the mew interval doesn't need to merge. 
     */ 
    
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        List<Interval> res = new ArrayList<Interval>(); 
        if (intervals == null || intervals.size() == 0) {
            res.add(newInterval); 
            return res; 
        }
        if (newInterval == null) {
            return intervals; 
        }
        
        int i, j; 
        for (i = 0; i < intervals.size(); ++i) {
            if (intervals.get(i).end >= newInterval.start) {
                break; 
            } 
            res.add(intervals.get(i)); 
        }
        
        for (j = i; j < intervals.size(); ++j) {
            if (intervals.get(j).start > newInterval.end) {
                break; 
            }
        }
        
        if (i == j) {
            res.add(newInterval); 
        } else {
            int st = Math.min(intervals.get(i).start, newInterval.start); 
            int ed = Math.max(intervals.get(j - 1).end, newInterval.end); 
            res.add(new Interval(st, ed)); 
        }
        
        for (; j < intervals.size(); ++j) {
            res.add(intervals.get(j)); 
        }
        
        return res; 
    }
}
