package algorithms.detail; 

import java.util.*; 

public class TextJustification {
    /* Function: Output as many words (with spaces between) as it can in L length. 
     *     Padding spaces evenly between words to reach the L. The last line and 
     *     one-word line should be left justificate. 
     * Solution: Use sum to count the length, if exceed L, let previous words become a line.
     */ 
    
    public List<String> fullJustify(String[] words, int L) {
        List<String> res = new ArrayList<String>(); 
        if (words == null || words.length == 0 || L < 0) {
            return res; 
        }
        
        int sum = 0; 
        List<String> line = new ArrayList<String>(); 
        for (int i = 0; i < words.length; ++i) {
            sum += words[i].length(); 
            if (sum > L) {
                createLine(L, line, res); 
                sum = words[i].length(); 
                line.clear(); 
            }
            line.add(words[i]); 
            ++sum; // Add a space
        }
        
        StringBuffer sb = new StringBuffer(); 
        for (String s : line) {
            sb.append(s); 
            L -= s.length(); 
            if (L > 0) {
                sb.append(" "); 
                --L; 
            }
        }
        for (; L > 0; --L) {
            sb.append(" "); 
        }
        res.add(sb.toString()); 
        
        return res; 
    }
    
    private void createLine(int L, List<String> line, List<String> res) {
        if (line.size() == 0) {
            return; 
        }
        
        int sum = 0; 
        for (String s : line) {
            sum += s.length(); 
        }
        
        int slots = line.size() - 1; 
        int trail = slots == 0 ? (L - sum) : (L - sum) / slots; 
        int add = slots == 0 ? 0 : (L - sum) % slots; 
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = 0; i < line.size(); ++i) {
            sb.append(line.get(i)); 
            if (i != 0 && i == line.size() - 1) {
                continue; // The last one
            }
            
            for (int j = 0; j < trail; ++j) {
                sb.append(" "); 
            }
            if (add > 0) {
                sb.append(" "); 
                --add; 
            }
        }

        res.add(sb.toString()); 
    }
}
