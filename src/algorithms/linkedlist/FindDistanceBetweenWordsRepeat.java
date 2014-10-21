package algorithms.linkedlist; 

import java.util.*; 

public class FindDistanceBetweenWordsRepeat {
    /* Function: Find the shortest distance of two words in large amount of words. 
     * Solution: If don't need to call the function repeatly, just keep the pointers
     *     on the last appearence of two words, and update min if necessary. If need
     *     call many times, use linked lists to record the positions. Then merge sort
     *     two lists, and find the min interval between two lists. 
     */ 
    
    String[] words; 
    Map<String, List<Integer>> map = new HashMap<String, List<Integer>>(); 
    public FindDistanceBetweenWordsRepeat(String[] words) {
        this.words = words; 
        for (int i = 0; i < words.length; ++i) {
            String word = words[i]; 
            if (!map.containsKey(word)) {
                map.put(word, new ArrayList<Integer>()); 
            }
            map.get(word).add(i); 
        }
    }
    
    public int shortest(String word1, String word2) {
        if (!map.containsKey(word1) || !map.containsKey(word2)) {
            return Integer.MAX_VALUE; 
        }
        
        int min = Integer.MAX_VALUE; 
        List<Integer> l1 = map.get(word1), l2 = map.get(word2); 
        int pt1 = 0, pt2 = 0; 
        int from = 2; 
        int pre = l1.get(0) - 1 - Integer.MAX_VALUE; // Let the first case become inf
        while (pt1 < l1.size() && pt2 < l2.size()) {
            int a = l1.get(pt1), b = l2.get(pt2); 
            if (a < b) {
                if (from == 2) {
                    min = Math.min(min, a - pre - 1); 
                }
                from = 1; 
                pre = a; 
                ++pt1; 
            } else {
                if (from == 1) {
                    min = Math.min(min, b - pre - 1); 
                }
                from = 2; 
                pre = b; 
                ++pt2; 
            }
        }
        
        if (pt1 == l1.size()) {
            min = Math.min(min, l2.get(pt2) - pre - 1); 
        } else {
            min = Math.min(min, l1.get(pt1) - pre - 1); 
        }
        
        return min; 
    }
    
    /* Test case
    public static void main(String[] args) {
        String[] words = {"apple", "ZZZ", "orange", "banana", "orange"}; 
        FindDistanceBetweenWordsRepeat ins = FindDistanceBetweenWordsRepeat Test(words); 
        int ans = ins.shortest("apple", "banana"); 
        System.out.print(ans + " "); 
        System.out.println(); 
    }
    */
}
