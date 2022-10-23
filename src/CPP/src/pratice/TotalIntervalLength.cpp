#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [source]: http://www.1point3acres.com/bbs/thread-228275-1-1.html

class Solution {
public:
    double totalLength(vector<double> &intervalStarts) {
        unordered_map<int, double> left, right;
        for (double &start : intervalStarts) {
            int bucket = (int)(start + 1.0);
            if (!left[bucket])
                left[bucket] = (double)bucket;
            left[bucket] = min(start, left[bucket]);
            if (right.count(bucket - 1) && right[bucket - 1] >= left[bucket]) {
                right[bucket - 1] = (double)bucket;
                left[bucket] = (double)bucket;
            }

            if (!right[bucket])
                right[bucket] = (double)bucket;
            right[bucket] = max(start + 1.0, right[bucket]);
            if (left.count(bucket + 1) && left[bucket + 1] <= right[bucket]) {
                left[bucket + 1] = (double)bucket + 1.0;
                right[bucket] = (double)bucket + 1.0;
            }
        }

        double len = 0.0;
        for (auto it = left.begin(); it != left.end(); ++it) {
            len += right[it->first] - it->second;
        }
        return len;
    }
};

int main() {
    Solution sol;

    vector<double> intervals = {0.5, 1, 0};
    cout << sol.totalLength(intervals) << endl;

    return 0;
}
