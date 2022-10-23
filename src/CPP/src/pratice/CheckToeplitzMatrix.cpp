#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-229745-1-1.html

// Toeplitz Matrix
// 1,2,3,4
// 5,1,2,3
// 6,5,1,2

class Solution {
public:
    // divide tasks to n machines
    bool checkToeplitz(vector<vector<int>> &matrix, int n) {
        if (matrix.empty() || matrix[0].empty())
            return true;

        int h = matrix.size();
        if (h / n <= 1) {
            cout << "too much machine" << endl;
            return false;
        }

        int st = 0;
        bool res = true;
        while (st < h) {
            int ed = min(h, st + h / n);
            // put into a thread
            res &= helper(matrix, st, ed);
            if (ed < h) {
                // put into a thread
                res &= helper(matrix, ed - 1, ed + 1);
            }
            st = ed;
        }
        return res;
    }

private:
    bool helper(vector<vector<int>> &matrix, int st, int ed) {
        // pass in bool res, and lock it when trying to modify it
        int w = matrix[0].size();
        for (int i = st + 1; i < ed; ++i) {
            for (int j = 1; j < w; ++j) {
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1,2,3,4,5,6,7},
        {5,1,2,3,4,5,6},
        {6,5,1,3,3,4,5},
        {7,6,5,1,2,3,4},
        {8,7,6,5,1,2,3}
    };

    cout << sol.checkToeplitz(matrix, 2) << endl;

    return 0;
}
