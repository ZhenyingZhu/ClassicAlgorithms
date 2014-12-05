package algorithms.sortandsearch; 

import java.util.*; 

public class SearchInSortedNodupArrayWithEmptyCell {
    /* Function: The string array is sorted without duplications, but has some empty strings 
     *     between them. 
     * Solution: First consider if search for empty string. Then notice when find mid is empty, 
     *     cannot just use the nearlest unempty point as mid. Like a,b,,,,c,d will cause dead cycle. 
     */ 
    
    public int search(String[] strings, String target) {
        if (strings == null || strings.length == 0 || target == null) {
            return -1; 
        }
        if (target.length() == 0) {
            return searchEmpty(strings); 
        }
        
        int st = 0, ed = strings.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (strings[md].equals("")) {
                int i; 
                for (i = md + 1; i <= ed && strings[i].equals(""); ++i) {}; 
                if (i <= ed && strings[i].compareTo(target) <= 0) {
                    st = i; 
                    continue; 
                }
                
                for (i = md - 1; i >= st && strings[i].equals(""); --i) {}
                if (i >= st && strings[i].compareTo(target) >= 0) {
                    ed = i; 
                    continue; 
                }
                
                return -1; 
            }
            
            if (strings[md].equals(target)) {
                return md; 
            } else if (strings[md].compareTo(target) < 0) {
                st = md; 
            } else {
                ed = md; 
            }
        }
        
        if (strings[st].equals(target)) {
            return st; 
        }
        if (strings[ed].equals(target)) {
            return ed; 
        }
        return -1; 
    }
    
    private int searchEmpty(String[] strings) {
        for (int i = 0; i < strings.length; ++i) {
            if (strings[i].equals("")) {
                return i; 
            }
        }
        return -1; 
    }
    
    /* Test Case
    public static void main(String[] args) {
        String[] arr = {"a", "", "b", "", "", "", "c", "", "d"}; 
        int ans = new Test().search(arr, "b"); 
        System.out.print(ans + " "); 
        System.out.println(); 
    }
    */
}