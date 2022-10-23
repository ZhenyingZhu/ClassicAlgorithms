/*
 * [Source] https://leetcode.com/problems/implement-queue-using-stacks/
 * [Difficulty]: Easy
 * [Tag]: Stack
 * [Tag]: Design
 */

#include <iostream>
#include <stack>
#include <climits>

using namespace std;

// [Solution]: Two stacks. Push to first stack. When peek or pop, either pop from second stack if it's not empty. Else move all element to second stack.
// [Corner Case]:
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!s2.empty()) {
            s2.pop();
            return;
        }

        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        if (!s1.empty())
            s1.pop();
    }

    // Get the front element.
    int peek(void) {
        if (empty())
            return INT_MAX;

        if (!s2.empty()) {
            return s2.top();
        }

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }

    stack<int> s1, s2;
};

class Solution {
public:
    void test() {
        Queue q;
        q.push(1); q.push(2);
        cout << q.peek() << endl;
        q.pop();
        cout << q.peek() << endl;
        q.push(3);
        cout << q.peek() << endl;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    sol.test();

    return 0;
}
