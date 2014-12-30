package algorithms.bitmanipulate; 

import java.util.*; 

public class FindMissingNumberInZeroToN {
    /*  Function: Find the missing number in a list from 0 to N.  
     *  Solution: Just sum them up. 
     */
    
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(0, 1, 2, 4);  
        System.out.println(new Test().findMissing(list));
    }

    public int findMissing(List<Integer> list) {
        int N = list.size(); 
        if (N <= 0) {
            return 0; 
        }

        int std = N * (N + 1) / 2; 
        int sum = 0; 
        for (int num : list) {
            sum += num; 
        }

        return std - sum; 
    }

}
