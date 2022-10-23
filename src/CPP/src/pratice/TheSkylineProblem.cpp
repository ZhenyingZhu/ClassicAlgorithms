#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

// [Source]: https://leetcode.com/problems/the-skyline-problem/#/description

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<ScanLine> lines;
        for (vector<int> &building : buildings) {
            lines.push_back( {building[0], building[2], true} );
            lines.push_back( {building[1], building[2], false} );
        }
        sort(lines.begin(), lines.end());

        vector<pair<int, int>> res;
        multiset<int, greater<int>> heights;
        heights.insert(0);

        int currentHeight = 0;
        for (ScanLine &line : lines) {
            if (line.isUp) {
                heights.insert(line.y);
                if (line.y > currentHeight) {
                    currentHeight = line.y;
                    push(line.x, line.y, res);
                }
            } else {
                heights.erase(heights.find(line.y));
                int nextHeight = *heights.begin();
                if (nextHeight < currentHeight) {
                    currentHeight = nextHeight;
                    push(line.x, nextHeight, res);
                }
            }
        }
        return res;
    }

private:
    struct ScanLine {
        int x, y;
        bool isUp;

        bool operator<(const ScanLine &other) const {
            if (x < other.x)
                return true;
            if (x > other.x)
                return false;
            // if both are down, the smaller y should come first
            if (y < other.y)
                return true;
            if (y > other.y)
                return false;
            // if both are same height but one down one up, the up should come first
            return isUp;
        }
    };

    void push(int x, int y, vector<pair<int, int>> &res) {
        if (res.empty() || res.back().first < x) {
            res.push_back( {x, y} );
            return;
        }

        res.back().second = max(res.back().second, y);
    }
};

int main() {
    Solution sol;

    //vector<vector<int>> buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    //vector<vector<int>> buildings = {{2,3,10}, {2,3,5}};
    //vector<vector<int>> buildings = {{2,3,10}, {3,5,15}};
    vector<vector<int>> buildings = {{0,2,3}, {2,5,3}};
    for (pair<int, int> &point : sol.getSkyline(buildings))
        cout << "(" << point.first << "," << point.second << ") ";
    cout << endl;

    return 0;
}
