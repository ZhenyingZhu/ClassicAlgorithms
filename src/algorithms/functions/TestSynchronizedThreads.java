package algorithms.functions; 

import java.util.*; 

public class TestSynchronizedThreads {
    /* Function: Use two ways to create threads and test synchronized. 
     * Solution: Print some strings and check. 
     */ 
    
    public static void main(String[] args) {
        MyClass first = new MyClass("first"); 
        Thread thread1 = new Thread(first); 
        Thread thread2 = new Thread(new MyClass("second")); // Can run together with first. 
        Thread thread3 = new Thread(first); // Cannot run together because synchronized. 
        thread1.start(); 
        thread2.start(); 
        thread3.start(); 
        
        MyThread thread4 = new MyThread("1"); 
        MyThread thread5 = new MyThread("2"); 
        thread4.start(); 
        thread5.start(); 
    }
}

class MyClass implements Runnable { // Better way, can implement more interface
    int count = 0; 
    String name; 
    public MyClass(String n) {
        name = n; 
    }
    
    public synchronized void run() {
        try {
            while (count < 5) {
                System.out.println(name + " " + count); 
                Thread.sleep(3000); 
                ++count; 
            }
            return; // Even return here, finally will run. 
        } catch (InterruptedException exc) {
            exc.printStackTrace(); 
        } finally {
            System.out.println("Thread end"); 
        }
    }
}

class MyThread extends Thread { // Extend too many unnecessary properties
    String name; 
    public MyThread(String n) {
        name = n; 
    }
    public void run() {
        if (name.equals("1")) {
            MyObject.foo(name); 
        } else {
            MyObject.bar(name); 
        }
    }
}

class MyObject {
    public static synchronized void foo(String name) { // Cannot run with bar because the class is syncronized. 
        try {
            System.out.println("foo " + name + " start. "); 
            Thread.sleep(3000); 
            System.out.println("foo " + name + " end. "); 
        } catch (InterruptedException exc) {
            exc.printStackTrace(); 
        }
    }
    
    public static synchronized void bar(String name) {
        try {
            System.out.println("bar " + name + " start. "); 
            Thread.sleep(3000); 
            System.out.println("bar " + name + " end. "); 
        } catch (InterruptedException exc){
            exc.printStackTrace(); 
        }
    }
}