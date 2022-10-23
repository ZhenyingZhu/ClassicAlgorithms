/*
 * [Source] https://leetcode.com/problems/copy-list-with-random-pointer/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Linked List
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// [Solution]: Do it in two or three pass. Use hash map to record pairs. Not coupling random pointers with next pointers
// [Corner Case]:
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;

        unordered_map<RandomListNode*, RandomListNode*> oriCpyMap;

        RandomListNode *headCpy = new RandomListNode(head->label);
        oriCpyMap[head] = headCpy;

        RandomListNode *run = head->next, *pre = headCpy;

        while (run != NULL) {
            RandomListNode *cpy = new RandomListNode(run->label);
            oriCpyMap[run] = cpy;
            pre->next = cpy;

            pre = pre->next;
            run = run->next;
        }

        run = head;
        while (run != NULL) {
            RandomListNode *cpyPtr = oriCpyMap[run];
            if (run->random != NULL) {
                cpyPtr->random = oriCpyMap[run->random];
            }
            run = run->next;
        }

        return headCpy;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/CopyListWithRandomPointer.java
 */

/* Java solution
public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
		if(head==null) return null;
		RandomListNode current=head;
		while(current!=null){
			RandomListNode copy=new RandomListNode(current.label);
			copy.next=current.next; // Cross link for reconstructation
			current.next=copy; 
			current=copy.next;
		}
		current=head;
		RandomListNode copy=head.next;
		while(current!=null){
			if(current.random!=null){
				copy.random=current.random.next;
			}
			current=copy.next;
			if(current==null) break;
			copy=current.next;
		}
		// reconstruction
		current=head;
		RandomListNode copHead=head.next;
		copy=copHead;
		while(current!=null){
			RandomListNode curNext=copy.next;
			RandomListNode copNext=curNext==null?null:curNext.next;
			current.next=curNext;
			copy.next=copNext;
			current=current.next;
			copy=copy.next;
		}
		return copHead;
    }
}
 */

int main() {
    Solution sol;

    RandomListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2; n2.next = &n3; n3.next = &n4;
    n1.random = &n3; n2.random = &n1; n4.random = &n4;

    RandomListNode *cpy = sol.copyRandomList(&n1);
    while (cpy != NULL) {
        cout << cpy->label << ", random:";
        if (cpy->random == NULL) {
            cout << "NULL";
        } else {
            cout << cpy->random->label;
        }
        cout << endl;
        cpy = cpy->next;
    }

    return 0;
}
