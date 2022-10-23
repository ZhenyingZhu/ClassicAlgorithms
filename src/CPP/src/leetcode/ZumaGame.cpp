/*
 * [Source] https://leetcode.com/problems/zuma-game/
 * [Difficulty]: Hard
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

// [Solution]: Backtracking. NP hard
// [Corner Case]:
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<char, int> handCnt;
        for (char &c : hand)
            ++handCnt[c];

        return helper(board, handCnt, hand.size());
    }

    int helper(string &board, unordered_map<char, int> &handCnt, int left) {
        if (board.length() == 0)
            return 0;
        if (left == 0)
            return -1; // cannot finish

        int res = INT_MAX;
        for (int i = 1; i <= (int)board.size(); ++i) {
            if (i == (int)board.size() || board[i] != board[i - 1]) {
                char prev = board[i - 1];
                if (handCnt[prev] > 0) {
                    string newBoard = board;
                    newBoard.insert(i - 1, 1, prev);
cout << board << " insert " << prev << " becomes " << newBoard << endl;
                    shrink(newBoard);
cout << "after shrink " << newBoard << endl;
                    --handCnt[prev];
                    int tmp = helper(newBoard, handCnt, left - 1);
                    ++handCnt[prev];

                    if (tmp != -1)
                        res = min(res, 1 + tmp);
                }
            }
        }
        if (res == INT_MAX)
            return -1;
        return res;
    }

    void shrink(string &board) {
        if (board.size() < 3)
            return;

        char c = board[0];
        int cnt = 1;
        for (int i = 1; i < (int)board.length(); ++i) {
            if (board[i] == c) {
                ++cnt;
            } else if (cnt < 3) {
                c = board[i];
                cnt = 1;
            } else {
                board.erase(i - cnt, cnt);
                shrink(board);
                return; // need return here to not continue
            }
        }

        if (cnt >= 3) {
            board.erase(board.length() - cnt);
            shrink(board);
        }
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //cout << sol.findMinStep("WRRBBW", "RB") << endl;
    //cout << sol.findMinStep("WWRRBBWW", "RB") << endl;
    //cout << sol.findMinStep("G", "GGGGG") << endl;
    cout << sol.findMinStep("RBYYBBRRB", "YRBGB") << endl;

    return 0;
}
