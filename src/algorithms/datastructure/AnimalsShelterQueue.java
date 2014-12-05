package algorithms.datastructure; 

import java.util.*; 

public class AnimalsShelterQueue {
    /* Function: Create a animal shelter that FIFO. Can dequeue dog or cat. 
     * Solution: Use linked list as queue. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        AnimalQueue aq = new AnimalQueue(); 
        aq.enqueue(new Dog("d1")); 
        aq.enqueue(new Dog("d2")); 
        aq.enqueue(new Cat("c1")); 
        aq.enqueue(new Dog("d3")); 
        
        System.out.println(aq.dequeueAny().name); 
        System.out.println(aq.dequeueCat().name); 
        System.out.println(aq.dequeueCat()); 
    }
    */
} 

class AnimalQueue {
    LinkedList<Dog> dogs = new LinkedList<Dog>(); 
    LinkedList<Cat> cats = new LinkedList<Cat>(); 
    private int order = 0; 
    
    public void enqueue(Animal a) {
        a.setOrder(order++); 
        if (a instanceof Dog) {
            dogs.addLast((Dog)a); 
        } else if (a instanceof Cat) {
            cats.addLast((Cat)a); 
        }
    }
    
    public Animal dequeueAny() {
        if (dogs.size() == 0) {
            return dequeueCat(); // Reuse
        } else if (cats.size() == 0) {
            return dequeueDog(); 
        }
        
        Dog d = dogs.peek(); 
        Cat c = cats.peek(); 
        if (d.isOlderThan(c)) {
            return dequeueDog(); 
        } else {
            return dequeueCat(); 
        }
    }
    
    public Dog dequeueDog() {
        if (dogs.size() == 0) {
            return null; 
        }
        
        return dogs.poll(); 
    }
    
    public Cat dequeueCat() {
        if (cats.size() == 0) {
            return null; 
        }
        
        return cats.poll(); 
    }
}

abstract class Animal {
    private int order; 
    protected String name; 
    public Animal(String name) { // Not use order because it is hidden property
        this.name = name; 
    }
    
    public void setOrder(int ord) {
        order = ord; 
    }
    
    public int getOrder() {
        return order; 
    }
    
    public boolean isOlderThan(Animal ani) { // Start from 0
        return this.order < ani.getOrder(); 
    }
}

class Dog extends Animal {
    public Dog(String s) {
        super(s); 
    }
}

class Cat extends Animal {
    public Cat(String s) {
        super(s); 
    }
}