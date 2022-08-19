package algorithms.rcanddp; 

import java.util.*; 

public class MostPeopleCircusTower {
    /* Function: Let only not shorter or not taller person stand on the above, 
     *     find a way to make the circus tower contains most people. 
     * Solution: It becomes longest increasing sequence when sort the array first. 
     *     Notice when need to construct the result, memo cache is better than matrix. 
     */ 
    
    public List<Htwt> getIncreasingSequence(List<Htwt> arr) {
        List<Htwt> res = new ArrayList<Htwt>(); 
        if (arr == null || arr.size() == 0) {
            return res; 
        }
        
        arr.add(new Htwt(0, 0)); 
        Collections.sort(arr); 
        
        Map<Integer, List<Htwt>> map = new HashMap<Integer, List<Htwt>>(); 
        seqHelper(arr, 0, map); 
        return map.get(0); 
    }
    
    private int seqHelper(List<Htwt> arr, int st, Map<Integer, List<Htwt>> map) {
        if (map.containsKey(st)) {
            return map.get(st).size(); 
        }
        
        int max = 0, idx = -1; 
        Htwt key = arr.get(st); 
        for (int i = st + 1; i < arr.size(); ++i) {
            if (arr.get(i).w < key.w) {
                continue; 
            }
            
            if (max < seqHelper(arr, i, map)) {
                max = seqHelper(arr, i , map); 
                idx = i; 
            }
        }
        
        List<Htwt> res = new ArrayList<Htwt>(); 
        if (st != 0) {
            res.add(key); 
        }
        if (idx != -1) {
            res.addAll(map.get(idx)); 
        }
        map.put(st, res); 
        
        return max + 1; 
    }
    
    /* Test Case
    public static void main(String[] args) {
        List<Htwt> arr = new ArrayList<Htwt>(); 
        arr.add(new Htwt(5, 12)); 
        arr.add(new Htwt(4, 11)); 
        arr.add(new Htwt(3, 10)); 
        arr.add(new Htwt(2, 14)); 
        arr.add(new Htwt(1, 13)); 
        List<Htwt> ans = new Test().getIncreasingSequence(arr); 
        System.out.print(ans + " "); 
        System.out.println(); 
    }
    */
}

class Htwt implements Comparable<Htwt> {
    int h, w; 
    public Htwt(int h, int w) {
        this.h = h; 
        this.w = w; 
    }
    
    public int compareTo(Htwt htwt) {
        return this.h - htwt.h; 
    }
    
    public String toString() {
        return "(" + w + ", " + h + ")"; 
    }
}