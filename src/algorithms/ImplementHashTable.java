//package algorithms; 

import java.util.*; 

public class ImplementHashTable {
    /* Function: Use the Apache HashCode to implement hash table. 
     * Solution: Magic number 33. 
     * Test Case: 

    public static void main(String[] args) {
        MyHashTable hash = new MyHashTable(10); 
        System.out.println(hash.containsKey("apple")); 
        hash.put("apple", "sweet"); 
        System.out.println(hash.containsKey("apple")); 
        System.out.println(hash.get("apple")); 
        hash.put("apple", "sweet but sour"); 
        System.out.println(hash.get("apple")); 
        hash.put(null, "apple"); 
    }
    
     */ 
}

class MyHashTable {
    private int HASHTABLE_SIZE; 
    int size; 
    private List<List<String>> keys = new ArrayList<List<String>>(); 
    private List<List<String>> values = new ArrayList<List<String>>(); 
    
    private class KeyException extends Exception {
        public KeyException() {
            System.err.println("Key cannot be null"); 
        }
    }
    
    public MyHashTable(int cap) {
        this.HASHTABLE_SIZE = cap; 
        size = 0; 
        for (int i = 0; i < cap; ++i) {
            keys.add(new ArrayList<String>()); 
            values.add(new ArrayList<String>()); 
        }
    }
    
    public boolean containsKey(String key) {
        try {
            int pos = hashfunc(key); 
            int idx = getIdx(pos, key); 
            if (idx == -1) {
                return false; 
            }
            return true; 
        } catch(KeyException ke) {
            return false; 
        }
    }
    
    public String get(String key) {
        try {
            int pos = hashfunc(key); 
            int idx = getIdx(pos, key); 
            if (idx == -1) {
                return null; 
            }
            return values.get(pos).get(idx); 
        } catch(KeyException ke) {
            return null; 
        }
    }
    
    public void put(String key, String value) {
        try {
            int pos = hashfunc(key); 
            int idx = getIdx(pos, key); 
            if (idx == -1) {
                keys.get(pos).add(key); 
                values.get(pos).add(value); 
                ++size; 
            } else {
                values.get(pos).set(idx, value); 
            }
        } catch(KeyException ke) {
            return; 
        }
    }
    
    private int hashfunc(String key) throws KeyException {
        if (key == null) {
            throw new KeyException(); 
        }
        
        int sum = 0; 
        for (int i = 0; i < key.length(); ++i) {
            sum = sum * 33 + key.charAt(i); 
            sum = sum % HASHTABLE_SIZE; 
        }
        
        return sum; 
    }
    
    private int getIdx(int pos, String key) {
        return keys.get(pos).indexOf(key); 
    }
}
