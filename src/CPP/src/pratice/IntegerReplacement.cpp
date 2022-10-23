#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225644-1-1.html
// https://leetcode.com/problems/integer-replacement/

// [Solution]: BFS
class Solution {
public:
    int integerRelacementSteps(int a, int b) {
        if (a >= b)
            return 0;

        unordered_set<int> visiting;
        Node n{a, 0};
        queue<Node> q;
        q.push(n);
        while (!q.empty()) {
            Node cur = q.front();
            if (cur.val == b)
                return cur.step;

            q.pop();
            if (visiting.count(cur.val))
                continue;

            visiting.insert(cur.val);
            q.push({cur.val + 1, cur.step + 1});
            q.push({cur.val - 1, cur.step + 1});
            q.push({cur.val * 2, cur.step + 1});
        }

        return -1; // cannot reach here
    }

private:
    struct Node {
        int val;
        int step;
    };
};

int main() {
    Solution sol;

    cout << sol.integerRelacementSteps(1, 7) << endl;

    return 0;
}
