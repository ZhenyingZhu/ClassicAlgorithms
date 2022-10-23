/*
 * [Source] https://leetcode.com/problems/number-of-islands-ii/
 * [Difficulty]: Hard
 * [Tag]: Union Find
 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// [Solution]: Union find. Use fast find.
// [Corner Case]:
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int islands = 0;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<int> unionSet(m * n, -1);
        for (pair<int, int> &pos : positions) {
            int coor = pos.first * n + pos.second;
            unionSet[coor] = coor;
            ++islands;

            for (vector<int> &dir : dirs) {
                int x = pos.first + dir[0], y = pos.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                int neighbor = x * n + y;
                if (unionSet[neighbor] == -1)
                    continue; // this neighbor is still ocean

                // quick find. use the coor as root and append all other trees to coor's children
                if (unionSet[neighbor] == unionSet[coor])
                    continue; // they are already on a same island

                --islands; // two islands merge together
                int preRoot = unionSet[neighbor];
                for (int i = 0; i < m * n; ++i) {
                    if (unionSet[i] == preRoot)
                        unionSet[i] = coor;
                }
            }

            res.push_back(islands);
        }

        return res;
    }
};

int main() {
    Solution sol;

    vector<pair<int, int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}};
    for (int &i : sol.numIslands2(3, 3, positions))
        cout << i << " ";
    cout << endl;

    return 0;
}
