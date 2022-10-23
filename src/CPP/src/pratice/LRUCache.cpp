#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>

using namespace std;

// [Source]: https://leetcode.com/problems/lru-cache/#/description
// http://www.1point3acres.com/bbs/thread-223577-1-1.html

class LRUCache {
public:
    LRUCache(int capacity): cap(capacity) {
    }

    int get(int key) {
        if (!keyItMap.count(key))
            return -1;

        list<KeyVal>::iterator it = keyItMap[key];
        int val = it->val;
        moveToEnd(it);
        return val;
    }

    void put(int key, int value) {
        if (keyItMap.count(key)) {
            list<KeyVal>::iterator it = keyItMap[key];
            it->val = value;
            moveToEnd(it);
            return;
        }

        usageList.push_back( {key, value} );
        keyItMap[key] = --usageList.end();

        if ((int)usageList.size() > cap) {
            int oldKey = usageList.begin()->key;
            keyItMap.erase(oldKey);
            usageList.erase(usageList.begin());
        }
    }

private:
    struct KeyVal {
        int key, val;
    };

    list<KeyVal> usageList; // head oldest
    unordered_map<int, list<KeyVal>::iterator> keyItMap;
    int cap;

private:
    void moveToEnd(list<KeyVal>::iterator it) {
        int key = it->key, val = it->val;
        usageList.erase(it);
        usageList.push_back( {key, val} );
        keyItMap[key] = --usageList.end();
    }
};

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4

    return 0;
}
