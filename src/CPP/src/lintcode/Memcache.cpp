/*
 * [Source] http://www.lintcode.com/en/problem/memcache/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

class Memcache {

// [Corner Case]:
// [Solution]: Store time in data node. Delete when query. Trying to use a class as value of the hash but failed. Use pointer instead.
public:
    Memcache() {
        table_.clear();
    }

    int get(int curtTime, int key) {
        auto it = table_.find(key);
        if (it == table_.end())
            return INT_MAX;
        if (it->second->isExpired(curtTime)) {
            delete it->second;
            table_.erase(key);
            return INT_MAX;
        }
        return it->second->getData();
    }

    // if ttl == 0, never expire
    void set(int curtTime, int key, int value, int ttl) {
        int expireTime = ttl == 0 ? 0 : curtTime + ttl;
        table_[key] = new ValueNode(value, expireTime);
    }

    void del(int curtTime, int key) {
        if (table_.find(key) != table_.end())
            delete table_[key];
        table_.erase(key);
    }
    
    int incr(int curtTime, int key, int delta) {
        return setValueNodeValue_(curtTime, key, delta);
    }
    
    int decr(int curtTime, int key, int delta) {
        return setValueNodeValue_(curtTime, key, -delta);
    }

private:
    class ValueNode {
    public:
        ValueNode(int d, int t):
            data_(d), expire_time_(t) {
            cout << "Construct " << d << endl;
        }

        ~ValueNode() {
            cout << "Destory " << data_ << endl;
        }

        void setData(int d) {
            data_ = d;
        }

        int getData() const {
            return data_;
        }

        bool isExpired(int currentTime) const {
            return (expire_time_ != 0 && expire_time_ <= currentTime);
        }

    private:
        int data_;
        int expire_time_;
    };

private:
    int setValueNodeValue_(int curtTime, int key, int absoluteDelta) {
        auto it = table_.find(key);
        if (it == table_.end())
            return INT_MAX;
        if (it->second->isExpired(curtTime)) {
            table_.erase(key);
            return INT_MAX;
        }
        int newVal = it->second->getData() + absoluteDelta;
        it->second->setData(newVal);
        return newVal;
    }

private:
    unordered_map<int, ValueNode*> table_;
};

// [Solution]:

int main() {
    Memcache mem;

    cout << mem.get(1, 0) << endl;
    mem.set(2, 1, 1, 2);
    cout << mem.get(3, 1) << endl;
    cout << mem.get(4, 1) << endl;
    cout << mem.incr(5, 1, 1) << endl;
    mem.set(6, 1, 3, 0);
    cout << mem.incr(7, 1, 1) << endl;
    cout << mem.decr(8, 1, 1) << endl;
    cout << mem.get(9, 1) << endl;
    mem.del(10, 1);
    cout << mem.get(11, 1) << endl;
    cout << mem.incr(12, 1, 1) << endl;

    return 0;
}
