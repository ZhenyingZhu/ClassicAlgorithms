package algorithms; 

import java.util.*; 

public class LRUCache {
    /* Function: Implement a Last-Recently-Used Cache. 
     * Solution: Use linked list to recode key and value and
     *     HashMap to record position. When get or set, move
     *     that node to the end. 
     */ 
    Node dummy = new Node(0, 0), tail = dummy; 
    int cap, size = 0; 
    Map<Integer, Node> map = new HashMap<Integer, Node>(); 
    
    private class Node {
        int key, val;
        Node next, prev; 
        public Node(int k, int x) {
            key = k; 
            val = x; 
        }
    }
    
    public LRUCache(int capacity) {
        cap = capacity; 
    }
    
    public int get(int key) {
        if (!map.containsKey(key)) {
            return -1; 
        }
        
        Node node = map.get(key); 
        moveToEnd(node); 
        return node.val; 
    }
    
    public void set(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key); 
            moveToEnd(node); 
            node.val = value; 
            return; 
        }
        
        Node add = new Node(key, value); 
        map.put(key, add); 
        addToEnd(add); 
        if (size < cap) {
            ++size; 
            return; 
        }
        
        deleteHead(); 
    }
    
    private void moveToEnd(Node node) {
        if (tail == node) {
            return; 
        }
        
        node.prev.next = node.next; 
        node.next.prev = node.prev; 
        addToEnd(node); 
    }
    
    private void addToEnd(Node add) {
        tail.next = add; 
        add.prev = tail; 
        tail = add; 
        add.next = null; 
    }
    
    private void deleteHead() {
        if (dummy.next == tail) {
            return; // No head
        }
        
        Node head = dummy.next; 
        map.remove(head.key); 
        dummy.next = head.next; 
        head.next.prev = dummy; 
    }
}
