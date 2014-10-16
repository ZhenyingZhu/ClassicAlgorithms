package algorithms.datastructure; 

import java.util.*; 
import lib.Interval; 

public class MergeIntervals {
    /* Function: Given a list of intervals, merge intervals if they can and output all new of intervals. 
     * Solution: First sort them by start time. If the end of current interval is small than the next one's, 
     *     this interval can be outputed. Else, they can merge, keep the start but let end be the larger one. 
     */ 
    
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> res = new ArrayList<Interval>(); 
        if (intervals == null || intervals.size() == 0) {
            return res; 
        }
        
        Queue<Interval> heap = new PriorityQueue<Interval>(intervals.size(), IntervalComparator); 
        for (Interval itv : intervals) {
            heap.offer(itv); 
        }
        
        Interval cur = heap.poll(); 
        int st = cur.start, ed = cur.end; 
        while (!heap.isEmpty()) {
            cur = heap.poll(); 
            if (ed < cur.start) {
                res.add(new Interval(st, ed)); 
                st = cur.start; 
                ed = cur.end; 
            } else {
                ed = Math.max(ed, cur.end); 
            }
        }
        
        res.add(new Interval(st, ed)); 
        return res; 
    }
    
    private Comparator<Interval> IntervalComparator = new Comparator<Interval>() {
        public int compare(Interval i1, Interval i2) {
            return i1.start - i2.start; 
        }
    }; 
}
