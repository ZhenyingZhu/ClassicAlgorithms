package algorithms.rcanddp; 

import java.util.*; 

public class SubsetsOfASetBinaryString {
    /*  Function: Return all the subset of a set without duplicates. 
     *  Solution: Create a binary string to show the appearance of elements. 
     */
    
    public List<List<Integer>> getSubsets(List<Integer> set) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (set == null || set.size() == 0) {
            return res; 
        }

        StringBuffer bin = new StringBuffer();  

        List<String> series = new ArrayList<String>(); 
        generateSeries(bin, 0, series, set.size()); 

        for (String cur : series) {
            res.add(convert(cur, set)); 
        }

        return res; 
    }

    private void generateSeries(StringBuffer bin, int st, List<String> series, int size) {
        if (st == size) {
            series.add(bin.toString()); 
            return; 
        }

        bin.append('0'); 
        generateSeries(bin, st + 1, series, size); 
        bin.setCharAt(bin.length() - 1, '1'); 
        generateSeries(bin, st + 1, series, size);
        bin.deleteCharAt(bin.length() - 1); 
    }

    private List<Integer> convert(String bin, List<Integer> set) {
        List<Integer> res = new ArrayList<Integer>(); 
        for (int i = 0; i < bin.length(); ++i) {
            if (bin.charAt(i) == '1') {
                res.add(set.get(i)); 
            }
        }
        return res; 
    }
}
