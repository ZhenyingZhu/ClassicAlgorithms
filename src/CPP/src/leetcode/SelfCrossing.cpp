/*
 * [Source] https://leetcode.com/problems/self-crossing/
 * [Difficulty]: Hard
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

// [Solution]: It is in a loop so only need to consider first 6 edges.
// [Corner Case]: For 6 edges cross, need be very careful
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        if (x.size() <= 3)
            return false;

        deque<int> edges;
        int i = 0;
        for (; i < 3; ++i)
            edges.push_back(x[i]);

        for (; i < (int)x.size(); ++i) {
            edges.push_back(x[i]);
            if (cross(edges)) {
for (int &a : edges)
    cout << a << " ";
cout << endl;
                return true;
            }

            if (edges.size() >= 6)
                edges.pop_front();
        }

        return false;
    }

    bool cross(deque<int> &edges) {
        // four edges cross
        if (edges[0] >= edges[2] && edges[1] <= edges[3])
            return true;

        // five edges cross
        if (edges.size() >= 5) {
            if (edges[1] == edges[3] && edges[0] + edges[4] >= edges[2])
                return true;
        }

        // six edges cross
        if (edges.size() >= 6) {
            // can this part of logic simplifier?
            if (edges[0] <= edges[2] && edges[4] <= edges[2] && edges[0] + edges[4] >= edges[2] &&
                edges[1] <= edges[3] && edges[5] <= edges[3] && edges[1] + edges[5] >= edges[3])
                return true;
        }

        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> x
        //= {2, 1, 1, 2};
        //= {1, 2, 3, 4};
        //= {1, 1,1,1};
        = {1,1,2,2,3,3,4,4,10,4,4,3,3,2,2,1,1};
    cout << sol.isSelfCrossing(x) << endl;

    return 0;
}
