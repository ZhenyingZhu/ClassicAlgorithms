/*
 * [Source] https://leetcode.com/problems/queue-reconstruction-by-height/
 * [Difficulty]: Medium
 * [Tag]: Greedy
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <list>

using namespace std;

// [Solution]: Sort the people by 1. height from tall to short, 2. count from small to large. Then check from left to right, place them at the right place.
// [Corner Case]:
class Solution {
public:
    static bool greater(const pair<int, int> &pair1, const pair<int, int> &pair2) {
        // use for sort. Height from high to low, count from small to large
        if (pair1.first > pair2.first)
            return true;
        return pair1.first == pair2.first && pair1.second < pair2.second;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if (people.empty())
            return {};

        sort(people.begin(), people.end(), greater);

        list<pair<int, int>> lst;
        for (pair<int, int> &p : people) {
            auto it = findPos(p, lst);
            lst.insert(it, p); // insert to the previous of it
        }
        return vector<pair<int, int>>(lst.begin(), lst.end());
    }

    list<pair<int, int>>::iterator findPos(pair<int, int> &p, list<pair<int, int>> &lst) {
        int height = p.first, cnt = p.second;
        list<pair<int, int>>::iterator pos = lst.begin();
        while (pos != lst.end() && cnt > 0) {
            if (pos->first >= height)
                --cnt;
            ++pos;
        }
        // cnt should always be 0 at this time
        return pos;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<pair<int, int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    for (pair<int, int> & p : sol.reconstructQueue(people))
        cout << "[" << p.first << "," << p.second << "] ";
    cout << endl;

    return 0;
}
