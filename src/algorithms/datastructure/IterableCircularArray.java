package algorithms.datastructure; 

import java.util.*; 

public class IterableCircularArray {
    /* Function: Implement an circular array that support rotate easily. 
     * Solution: Move head and implement iterable. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        String[] arr = {"aaa", "vvv", "ccc"}; 
        CircularArray<String> carr = new CircularArray<String>(4); 
        for (int i = 0; i < arr.length; ++i) {
            carr.set(i, arr[i]); 
        }
        
        String one = carr.get(0); 
        System.out.println(one instanceof java.lang.String); 
        String two = carr.get(3); 
        System.out.println(one + two); 
        Iterator<String> iter = carr.iterator(); 
        while (iter.hasNext()) {
            System.out.println(iter.next()); 
        }
    }
    */
}

class CircularArray<T> implements Iterable<T> {
    private int head = 0; 
    private T[] items; 
    public CircularArray(int size) {
        items = (T[])new Object[size]; 
    }
    
    public void set(int idx, T item) {
        if (idx < 0 || idx >= items.length) {
            throw new java.lang.IndexOutOfBoundsException("out"); 
        }
        items[convert(idx)] = item; 
    }
    
    public T get(int idx) {
        if (idx < 0 || idx >= items.length) {
            throw new java.lang.IndexOutOfBoundsException("out"); 
        }
        return items[convert(idx)]; // Don't need cast
    }
    
    public void rotate(int offset) {
        head = convert(offset); 
    }
    
    private int convert(int idx) {
        if (idx < 0) { // For offset
            idx += items.length; 
        }
        return (head + idx) % items.length; 
    }
    
    public Iterator<T> iterator() {
        return new CircularArrayIterator<T>(this); 
    }
    
    private class CircularArrayIterator<TI> implements Iterator<TI> {
        private int _cur = -1; 
        private TI[] _items; 
        
        public CircularArrayIterator(CircularArray<TI> array) {
            _items = array.items; 
        }
        
        @Override
        public boolean hasNext() {
            return _cur < _items.length - 1; 
        }
        
        @Override
        public TI next() {
            return (TI)_items[convert(++_cur)]; // Here is TI
        }
        
        @Override
        public void remove() {
            throw new UnsupportedOperationException("not support"); 
        }
    }
}