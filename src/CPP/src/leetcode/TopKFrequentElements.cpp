/*
 * [Source] https://leetcode.com/problems/top-k-frequent-elements/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Heap
 */

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// [Solution]: Count the number. Use heap with size k.
// [Corner Case]:
class Solution {
public:
    struct NumFreq {
        int num, freq;
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqs;
        for (int &num : nums) {
            ++freqs[num];
        }
        
        priority_queue< NumFreq, vector<NumFreq>, function<bool(NumFreq, NumFreq)> > pq
            ( [](const NumFreq &a, const NumFreq &b) -> bool {return a.freq > b.freq;} );
        for (auto it = freqs.begin(); it != freqs.end(); ++it) {
            pq.push({it->first, it->second});
            if ((int)pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().num);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    for (int &n : sol.topKFrequent(nums, 2))
        cout << n << " ";
    cout << endl;

    return 0;
}
