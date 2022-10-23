/*
 * [Source] https://leetcode.com/problems/min-stack/
 * [Source]: CTCI ch03 02
 * [Difficulty]: Easy
 * [Tag]: Stack
 * [Tag]: Design
 */

#include <iostream>

using namespace std;

// [Solution]: Maintain another stack with current min value. When pop, this stack also pop.
// [Corner Case]:
class Solution {
};

// [Solution]: The second stack only push when smaller or equal to current min value value. When pop an element that is same as min, pop the stack.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/MinStackSimple.java
 */

/* Java solution
class Node{
	Node next;
	Node prev;
	int data=Integer.MAX_VALUE;
	int mini=Integer.MAX_VALUE;
}

class MinStack{
	Node pointer;
	int minimum=Integer.MAX_VALUE;
	int cap=0;
	int position=0;

	public MinStack(int cap){
		this.cap=cap;
		Node head=new Node();
		pointer=head;
	}

	public boolean push(int data){
		if(position>=cap) return false;		
		Node current=new Node();
		current.data=data;
		pointer.next=current;
		current.prev=pointer;
		if(data<minimum) minimum=data;
		current.mini=minimum;
		pointer=current;
		position++;
		return true;
	}
	public int pop(){
		if(position<=0) return Integer.MAX_VALUE;
		int result=pointer.data;
		pointer.prev.next=null;
		pointer=pointer.prev;
		position--;
		return result;
	}
	public int min(){
		if(position<=0) return Integer.MAX_VALUE;
		return pointer.mini;
	}
}

class Question{
	public static void main(String[] args){
		MinStack ms=new MinStack(5);
		ms.push(8);
		ms.push(2);
		ms.push(5);
		ms.push(3);
		ms.push(5);
		System.out.println(ms.push(2));
		System.out.println(ms.pop()+" min="+ms.min());
		System.out.println(ms.pop()+" min="+ms.min());
		System.out.println(ms.pop()+" min="+ms.min());
		System.out.println(ms.pop()+" min="+ms.min());
		System.out.println(ms.pop()+" min="+ms.min());
		System.out.println(ms.pop()+" min="+ms.min());
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
