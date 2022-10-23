#include <iostream>
#include <list>
#include <map>
#include <climits>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-212481-1-1.html

class MaxStack {
public:
    MaxStack() {
    }

    bool empty() {
        return store.empty();
    }

    void push(int x) {
        store.push_back(x);
        list<int>::iterator it = --store.end();
        valItMap[x].push_back(it);
    }

    int pop() {
        if (store.empty())
            return INT_MAX;

        list<int>::iterator it = --store.end();
        int val = *it;

        valItMap[val].pop_back();
        if (valItMap[val].empty())
            valItMap.erase(val);

        store.erase(it);
        return val;
    }

    int peek() {
        if (store.empty())
            return INT_MAX;
        list<int>::iterator it = --store.end();
        return *it;
    }

    int peekMax() {
        return valItMap.begin()->first;
    }

    int popMax() {
        if (store.empty())
            return INT_MAX;

        int maxVal = valItMap.begin()->first;

        list<int>::iterator it = valItMap.begin()->second.back();
        valItMap.begin()->second.pop_back();
        if (valItMap.begin()->second.empty())
            valItMap.erase(valItMap.begin());

        store.erase(it);

        return maxVal;
    }

private:
    list<int> store;
    list<int>::iterator back;
    map<int, vector<list<int>::iterator>, greater<int>> valItMap;
};

int main() {
    vector<int> nums = {5,4,3,2,1,6};
    MaxStack ms;

    for (int &num : nums)
        ms.push(num);

    cout << ms.peek() << endl;
    cout << ms.peekMax() << endl;
    cout << ms.popMax() << endl;
    cout << ms.popMax() << endl;
    cout << ms.peekMax() << endl;

    while (!ms.empty())
        cout << ms.pop() << " ";
    cout << endl;

}
