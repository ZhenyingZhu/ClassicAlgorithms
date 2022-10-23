#include <iostream>
#include <unordered_set>

using namespace std;

// [Source]: EPI 13.13
// http://www.1point3acres.com/bbs/thread-226035-1-1.html
class Solution {
public:
    bool testCollatz(int n) {
        unordered_set<long> visited;
        visited.insert(1);

        for (int i = 2; i <= n; i++) {
            long cur = i;
            unordered_set<long> visiting;
            bool conjecture = false;
            while (!visiting.count(cur)) {
                if (visited.count(cur)) {
                    conjecture = true;
                    visited.insert(visiting.begin(), visiting.end());
                    break;
                }

                visiting.insert(cur);
                cur = cur % 2 == 0 ? cur / 2 : cur * 3 + 1;
            }

            if (!conjecture)
                return false;
            for (auto it = visited.begin(); it != visited.end(); it++)
                cout << *it << ", ";
            cout << endl;
        }
        return true;
    }
};

int main() {
    Solution sol;

    cout << sol.testCollatz(20) << endl;

    return 0;
}
