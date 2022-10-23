#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: http://www.meetqun.net/thread-43863-1-1.html
// http://www.1point3acres.com/bbs/thread-225497-1-1.html

// Find all pairs
class SolutionFindAll {
public:
    vector<vector<int>> findTriangle(vector<int> &edges) {
        if (edges.size() <= 2)
            return {};

        vector<vector<int>> res;
        sort(edges.begin(), edges.end());
        int len = edges.size();
        for (int i = 0; i < len - 2; ++i) {
            for (int j = i + 1; j < len - 1; ++j) {
                int k = j + 1;
                while (k < len && edges[k] < edges[i] + edges[j]) {
                    res.push_back( {edges[i], edges[j], edges[k]} );
                    ++k;
                }
            }
        }
        return res;
    }
};

// Find if exist needs O(n)
class SolutionFindExist {
public:
    bool exist(vector<int> &nums) {
        if (nums.size() < 3)
            return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < (int)nums.size() - 2; ++i) {
            int &edge1 = nums[i], &edge2 = nums[i + 1], &edge3 = nums[i + 2];
            if (edge1 + edge2 > edge3)
                return true;
        }
        return false;
    }
};

// Count the number of triangles needs O(n^2), as k is move forwarding
class Solution {
    int count(vector<int> &nums) {
        if (nums.size() < 3)
            return 0;
        int size = nums.size();
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < size - 2; ++i) {
            int edge1 = nums[i];
            int k = i + 2;
            for (int j = i + 1; j < size - 1; ++j) {
                int edge2 = nums[j];
                while (k < size && edge1 + edge2 > nums[k])
                    ++k;

                res += k - j - 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> edges = {1, 2, 3, 1};
    /*
    for (vector<int> &vec : sol.findTriangle(edges)) {
        for (int &edge : vec)
            cout << edge << " ";
        cout << endl;
    }
    */

    cout << sol.exist(edges) << endl;
    return 0;
}
