/*
 * [Source] https://leetcode.com/problems/lru-cache/
 * [Difficulty]: Hard
 * [Tag]: Design
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// [Solution]: Use a doubly linked list to track key-value pair, and a hash map to map key to node. Use doubly linked list so that delete and move nodes are easy. Keep key in the node so that when delete node, can easily delete it from hash map
// [Corner Case]:
class LRUCache{
public:
    LRUCache(int capacity): capacity_(capacity) {
        size_ = 0;
        head = new DoublyLinkedList(-1, 0); // valid key always positive
        tail = head;
    }

    int get(int key) {
        unordered_map<int, DoublyLinkedList*>::iterator it = keyNodeMap_.find(key);
        if (it == keyNodeMap_.end())
            return -1;

        DoublyLinkedList *node = it->second;
        moveNodeToEnd(node);

        return node->value;
    }

    void set(int key, int value) {
        auto it = keyNodeMap_.find(key);
        if (it == keyNodeMap_.end()) {
            DoublyLinkedList *node = new DoublyLinkedList(key, value);
            keyNodeMap_[key] = node;
            tail->nxt = node;
            node->pre = tail;
            tail = node;
            ++size_;

            if (size_ > capacity_)
                deleteLeastUsedNode();
        } else {
            DoublyLinkedList *node = it->second;
            node->value = value;
            moveNodeToEnd(node);
        }
    }

private:
    struct DoublyLinkedList {
        DoublyLinkedList(int k, int v): key(k), value(v), pre(NULL), nxt(NULL) {}
        int key;
        int value;
        DoublyLinkedList *pre, *nxt;
    };

    void moveNodeToEnd(DoublyLinkedList *node) {
        if (node == tail)
            return;

        node->pre->nxt = node->nxt;
        node->nxt->pre = node->pre;
        node->pre = tail;
        tail->nxt = node;
        node->nxt = NULL;
        tail = node;
    }

    void deleteLeastUsedNode() {
        if (head->nxt == NULL)
            return;
        int removeKey = head->nxt->key;
        keyNodeMap_.erase(removeKey);

        DoublyLinkedList *removeNode = head->nxt;
        head->nxt = head->nxt->nxt;
        if (head->nxt != NULL) // if cap = 0
            head->nxt->pre = head;

        delete removeNode;
        removeNode = NULL;
        --size_;
    }

// helper
void printNodes() {
cout << "Nodes ";
DoublyLinkedList *t = head;
while (t != NULL) {
    cout << t->value << "->";
    t = t->nxt;
}
cout << endl;
cout << "tail " << tail->value << endl;
}

private:
    int capacity_;
    int size_;
    DoublyLinkedList *head;
    DoublyLinkedList *tail;
    unordered_map<int, DoublyLinkedList*> keyNodeMap_;
};

class Solution {
public:
    void testLRUCache() {
        LRUCache c(3);

        cout << c.get(0) << endl;
        c.set(1,1); c.set(2,2); c.set(3,3);
        cout << c.get(1) << endl; cout << c.get(2) << endl; cout << c.get(3) << endl; cout << c.get(0) << endl;
        c.set(4,4);
        cout << c.get(1) << endl; cout << c.get(2) << endl; cout << c.get(3) << endl; cout << c.get(4) << endl;
        c.set(2,5);
        cout << c.get(1) << endl; cout << c.get(2) << endl; cout << c.get(3) << endl; cout << c.get(4) << endl;
        c.set(6,6);
        cout << c.get(2) << endl; cout << c.get(3) << endl; cout << c.get(4) << endl; cout << c.get(5) << endl; cout << c.get(6) << endl;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/LRUCache.java
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/datastructure/LRUCacheClear.java
 */

/* Java solution
public class LRUCache {
	HashMap<Integer, ListNode> map=new HashMap<Integer, ListNode>(); // key and node in list
	ListNode head; // Head is a dummy
	ListNode tail; // The recently visited element
	int capacity;
	int volume=0;
	
    public LRUCache(int capacity) {
		this.capacity=capacity;
		head=new ListNode(0, 0);
		tail=head;
	}
    
    public int get(int key) {
		if(!map.containsKey(key)) return -1;
		ListNode result=map.get(key);
		// Move result to last. 
		if(result.next!=null){
    	    result.prev.next=result.next;
		    result.next.prev=result.prev;
		    tail.next=result;
		    result.prev=tail;
		    tail=result;
			tail.next=null; // Break the next of tail
		}// else result is the tail. 
		return result.val;
	}
    
    public void set(int key, int value) {
		if(!map.containsKey(key)){
			// Insert the new node to the end
			ListNode newNode=new ListNode(key, value);
			tail.next=newNode;
			newNode.prev=tail;
			tail=newNode;
			map.put(key, newNode);
			// If out bound, delete head. 
			if(volume>=capacity){
				head=head.next;
				int leastKey=head.key;
				head.prev=null;
				map.remove(leastKey);
			}else volume++;
		}else{ 
		    // Set the value. 
			ListNode visitNode=map.get(key);
			visitNode.val=value; 
			// Move this node to the end; 
			if(visitNode.next!=null){
			    visitNode.prev.next=visitNode.next;
			    visitNode.next.prev=visitNode.prev;
			    tail.next=visitNode;
			    visitNode.prev=tail;
			    tail=visitNode;
				tail.next=null;
			}
		}
	}
}

class ListNode{
	int key;
	int val;
	ListNode prev;
	ListNode next;
	public ListNode(int key, int val){
		this.key=key;
		this.val=val;
	}
}
 */

int main() {
    Solution sol;

    sol.testLRUCache();

    return 0;
}
