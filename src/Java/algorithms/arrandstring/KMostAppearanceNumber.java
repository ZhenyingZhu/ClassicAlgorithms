package algorithms.arrandstring; 

import java.util.*; 

public class KMostAppearanceNumber {
    /* Function: Find the first k numbers that appear most times in an array. 
     * Solution: Use hashmap to record the elements and sort by the frequency. 
     */ 
    
    // Test Case
    public static void main(String[] args) {
        int[] a = {3, 2, 3, 4, 2, 4, 3, 5}; 
        for (int i = 1; i <= 3; ++i) {
            System.out.println(new Test().findKAppearance(a, i)); 
        }
    }
    
    public List<Integer> findKAppearance(int[] array, int k) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (array == null || array.length == 0 || k <= 0) {
            return res; 
        }
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(); 
        
        for (int num : array) {
            if (map.containsKey(num)) {
                map.put(num, map.get(num) + 1); 
            } else {
                map.put(num, 1); 
            }
        }
        
        List<EleFreq> list = new ArrayList<EleFreq>(); 
        for (int num : map.keySet()) {
            list.add(new EleFreq(num, map.get(num))); 
        }
        Collections.sort(list, EleComparator); 
        
        for (int i = 0; i < k; ++i) {
            res.add(list.get(i).getNum()); 
        }
        return res; 
    }
    
    private class EleFreq {
        int num; 
        int freq; 
        
        public EleFreq(int num, int freq) {
            this.num = num; 
            this.freq = freq; 
        }
        
        public int getNum() {
            return num; 
        }
    }
    
    private Comparator<EleFreq> EleComparator = new Comparator<EleFreq>() {
        public int compare(EleFreq e1, EleFreq e2) {
            return e2.freq - e1.freq; 
        }
    }; 
} 
