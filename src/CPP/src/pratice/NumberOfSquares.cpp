#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-230637-1-1.html

class Solution {
public:
    int numOfSquares(vector<vector<int>> &maze) {
        // 1 indicate an invalid cell
        if (maze.empty() || maze[0].empty()) {
            return 0;
        }

        vector<vector<int>> invalidIdxes = buildInvalidIdxes(maze);

        int m = maze.size(), n = maze[0].size();
        int num = 0;
        for (int i = 1; i <= min(m, n); ++i) {
            int tmp = countSquaresOfSize(m, n, i, invalidIdxes);
            cout << i << " " << tmp << endl;
            num += tmp;
        }

        return num;
    }

private:
    vector<vector<int>> buildInvalidIdxes(vector<vector<int>> &maze) {
        // store invalid cells of each row in a list
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> idxes(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (maze[i][j] == 1) {
                    idxes[i].push_back(j);
                }
            }
        }
        return idxes;
    }

    int countSquaresOfSize(int m, int n, int size, vector<vector<int>> &invalidIdxes) {
        int nums = 0;
        for (int i = size - 1; i < n; ++i) {
            vector<int> pts(size, 0);

            for (int j = size - 1; j < m; ++j) {
                bool valid = true;
                for (int k = 0; k < size; ++k) {
                    while (pts[k] < (int)invalidIdxes[i - size + 1 + k].size() && invalidIdxes[i - size + 1 + k][pts[k]] <= j - size) {
                        ++pts[k];
                    }

                    if (pts[k] < (int)invalidIdxes[i - size + 1 + k].size() && invalidIdxes[i - size + 1 + k][pts[k]] <= j) {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    ++nums;
            }
        }

        return nums;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> maze = {
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,0,0,0,0}
    };
    cout << sol.numOfSquares(maze) << endl;

    return 0;
}
