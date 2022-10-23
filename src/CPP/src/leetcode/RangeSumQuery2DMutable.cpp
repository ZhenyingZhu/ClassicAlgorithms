/*
 * [Source] https://leetcode.com/problems/range-sum-query-2d-mutable/
 * [Difficulty]: Hard
 * [Tag]: Binary Indexed Tree
 * [Tag]: Segment Tree
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Create indexed tree for each row, and sum up rows
// [Corner Case]:
class NumMatrix1D {
public:
    NumMatrix1D(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        indexTrees.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j)
                update(i, j, matrix[i][j]);
        }
    }

    void update(int row, int col, int val) {
        int oldVal = sumRegion(row, col, row, col);
        int diff = val - oldVal;
        // idx is base 1
        for (int idx = col + 1; idx <= (int)indexTrees[0].size(); idx += idx & -idx) {
            indexTrees[row][idx - 1] += diff;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += sumRow(i, col2) - sumRow(i, col1 - 1);
        }
        return sum;
    }

    int sumRow(int row, int col) {
        if (col < 0)
            return 0;
        int sum = 0;
        int idx = col + 1; // idx is base 1
        while (idx > 0) {
            sum += indexTrees[row][idx - 1];
            idx -= idx & -idx;
        }
        return sum;
    }

    vector<vector<int>> indexTrees;
};

// [Solution]: 2D indexed tree
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        tree.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < (int)matrix.size(); ++i) {
            for (int j = 0; j < (int)matrix[0].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }

for (vector<int> &vec : tree) {for (int &i : vec) cout << i << " "; cout << endl;}
    }

    void update(int row, int col, int val) {
        int diff = val - sumRegion(row, col, row, col);
        for (int i = row + 1; i < (int)tree.size(); i += i & -i) {
            for (int j = col + 1; j < (int)tree[0].size(); j += j & -j) {
                tree[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum(row2, col2) - sum(row2, col1 - 1) - sum(row1 - 1, col2) + sum(row1 - 1, col1 - 1);
    }

    int sum(int row, int col) {
        int sum = 0;
        for (int i = row + 1; i > 0; i -= i & -i) {
            for (int j = col + 1; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    vector<vector<int>> tree;
};

int main() {
    /*
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    */
    vector<vector<int>> matrix = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };

    NumMatrix mn(matrix);
    //cout << mn.sumRegion(2, 1, 4, 3) << endl;
    //mn.update(3, 2, 2);
    //cout << mn.sumRegion(2, 1, 4, 3) << endl;

    return 0;
}
