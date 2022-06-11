package algorithms.sortandsearch; 

import java.util.*; 

public class SortAnagrams {
    /* Function: Sort the string array such that the anagrams are show at together. 
     * Solution: The most fast algorithm is using bucket sorting. But here implementing
     *     a comparator is the key step. 
     */ 
    
    public void sort(String[] arr) {
        if (arr == null || arr.length == 0) {
            return; 
        }
        
        Comparator<String> StrComparator = new Comparator<String>() { 
            public String anaSort(String s) {
                char[] tmp = s.toCharArray(); 
                Arrays.sort(tmp); 
                return new String(tmp); 
            }
            
            public int compare(String s1, String s2) {
                return anaSort(s1).compareTo(anaSort(s2)); 
            }
        }; 
        
        Arrays.sort(arr, StrComparator); 
    }
}