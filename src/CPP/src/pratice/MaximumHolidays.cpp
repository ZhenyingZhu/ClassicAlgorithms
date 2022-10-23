#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224520-1-1.html

class Solution {
public:
    int maxHolidays(vector<vector<int>> holidaysCityWeek) {
        int citys = holidaysCityWeek.size();
        int weeks = holidaysCityWeek[0].size();

        vector<vector<int>> dp(citys + 2, vector<int>(weeks + 1, 0));
        for (int w = 0; w < weeks; ++w) {
            for (int c = 0; c < citys; ++c) {
                int maxHoliday = 0;
                for (int i = 0; i < 3; ++i) {
                    maxHoliday = max(maxHoliday, dp[c + i][w]);
                }
                dp[c + 1][w + 1] = maxHoliday + holidaysCityWeek[c][w];
            }
        }

        int res = 0;
        for (int c = 1; c <= citys; ++c) {
            res = max(res, dp[c].back());
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> holidaysCityWeek = {
        {2,0,4,0},
        {0,3,0,0},
        {1,0,0,5}
    };

    cout << sol.maxHolidays(holidaysCityWeek) << endl;

    return 0;
}
