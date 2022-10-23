/*
 * [Source] https://leetcode.com/problems/number-of-boomerangs/
 * [Difficulty]: Easy
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

// [Solution]: For each distance, count how many nodes linked to one node
// [Corner Case]:
class SolutionTLE {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, unordered_map<int, int>> distanceMap;
        for (int i = 0; i < (int)points.size() - 1; ++i) {
            pair<int, int> &p1 = points[i];
            for (int j = i + 1; j < (int)points.size(); ++j) {
                pair<int, int> &p2 = points[j];
                int dis = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
                ++distanceMap[dis][i];
                ++distanceMap[dis][j];
            }
        }

        int res = 0;
        for (auto disIt = distanceMap.begin(); disIt != distanceMap.end(); ++disIt) {
            for (auto it = disIt->second.begin(); it != disIt->second.end(); ++it) {
                int num = it->second;
                res += num * (num - 1);
            }
        }
        return res;
    }
};

// [Solution]: for each mid node, see how many nodes are in the same distance to it
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        unordered_map<int, int> distanceMap;
        int res = 0;
        for (int i = 0; i < (int)points.size(); ++i) {
            pair<int, int> &p1 = points[i];
            for (int j = 0; j < (int)points.size(); ++j) {
                if (i == j)
                    continue;

                pair<int, int> &p2 = points[j];
                int dis = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
                ++distanceMap[dis];
            }

            for (auto it = distanceMap.begin(); it != distanceMap.end(); ++it) {
                int val = it->second;
                res += val * (val - 1);
            }

            distanceMap.clear();
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<pair<int, int>> points = {{0,0},{1,0},{2,0}};
    cout << sol.numberOfBoomerangs(points) << endl;

    return 0;
}
