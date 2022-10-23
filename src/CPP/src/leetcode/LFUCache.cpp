/*
 * [Source] https://leetcode.com/problems/lfu-cache/
 * [Difficulty]: Hard
 * [Tag]: Design
 */

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

// [Solution]: A map maps freq to a list of nodes. A map maps key to list iterator. a minfreq to track the minfreq. it needs only increase 1 when the minfreq number updated
// [Corner Case]:
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if ( !keyItMap.count(key) )
            return -1;

        list<Node>::iterator nodeIt = keyItMap[key];
        int val = nodeIt->val;

        // remove old node from the list in freq map
        int freq = nodeIt->freq;
        list<Node> &freqList = freqNodeListMap[freq];
        freqList.erase(nodeIt);
        if ( freq == minFreq &&freqList.empty() )
            ++minFreq; // previous freq is the minFreq and now change to freq+1

        // insert new node
        list<Node> &newFreqList = freqNodeListMap[freq + 1];
        newFreqList.push_back( {key, val, freq + 1} );
        keyItMap[key] = --newFreqList.end();

        return val;
    }

    void put(int key, int value) {
        if (cap <= 0)
            return;

        if ( get(key) != -1 ) { // get() update the freq of this key already
            list<Node>::iterator nodeIt = keyItMap[key];
            nodeIt->val = value;
            return;
        }

        // if exceed cap, remove a node
        if ((int)keyItMap.size() >= cap) {
            // get least freq and least recent key
            list<Node>::iterator leastNodeIt = freqNodeListMap[minFreq].begin();
            int leastKey = leastNodeIt->key;

            // totally remove the key
            freqNodeListMap[minFreq].erase(leastNodeIt);
            keyItMap.erase(leastKey);
        }

        // insert new node
        list<Node> &freqOneList = freqNodeListMap[1];
        freqOneList.push_back( {key, value, 1} );
        keyItMap[key] = --freqOneList.end();

        minFreq = 1;
    }

private:
    struct Node {
        int key;
        int val;
        int freq;
    };

    unordered_map<int, list<Node>> freqNodeListMap;
    unordered_map<int, list<Node>::iterator> keyItMap;
    int cap;
    int minFreq;
};

class Solution {
public:
    void test() {
        LFUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        cout << cache.get(1) << endl;       // returns 1
        cache.put(3, 3);    // evicts key 2
        cout << cache.get(2) << endl;       // returns -1 (not found)
        cout << cache.get(3) << endl;       // returns 3.
        cache.put(4, 4);    // evicts key 1.
        cout << cache.get(1) << endl;       // returns -1 (not found)
        cout << cache.get(3) << endl;       // returns 3
        cout << cache.get(4) << endl;       // returns 4
    }
};

int main() {
    Solution sol;
    sol.test();

    return 0;
}
