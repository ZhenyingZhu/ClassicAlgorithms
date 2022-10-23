#include <iostream>
#include <queue>

using namespace std; 

namespace cppprimer {

int queueOperations()
{
    /* Source: Chapter 9.7.2
     * Description: See how priority queue works.
     * Also the default descriptor is extern so
     * no need to declare as extern int queueOperations()
     */
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}

}

