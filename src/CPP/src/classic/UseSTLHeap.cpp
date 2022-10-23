#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct Integer {
    int num;
};

struct Compare {
    bool operator()(const Integer &int1, const Integer &int2) {
        // a greater function makes the heap put the smallest value at top
        return int1.num > int2.num;
    }
};

int main() {
    vector<int> input = {3, 5, 2, 6, 8, 1, 4, 7, 9, 0};

    // Accept a Compare class, like greater<int>
    //priority_queue<Integer, vector<Integer>, Compare> pq;
    // Use Lambda to init a function class
    priority_queue< Integer, vector<Integer>, function<bool(Integer, Integer)> > pq
        ( [](const Integer &int1, const Integer &int2) -> bool {return int1.num > int2.num;} );

    for (int & num : input)
        pq.push( {num} );
    
    while (!pq.empty()) {
        cout << pq.top().num << " ";
        pq.pop();
    }
    cout << endl;
}
