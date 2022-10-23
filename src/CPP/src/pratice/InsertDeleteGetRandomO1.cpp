#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Source]: https://leetcode.com/problems/insert-delete-getrandom-o1/
// http://www.1point3acres.com/bbs/thread-225081-1-1.html

class RandomizedSet {
public:
    RandomizedSet() {
    }

    bool insert(int val) {
        if (numIdxMap.count(val))
            return false;

        nums.push_back(val);
        numIdxMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!numIdxMap.count(val))
            return false;

        int idx = numIdxMap[val];
        numIdxMap[nums.back()] = idx;
        swap(nums[idx], nums.back());
        nums.pop_back();
        numIdxMap.erase(val);
        return true;
    }

    int getRandom() {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }

private:
    vector<int> nums;
    unordered_map<int, int> numIdxMap;
};

int main() {
    RandomizedSet randomSet;
    cout << randomSet.insert(1) << endl;
    cout << randomSet.remove(2) << endl;
    cout << randomSet.insert(2) << endl;
    cout << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;
    cout << endl;
    cout << randomSet.remove(1) << endl;
    cout << randomSet.insert(2) << endl;
    cout << endl;
    cout << randomSet.getRandom() << endl;
    cout << randomSet.getRandom() << endl;

    return 0;
}
