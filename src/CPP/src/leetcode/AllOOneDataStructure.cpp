/*
 * [Source] https://leetcode.com/problems/all-oone-data-structure/
 * [Difficulty]: Hard
 * [Tag]: Design
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <iterator>
#include <string>

using namespace std;

// [Solution]: My solution is right, but leetcode reports run time error, which I think it might because memory corrupt
class AllOneOutOfMemory {
public:
    struct ListNode {
        int val;
        unordered_set<string> keys;
        ListNode *next;
        ListNode *prev;
    };

    unordered_map<string, ListNode*> keyMap;
    unordered_map<int, ListNode*> valMap;
    ListNode *begin; // the previous of the first node
    ListNode *end; // the last node

    AllOneOutOfMemory() {
        begin = new ListNode{0};
        end = begin;
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
//cout << "inc before " << endl;
//printNodes();
        if (keyMap.count(key) > 0) {
            ListNode *node = keyMap[key];
            int val = node->val;
            node->keys.erase(key);
            keyMap.erase(key);

            insertNode(val + 1, key, node);

            if (node->keys.empty())
                eraseNode(node);
        } else {
            insertNode(1, key, begin);
        }
//cout << "inc after " << endl;
//printNodes();
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
//cout << "dec before " << endl;
//printNodes();
        if (keyMap.count(key) > 0) {
            ListNode *node = keyMap[key];
            int val = node->val;
            node->keys.erase(key);
            keyMap.erase(key);

            // if val is 1, this key needs remove
            if (val != 1)
                insertNode(val - 1, key, node->prev);

            if (node->keys.empty())
                eraseNode(node);
        }
//cout << "dec after " << endl;
//printNodes();
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
printNodes();
        if (end->val == 0)
            return "";
        return *(end->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
printNodes();
        if (begin->next == NULL)
            return "";
        return *(begin->next->keys.begin());
    }

    void eraseNode(ListNode *node) {
        // keyMap update always done in insertNode
        valMap.erase(node->val);
        // no need to deal with begin, because begin is always the sential node
        if (node == end)
            end = node->prev;

        if (node->next != NULL)
            node->next->prev = node->prev;
        node->prev->next = node->next; // can be null

        delete node;
    }

    void insertNode(int val, string key, ListNode *prev) {
        // insert node or update node
        ListNode *node;
        if (valMap.count(val) > 0) {
            node = valMap[val];
        } else {
            node = new ListNode{val};
            if (prev->next != NULL)
                prev->next->prev = node;
            node->next = prev->next;
            prev->next = node;
            node->prev = prev;

            valMap[val] = node;
        }

        if (val > end->val)
            end = node;

        node->keys.insert(key);
        keyMap[key] = node;
    }

    void printNodes() {
        ListNode *cur = begin;
        while (cur != NULL) {
            cout << cur->val << ": ";
            for (auto it = cur->keys.begin(); it != cur->keys.end(); ++it)
                cout << *it << " ";
            cout << endl;
            cur = cur->next;
        }
        cout << endl;
    }
};

// [Solution]:
class AllOne {
public:
    struct Bucket {
        int val;
        unordered_set<string> keys;
    };

    list<Bucket> buckets; // big val at begin, small val at end
    unordered_map<string, list<Bucket>::iterator> map;

    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!map.count(key)) {
            if (buckets.empty() || buckets.back().val != 1) {
                auto newBucketIt = buckets.insert(buckets.end(), {1, {key}}); // insert return iterator
                map[key] = newBucketIt;
            } else {
                auto valOneBucketIt = --buckets.end();
                valOneBucketIt->keys.insert(key);
                map[key] = valOneBucketIt;
            }
        } else {
            auto curBucketIt = map[key];
            auto largerBucketIt = prev(curBucketIt);
            if (curBucketIt == buckets.begin() || largerBucketIt->val != curBucketIt->val + 1) {
                auto newBucketIt = buckets.insert(curBucketIt, {curBucketIt->val + 1, {key}});
                map[key] = newBucketIt;
            } else {
                largerBucketIt->keys.insert(key);
                map[key] = largerBucketIt;
            }

            curBucketIt->keys.erase(key);
            if (curBucketIt->keys.empty())
                buckets.erase(curBucketIt);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (map.count(key)) {
            auto curBucketIt = map[key];
            if (curBucketIt->val != 1) {
                auto nextBucketIt = next(curBucketIt);
                if (nextBucketIt == buckets.end() || nextBucketIt->val != curBucketIt->val - 1) {
                    auto newBucketIt = buckets.insert(nextBucketIt, {curBucketIt->val - 1, {key}});
                    map[key] = newBucketIt;
                } else {
                    nextBucketIt->keys.insert(key);
                    map[key] = nextBucketIt;
                }
            } else {
                map.erase(key);
            }
            curBucketIt->keys.erase(key);
            if (curBucketIt->keys.empty())
                buckets.erase(curBucketIt);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (buckets.empty())
            return "";
        return *(buckets.front().keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (buckets.empty())
            return "";
        return *(buckets.back().keys.begin());
    }
};

class Solution {
public:
    void test() {
        AllOne obj;
        for (int i = 0; i < 10000; ++i) {
            obj.inc("a");
        }
        for (int i = 0; i < 6050; ++i) {
            obj.inc("b");
            obj.dec("b");
        }

        cout << obj.getMinKey() << endl;
        cout << obj.getMaxKey() << endl;
    }
};

int main() {
    Solution sol;

    sol.test();

    return 0;
}
