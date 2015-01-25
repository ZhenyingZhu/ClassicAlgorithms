package algorithms.sortandsearch; 

import java.util.*; 

public class QuickSort {
    /* Function: Sort an array use quick sort. 
     * Solution: Standard quick sort. 
    */
    public void quickSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return; 
        }
        
        quickSortHelper(arr, 0, arr.length - 1); 
    }
    
    private void quickSortHelper(int[] arr, int st, int ed) {
        if (st >= ed) {
            return; 
        }
        
        int md = st + (ed - st) / 2; 
        swap(arr, md, ed); 
        
        int pt = st - 1; 
        for (int i = st; i < ed; ++i) {
            if (arr[i] < arr[ed]) {
                swap(arr, ++pt, i); 
            }
        }
        swap(arr, ++pt, ed); 
        
        quickSortHelper(arr, st, pt - 1); 
        quickSortHelper(arr, pt + 1, ed); 
    }
    
    private void swap(int[] arr, int p1, int p2) {
        int tmp = arr[p1]; 
        arr[p1] = arr[p2]; 
        arr[p2] = tmp; 
    }
}
