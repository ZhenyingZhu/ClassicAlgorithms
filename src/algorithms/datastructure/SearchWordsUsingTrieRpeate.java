package algorithms.datastructure; 

import java.util.*; 

public class SearchWordsUsingTrieRpeate {
    /* Function: Search words in a long string using trie tree. 
     * Solution: Create a trie tree with all the substring of the string. Each node
     *     keep and index of where the words that has this char start. Use map to store
     *     the children. 
     */ 
    
    public void search(String S, String[] targets) {
        if (S == null || S.length() == 0 || targets == null || targets.length == 0) {
            return; 
        }
        
        SuffixTree tree = new SuffixTree(S); 
        for (String t : targets) {
            if (t == null || t.length() == 0) {
                continue; 
            }
            
            System.out.println(t + ": " + tree.search(t)); 
        }
    }
    
    /* Test case: 
    public static void main(String[] args) {
        String[] t = {"a", "b", "ab", "f"}; 
        String S = "abcdabeaa"; 
        new Test().search(S, t); 
    }
    */
}

class SuffixTree {
    TrieNode root = new TrieNode(); 
    public SuffixTree(String s) {
        if (s == null || s.length() == 0) {
            return; 
        }
        
        for (int i = 0; i < s.length(); ++i) {
            root.insert(s.substring(i), i); 
        }
    }
    
    public List<Integer> search(String t) {
        return root.search(t); 
    }
}

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<Character, TrieNode>(); 
    List<Integer> indexes = new ArrayList<Integer>(); 
    
    public void insert(String s, int idx) {
        indexes.add(idx); // Where the string contains this char start. 
        if (s.length() == 0) {
            return; 
        }
        
        TrieNode child = null; 
        char nxt = s.charAt(0); 
        if (!children.containsKey(nxt)) {
            child = new TrieNode(); 
            children.put(nxt, child); 
        } else {
            child = children.get(nxt); 
        }
        
        child.insert(s.substring(1), idx); 
    }
    
    public List<Integer> search(String t) {
        if (t.length() == 0) {
            return indexes; // Reach the last char. 
        }
        
        char nxt = t.charAt(0); 
        if (children.containsKey(nxt)) {
            return children.get(nxt).search(t.substring(1)); 
        }
        
        return new ArrayList<Integer>(); 
    }
}
