package algorithms.rcanddp; 

import java.util.*; 

public class ClimbStairsThreeSteps {
    /*  Function: Each time can climb one, two or three stairs. 
     *  Solution: DP.  
     */
    
    public int countWays(int n) {
        if (n <= 0) {
            return 0; 
        }

        int[] array = new int[n + 2]; 
        array[0] = 0; // You cannot climb to second stair using three steps. 
        array[1] = array[2] = 1; 

        for (int i = 3; i < array.length; ++i) {
            array[i] = array[i - 1] + array[i - 2] + array[i - 3]; 
        }

        return array[n + 1]; 
    }
}
