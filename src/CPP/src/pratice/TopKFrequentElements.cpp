#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/top-k-frequent-elements/
// http://www.1point3acres.com/bbs/thread-225716-1-1.html

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> numCnt;
        for (int &num : nums) {
            ++numCnt[num];
        }

        priority_queue<NumCnt, vector<NumCnt>, NumCntCmp> pq;
        for (auto it = numCnt.begin(); it != numCnt.end(); ++it) {
            pq.push( {it->first, it->second} );
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

private:
    struct NumCnt {
        int num;
        int cnt;
    };

    struct NumCntCmp {
        bool operator()(const NumCnt &nc1, const NumCnt &nc2) {
            return nc1.cnt > nc2.cnt;
        }
    };
};

int main() {
    Solution sol;

    vector<int> nums = {1,1,1,2,2,3};
    for (int &n : sol.topKFrequent(nums, 2))
        cout << n << ", ";
    cout << endl;

    return 0;
}
