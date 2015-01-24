package algorithms.aortandsearch; 

import java.util.*; 

public class MergeSort {
    /* Function: Merge Sort to sort and Integer Array. 
     * Solution: Standard merge sort. 
    */
    public void mergeSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return; 
        }
        
        int[] temp = new int[arr.length]; 
        mergeSortHelper(arr, temp, 0, arr.length - 1); 
    }
    
    private void mergeSortHelper(int[] arr, int[] cpy, int st, int ed) {
        if (st >= ed) {
            return; 
        }
        
        int md = st + (ed - st) / 2; 
        mergeSortHelper(arr, cpy, st, md); 
        mergeSortHelper(arr, cpy, md + 1, ed); 
        merge(arr, cpy, st, md, ed); 
    }
    
    private void merge(int[] arr, int[] cpy, int st, int md, int ed) {
        for (int i = st; i <= ed; ++i) {
            cpy[i] = arr[i]; 
        }
        
        int p1 = st, p2 = md + 1, cur = st; 
        while (p1 <= md && p2 <= ed) {
            if (cpy[p1] < cpy[p2]) {
                arr[cur++] = cpy[p1++]; 
            } else {
                arr[cur++] = cpy[p2++]; 
            }
        }
        
        while (p1 <= md) {
            arr[cur++] = cpy[p1++]; 
        }
    }
}
