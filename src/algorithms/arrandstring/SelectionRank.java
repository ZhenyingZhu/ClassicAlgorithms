package algorithms.arrandstring; 

import java.util.*; 

public class SelectionRank {
    /* Function: Select an amount of smallest numbers from a large input in linear time.  
     *     The input can be fit in the memory. 
     * Solution: Can sort O(nlogn), can use heap O(nlogm). But selection rank use O(mn). 
     */ 
    
    public void selectRank(int[] arr, int amt) {
        if (arr == null || arr.length < amt) {
            return; 
        }
        
        for (int i = 1; i <= amt; ++i) {
            System.out.println(rank(arr, 0, arr.length - 1, i)); 
        }
    }
    
    public int rank(int[] arr, int left, int right, int rank) {
        int pivot = arr[left + (int)(Math.random() * (right - left + 1))]; 
        int leftEnd = partition(arr, left, right, pivot); 
        int leftSize = leftEnd - left + 1; 
        if (leftSize == rank) {
            return max(arr, left, leftEnd); 
        } else if (leftSize > rank) {
            return rank(arr, left, leftEnd, rank); 
        } else {
            return rank(arr, leftEnd + 1, right, rank - leftSize); 
        }
    }
    
    public int partition(int[] arr, int left, int right, int pivot) {
        while (true) {
            while (left <= right && arr[left] <= pivot) {
                ++left; 
            }
            while (left <= right && arr[right] > pivot) {
                --right; 
            }
            if (left > right) {
                return left - 1; 
            }
            int tmp = arr[left]; 
            arr[left] = arr[right]; 
            arr[right] = tmp; 
        }
    }
    
    private int max(int[] arr, int st, int ed) {
        int res = Integer.MIN_VALUE; 
        for (int i = st; i <= ed; ++i) {
            res = Math.max(res, arr[i]); 
        }
        return res; 
    }
}
