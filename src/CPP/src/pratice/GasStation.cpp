#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/gas-station/
// http://www.1point3acres.com/bbs/thread-224069-1-1.html

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty() || gas.size() != cost.size())
            return -1;

        int size = gas.size();
        int gasSum = 0, costSum = 0;
        for (int i = 0; i < size; ++i) {
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (gasSum < costSum)
            return -1;

        int idx = 0;
        int curGas = 0, curCost = 0;
        for (int i = 0; i < size; ++i) {
            curGas += gas[i];
            curCost += cost[i];

            if (curGas < curCost) {
                // cannot reach end before i
                idx = i + 1;
                curGas = 0;
                curCost = 0;
            }
        }
        return idx;
    }
};

int main() {
    Solution sol;

    vector<int> gas = {3,1,2}, cost = {1,4,2};
    cout << sol.canCompleteCircuit(gas, cost) << endl;

    return 0;
}
