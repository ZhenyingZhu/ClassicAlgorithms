package algorithms.sortandsearch; 

import java.util.*; 

public class MagicIndexOfSortedArrayWithDup {
    /* Function: Find a magic index of an array such that A[i]=i. 
     * Solution: If there is no duplication, A[md]<md means the index must in the right. 
     *     While if there are duplications, should search from st to A[md]. But A[md+1] 
     *     to md  still isn't possible to become the result. Then it must in right. 
     */ 
    
    public int magic(int[] arr) {
        if (arr == null || arr.length == 0) {
            return -1; 
        }
        
        int st = 0, ed = arr.length - 1, md, pt = -1; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (arr[md] == md) {
                return md; 
            }
            
            if (arr[md] < md) {
                for (pt = st; pt <= arr[md]; ++pt) {
                    if (arr[pt] == pt) {
                        return pt; 
                    }
                }
                
                st = md; 
            } else {
                for (pt = arr[md]; pt <= ed; ++pt) {
                    if (arr[pt] == pt) {
                        return pt; 
                    }
                }
                
                ed = md; 
            }
        }
        
        if (arr[st] == st) {
            return st; 
        }
        if (arr[ed] == ed) {
            return ed; 
        }
        return -1; 
    }
    
    /*Test Case
    public static void main(String[] args) {
        int[] arr = new int[10]; 
        for (int i = 0; i < arr.length; ++i) {
            arr[i] = (int)(Math.random() * 11); 
        }
        
        Arrays.sort(arr); 
        for (int i = 0; i < arr.length; ++i) {
            System.out.print(arr[i] + " "); 
        }
        System.out.println(); 
        
        int ans = new Test().magic(arr); 
        System.out.print(ans + " "); 
    }
    */
}
