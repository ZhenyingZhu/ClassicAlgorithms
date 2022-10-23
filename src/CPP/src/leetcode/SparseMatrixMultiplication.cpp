/*
 * [Source] https://leetcode.com/problems/sparse-matrix-multiplication/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Hash map is more expensive than array random access. So this solution is much faster 
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int h1 = A.size(), w1 = A[0].size();
        int w2 = B[0].size();

        vector<vector<int>> res(h1, vector<int>(w2, 0));
        for (int i = 0; i < h1; ++i) {
            for (int j = 0; j < w1; ++j) {
                if (A[i][j] == 0)
                    continue;

                for (int k = 0; k < w2; ++k) {
                    if (B[j][k] != 0)
                        res[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return res;
    }
};

// [Solution]: Use Hash map to avoid access each cell several times
// [Corner Case]:
class SolutionHashmap {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.empty() || B.empty())
            return {};
        int h1 = A.size(), w1 = A[0].size();
        int w2 = B[0].size();
        vector<vector<int>> res(h1, vector<int>(w2, 0));
        for (int i = 0; i < h1; ++i) {
            unordered_map<int, int> idxValMap;
            for (int x = 0; x < w1; ++x) {
                if (A[i][x] != 0)
                    idxValMap[x] = A[i][x];
            }

            for (int j = 0; j < w2; ++j) {
                int sum = 0;
                for (auto it = idxValMap.begin(); it != idxValMap.end(); ++it) {
                    int x = it->first;
                    sum += it->second * B[x][j];
                }
                res[i][j] = sum;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> A = {{1,0,0},{-1,0,3}};
    vector<vector<int>> B = {{7,0,0},{0,0,0},{0,0,1}};
    vector<vector<int>> res = sol.multiply(A, B);
    for (vector<int> &vec : res) {
        for (int &i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
