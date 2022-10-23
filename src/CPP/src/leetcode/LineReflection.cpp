/*
 * [Source] https://leetcode.com/problems/line-reflection/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

// [Solution]: Not consider duplicate points or points on the same x coordinate
// [Corner Case]:
class SolutionWrong {
public:
    static bool smaller(const pair<int, int> &p1, const pair<int, int> &p2) {
        if (p1.first < p2.first)
            return true;
        if (p1.first == p2.first && p1.second < p2.second)
            return true;
        return false;
    }

    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty())
            return true;

        sort(points.begin(), points.end(), smaller);
        int st = 0, ed = points.size() - 1;
        int mdTwice = points[st].first + points[ed].first;

        while (st <= ed) {
            if (points[st].second != points[ed].second)
                return false;
            if (points[st].first + points[ed].first != mdTwice)
                return false;

            ++st;
            --ed;
            while (st <= ed && points[st].first == points[st - 1].first && points[st].second == points[st - 1].second)
                st++;
            while (ed >= st && points[ed].first == points[ed + 1].first && points[ed].second == points[ed + 1].second)
                ed--;
        }
        return true;
    }
};

// [Solution]: Use hash table
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        if (points.empty())
            return true;

        int xMin = INT_MAX, xMax = INT_MIN;
        unordered_map<int, unordered_set<int>> xYMap;
        for (pair<int, int> &point : points) {
            xMin = min(xMin, point.first);
            xMax = max(xMax, point.first);
            xYMap[point.first].insert(point.second);
        }

        int midTwice = xMin + xMax;
        for (pair<int, int> &point : points) {
            int x = point.first, y = point.second;
            int reX = midTwice - x;
            if (!xYMap.count(reX) || !xYMap[reX].count(y)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;

    //vector<pair<int, int>> points = {{1,1}, {-1,1}};
    //vector<pair<int, int>> points = {{1,1}, {-1,-1}};
    //vector<pair<int, int>> points = {{-4,1}, {-2,6}, {4,1}, {2,6}};
    //vector<pair<int, int>> points = {{-5,1}, {-3,6},{-2,5},{3,1}, {1,6}};
    //vector<pair<int, int>> points = {{-5,1}, {-3,6},{-1,5},{3,1}, {1,6}};
    //vector<pair<int, int>> points = {{-16,1}, {16,1},{16,1}};
    vector<pair<int, int>> points = {{1,2}, {1,4},{2,2},{2,4}};
    cout << sol.isReflected(points) << endl;

    return 0;
}
