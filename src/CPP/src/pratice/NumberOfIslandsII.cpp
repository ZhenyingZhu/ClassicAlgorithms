#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// [Source]: https://leetcode.com/problems/number-of-islands-ii/
// http://www.1point3acres.com/bbs/thread-227554-1-1.html

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>> &positions) {
        m_ = m;
        n_ = n;
        parents.resize(m * n, -1);
        dirs = {1, 0, -1, 0, 1};

        vector<int> res;
        int islands = 0;
        for (pair<int, int> &position : positions) {
            int idx = getIdx(position.first, position.second);
            if (parents[idx] != -1) {
                res.push_back(islands);
                continue;
            }

            parents[idx] = idx;
            islands++;

            for (int i = 0; i < 4; ++i) {
                int newX = position.first + dirs[i], newY = position.second + dirs[i + 1];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n)
                    continue;

                int oldPar = parents[getIdx(newX, newY)];
                if (oldPar != -1 && oldPar != idx) {
                    islands--;
                    dfs(newX, newY, oldPar, idx);
                }
            }

            res.push_back(islands);
        }

        return res;
    }

private:
    int getIdx(int x, int y) {
        return x * n_ + y;
    }

    void dfs(int x, int y, int oriPar, int tarPar) {
        if (x < 0 || x >= m_ || y < 0 || y >= n_)
            return;

        int idx = getIdx(x, y);
        if (parents[idx] != oriPar)
            return;
        parents[idx] = tarPar;

        for(int i = 0; i < 4; ++i) {
            int newX = x + dirs[i], newY = y + dirs[i + 1];
            dfs(newX, newY, oriPar, tarPar);
        }
    }

    int m_, n_;
    vector<int> parents;
    vector<int> dirs;
};

int main() {
    Solution sol;

    vector<pair<int, int>> positions = {{0,0},{0,1},{1,2},{2,1},{1,2},{1,1}};
    for (int &num : sol.numIslands2(3, 3, positions))
        cout << num << endl;

    return 0;
}
