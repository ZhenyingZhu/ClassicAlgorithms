/*
 * [Source] https://leetcode.com/problems/teemo-attacking/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findPosisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty())
            return 0;

        int total = 0;
        for (int i = 0; i < (int)timeSeries.size() - 1; ++i) {
            int cur = timeSeries[i], next = timeSeries[i + 1];
            total += min(duration, next - cur);
        }
        return total + duration; // last hit
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> times = {1,4};
    cout << sol.findPosisonedDuration(times, 2) << endl;

    return 0;
}
