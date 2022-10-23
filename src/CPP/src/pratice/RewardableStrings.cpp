#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-228248-1-1.html

class SolutionDFS {
public:
    int rewardStringNum(int n) {
        int cnt = 0;
        a0l0 = 0;
        a0l1 = 0;
        a0l2 = 0;
        a1l0 = 0;
        a1l1 = 0;
        a1l2 = 0;
        vector<char> prev;
        helper(n, prev, cnt);
        cout << "b0,0: " << a0l0 << endl;
        cout << "b0,1: " << a0l1 << endl;
        cout << "b0,2: " << a0l2 << endl;
        cout << "b1,0: " << a1l0 << endl;
        cout << "b1,1: " << a1l1 << endl;
        cout << "b1,2: " << a1l2 << endl;
        return cnt;
    }

    void helper(int n, vector<char> &prev, int &cnt) {
        if ((int)prev.size() == n) {
            if (rewardable(prev)) {
                cout << string(prev.begin(), prev.end()) << endl;

                int aCnt = 0, lCnt = 0;
                for (char c : prev) {
                    if (c == 'A') {
                        aCnt = 1;
                        break;
                    }
                }
                for (int i = (int)prev.size() - 1; i >= 0; --i) {
                    if (prev[i] == 'L')
                        ++lCnt;
                    else
                        break;
                }
                if (aCnt == 0 && lCnt == 0)
                    ++a0l0;
                else if (aCnt == 0 && lCnt == 1)
                    ++a0l1;
                else if (aCnt == 0 && lCnt == 2)
                    ++a0l2;
                else if (aCnt == 1 && lCnt == 0)
                    ++a1l0;
                else if (aCnt == 1 && lCnt == 1)
                    ++a1l1;
                else if (aCnt == 1 && lCnt == 2)
                    ++a1l2;
                ++cnt;
            }
            return;
        }

        string candidates = "OLA";
        for (char &c : candidates) {
            prev.push_back(c);
            helper(n, prev, cnt);
            prev.pop_back();
        }
    }

    bool rewardable(vector<char> &str) {
        int aCnt = 0, lCnt = 0;
        for (char &c : str) {
            if (c == 'A') {
                if (aCnt == 1)
                    return false;
                lCnt = 0;
                ++aCnt;
            } else if (c == 'L') {
                if (lCnt == 2)
                    return false;
                ++lCnt;
            } else { // O
                lCnt = 0;
            }
        }
        return true;
    }

    int a0l0,a0l1,a0l2,a1l0,a1l1,a1l2;
};

class Solution {
public:
    int rewardStringNum(int n) {
        // dp[n][a][l]. n means n char, a means how many a, l means how many consective l
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[0][0][0] = 1;
        for (int idx = 1; idx <= n; ++idx) {
            //              OO+O,LO+O           OL+O                LL+O
            dp[idx][0][0] = dp[idx - 1][0][0] + dp[idx - 1][0][1] + dp[idx - 1][0][2];
            //              OO+L,LO+L
            dp[idx][0][1] = dp[idx - 1][0][0];
            //              OL+L
            dp[idx][0][2] = dp[idx - 1][0][1];
            //              OA+O,AO+O,LA+O      AL+O                ALL+O               OO+A,LO+A           OL+A                LL+A
            dp[idx][1][0] = dp[idx - 1][1][0] + dp[idx - 1][1][1] + dp[idx - 1][1][2] + dp[idx - 1][0][0] + dp[idx - 1][0][1] + dp[idx - 1][0][2];
            //              OA+L,AO+L,LA+L
            dp[idx][1][1] = dp[idx - 1][1][0];
            //              AL+L
            dp[idx][1][2] = dp[idx - 1][1][1];
        }

        int cnt = 0;
        for (int a = 0; a <= 1; ++a) {
            for (int l = 0; l <= 2; ++l) {
                cout << a << "," << l << ": " << dp.back()[a][l] << endl;
                cnt += dp.back()[a][l];
            }
        }
        return cnt;
    }
};

int main() {
    SolutionDFS sold;
    Solution sol;

    // 1: O, L, A
    // 2: OO, OL, LO, LL, OA, LA, AO, AL
    // 3: OOO, OOL, OOA, OLO, OLL, OLA, OAO, OAL, LOO, LOA, LOL, LLO, LLA, LAO, LAL, AOO, AOL, ALO, ALL
    for (int i = 1; i <= 5; ++i) {
        cout << sol.rewardStringNum(i) << " = " << sold.rewardStringNum(i) << endl;
    }

    return 0;
}
