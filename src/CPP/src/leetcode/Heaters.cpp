/*
 * [Source] https://leetcode.com/problems/heaters/
 * [Difficulty]: Easy
 * [Tag]: Binary Search
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (houses.size() == 0)
            return 0;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        vector<int> closestHeater(houses.size() + 1, -1); // actually no need a vector
        closestHeater[0] = 0; // not a real house

        int radius = 0;
        for (int i = 1; i <= (int)houses.size(); ++i) {
            int heaterSt = closestHeater[i - 1];
            long smallestDis = INT_MAX;
            for (int h = heaterSt; h < (int)heaters.size(); ++h) {
                long dis = abs((long)houses[i - 1] - (long)heaters[h]);
                if (dis <= smallestDis) {
                    smallestDis = dis;
                    closestHeater[i] = h;
                } else {
                    break;
                }
            }

            if (smallestDis > radius)
                radius = smallestDis;
        }
        return radius;
    }
};

// [Solution]: Use a set to store heaters, then iterate through houses, find lower bound and its previous iterator to find the closest one

int main() {
    Solution sol;
    vector<int> houses = {1,2,3,4}, heaters = {1,4};
    cout << sol.findRadius(houses, heaters) << endl;

    return 0;
}
