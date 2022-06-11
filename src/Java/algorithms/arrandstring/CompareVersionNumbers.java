package algorithms.arrandstring; 

import java.util.*; 

public class CompareVersionNumbers {
    /* Function: Compare two version numbers. 
     * Solution: The version is split by ".", the length may not same. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        String v1 = "1", v2 = "0"; 
        System.out.println(new Test().compareVersion(v1, v2)); 
    }
    */
    
    public int compareVersion(String version1, String version2) {
        if (!valid(version1) || !valid(version2)) {
            return 0; 
        }
        
        VersionType v1 = new VersionType(version1); 
        VersionType v2 = new VersionType(version2); 
        
        int size = Math.max(v1.releases.size(), v2.releases.size()); 
        for (int i = 0; i < size; i++) {
            int cur = compare(v1, v2, i); 
            if (cur != 0) {
                return cur; 
            } 
        }
        
        return 0; 
    }
    
    private boolean valid(String v) {
        if (v == null || v.length() == 0) {
            return false; 
        }

        return true; 
    }
    
    private int compare(VersionType v1, VersionType v2, int idx) {
        int r1 = v1.releases.size() <= idx ? 0 : v1.releases.get(idx); 
        int r2 = v2.releases.size() <= idx ? 0 : v2.releases.get(idx); 
        if (r1 > r2) {
            return 1; 
        } else if (r1 < r2) {
            return -1; 
        } else {
            return 0; 
        }
    }
    
    private class VersionType {
        List<Integer> releases = new ArrayList<Integer>(); 

        VersionType(String v) {
            String[] tmp = v.split("\\."); 
            for (String rls : tmp) {
                releases.add(Integer.parseInt(rls)); 
            }
        }
    }
} 
