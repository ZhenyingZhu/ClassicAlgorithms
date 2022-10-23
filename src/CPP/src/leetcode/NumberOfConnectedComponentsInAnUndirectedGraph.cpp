/*
 * [Source] https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Union Find
 * [Tag]: Graph
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// [Solution]: Union Find
// [Corner Case]:
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> unionSet(n, -1);
        for (pair<int, int> &edge : edges) {
            int lastIdxOfFirst = unionFind(unionSet, edge.first);
            int lastIdxOfSecond = unionFind(unionSet, edge.second);
            if (lastIdxOfFirst != lastIdxOfSecond) // They are already in the same union
                unionSet[lastIdxOfFirst] = lastIdxOfSecond;
        }

for (int &i : unionSet) cout << i << " "; cout << endl;
        int cnt = 0;
        for (int &i : unionSet) {
            if (i == -1)
                ++cnt;
        }
        return cnt;
    }

    int unionFind(vector<int> &unionSet, int vertex) {
        while (unionSet[vertex] != -1)
            vertex = unionSet[vertex];
        return vertex;
    }
};

// [Solution]: DFS on each node if not visited. If not visited before DFS, cnt++

int main() {
    Solution sol;

    vector<pair<int, int>> edges = {{0, 1}, {3, 4}, {0, 4}};
    cout << sol.countComponents(5, edges) << endl;

    return 0;
}
