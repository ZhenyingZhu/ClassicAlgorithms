package algorithms.datastructure; 

import java.util.*; 

class MedianArrayList {
    /* Function: An online arrayList that can get median in O(1).  
     * Solution: Use a maxHeap and a minHeap. If the value<maxHeap.peek, 
     *     it smaller than all the minHeap. Vice visa. 
     */ 

    private int SIZE; 
    private List<Integer> list = new ArrayList<Integer>(); 
    private Queue<Integer> minHeap, maxHeap; 
    
    public MedianArrayList(int size) {
        SIZE = size; 
        minHeap = new PriorityQueue<Integer>(SIZE / 2); 
        maxHeap = new PriorityQueue<Integer>(SIZE - SIZE / 2, MaxComparator); 
    }
    
    public void add(int val) {
        list.add(val); 
        if (maxHeap.size() == 0 || val < maxHeap.peek()) {
            maxHeap.offer(val); 
        } else {
            minHeap.offer(val); 
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll()); 
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll()); 
        }
    }
    
    public int get(int idx) {
        return list.get(idx);
    }
    
    public double median() {
        if (maxHeap.size() == minHeap.size()) {
            return (double)(maxHeap.peek() + minHeap.peek()) / 2; 
        }
        
        return maxHeap.peek(); 
    }
    
    private Comparator<Integer> MaxComparator = new Comparator<Integer>() {
        public int compare(Integer i1, Integer i2) {
            return i2 - i1; 
        }
    }; 
}
