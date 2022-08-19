package algorithms.datastructure; 

import java.util.*; 

public class LRUCacheClear {
    /* Function: Implement a LRU cache. 
     * Solution: Seperate every methods. 
     */ 
    
    // Test Case
    public static void main(String[] args) {
        LRUCache cache = new LRUCache(1); 
        cache.set(2,1); 
        System.out.println(cache.get(2)); 
        cache.set(3,2); 
        System.out.println(cache.get(2)); 
        System.out.println(cache.get(3)); 
    }
} 

class LRUCache {
    private class Node {
        Node prev, next; 
        int key; 
        int value; 
        
        Node(int key, int value) {
            this.key = key; 
            this.value = value; 
        }
    }
    
    Map<Integer, Node> map; 
    Node dummy = new Node(-1, -1);
    Node tail = dummy; 
    int capacity; 
    int size = 0; 
    
    public LRUCache(int capacity) {
        if (capacity < 1) {
            capacity = 1; 
        }
        this.capacity = capacity; 
        
        map = new HashMap<Integer, Node>(); 
    }
    
    public int get(int key) {
        Node node = touch(key); 
        if (node != null) {
            return node.value; 
        }
        
        return -1; 
    }
    
    public void set(int key, int value) {
        Node node = touch(key); 
        if (node != null) {
            node.value = value; 
            return; 
        }
        
        addNode(key, value); 
        if (size > capacity) {
            deleteHead(); 
        }
    }
    
    private void addNode(int key, int value) {
        Node node = new Node(key, value); 
        map.put(key, node); 
        
        tail.next = node; 
        node.prev = tail; 
        tail = node; 
        
        size++; 
    }
    
    private void deleteHead() {
        if (dummy == tail) {
            return; 
        }
        
        Node head = dummy.next; 
        head.prev = null; 
        dummy = head; 
        
        map.remove(head.key); 
        size--; 
    }
    
    private Node touch(int key) {
        if (map.containsKey(key)) {
            Node node = map.get(key); 
            moveToEnd(node); 
            
            return node; 
        }
        
        return null; 
    }
    
    private void moveToEnd(Node node) {
        if (node == tail) {
            return;
        }
        
        node.prev.next = node.next; 
        node.next.prev = node.prev; 
        
        tail.next = node; 
        node.prev = tail; 
        node.next = null; 
        
        tail = node; 
    }
}