package algorithms.functions; 

import java.util.*; 
import java.util.concurrent.locks.*; 

public class TestLock {
    /* Function: Test resource lock using ATM example. 
     * Solution: First store the balance variable to a tmp. If it is locked, 
     *     this operation cannot be done. 
     */ 
    
    public static void main(String[] args) {
        LockATM atm = new LockATM(1000); 
        Thread thread1 = new Thread(new ATMOperation(atm, "deposit")); 
        Thread thread2 = new Thread(new ATMOperation(atm, "withdraw")); 
        thread1.start(); 
        thread2.start(); 
        
        try {
            Thread.sleep(5000); 
            System.out.println("finally " + atm.balance); 
        } catch (InterruptedException exc) {
        }
        
    }
}

class ATMOperation implements Runnable {
    LockATM atm; 
    String operation; 
    public ATMOperation(LockATM atm, String op) {
        this.atm = atm; 
        operation = op; 
    }
    
    public void run() {
        if (operation.equals("deposit")) {
            atm.deposit(100); 
        } else {
            atm.withdraw(100); // Without lock, this operation doesn't work. 
        }
    }
}

class LockATM {
    int balance; 
    Lock lock; 
    public LockATM(int value) {
        balance = value; 
        lock = new ReentrantLock(); 
    }
    
    public void deposit(int amount) {
        lock.lock(); 
        int tmp = balance; 
        try {
            Thread.sleep(1000); 
            tmp += amount; 
            Thread.sleep(1000); 
        } catch (InterruptedException exc) {
        }
        balance = tmp; 
        lock.unlock(); 
        System.out.println("deposit " + balance); 
    }
    
    public void withdraw(int amount) {
        lock.lock(); 
        int tmp = balance; 
        try {
            Thread.sleep(500); 
            tmp -= amount; 
            Thread.sleep(500); 
        } catch (InterruptedException exc) {
        }
        balance = tmp; 
        lock.unlock(); 
        System.out.println("withdraw " + balance); 
    }
}