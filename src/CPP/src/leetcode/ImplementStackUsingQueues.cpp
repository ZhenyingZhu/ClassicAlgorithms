/*
 * [Source] https://leetcode.com/problems/implement-stack-using-queues/
 * [Difficulty]: Easy
 * [Tag]: Stack
 * [Tag]: Design
 */

#include <iostream>
#include <queue>

using namespace std;

// [Solution]: Spend an hour on this... The idea is that every time when we need a pop, move all numbers in queue1 into queue2, except the last one, and pop it. Then move all numbers back. To save sometime on top(), save the result from pop().
class Stack {
public:
    queue<int> q1, q2;
    int top_ = 0;

    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        top_ = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            top_ = q1.front();
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
        /*
        while (!q2.empty()) { // no need, can just swap q1 with q2
            q1.push(q2.front());
            q2.pop();
        }
        */
    }

    // Get the top element.
    int top() {
        return top_;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.size() == 0 && q2.size() == 0;
    }
};

// [Corner Case]:
class Solution {
public:
    void testStack() {
        Stack st;
        st.push(1); st.push(2); st.push(3);
        cout << st.top() << endl;
        st.pop();
        st.push(4); st.push(5);
        cout << st.top() << endl;
        st.pop();
        cout << st.top() << endl;
    }

};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    sol.testStack();

    return 0;
}
