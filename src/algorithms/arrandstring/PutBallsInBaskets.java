package algorithms.arrandstring; 

import java.util.*; 

public class PutBallsInBaskets {
    /* Function: Find all the solutions to put m balls in n baskets. 
     * Solution: DFS. 
     */ 
    
    public List<List<Integer>> putBallsInBaskets(int m, int n) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (m < n) {
            return res; 
        }
        
        List<Integer> list = new ArrayList<Integer>(); 
        basketHelper(m, n, list, res); 
        return res; 
    }
    
    private void basketHelper(int balls, int remains, List<Integer> list, List<List<Integer>> res) {
        if (balls == 0 && remains == 0) {
            res.add(new ArrayList<Integer>(list)); 
            return; 
        }
        if (balls < remains || remains <= 0) {
            return; 
        }
        
        for (int i = 1; i <= balls - remains + 1; ++i) {
            list.add(i); 
            basketHelper(balls - i, remains - 1, list, res); 
            list.remove(list.size() - 1); 
        }
    }
    
    public static void main(String[] args) {
        List<List<Integer>> ans = new Test().putBallsInBaskets(5, 4); 
        System.out.println(ans);
    }
} 