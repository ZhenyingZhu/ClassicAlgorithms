/*
 * [Source] https://leetcode.com/problems/minimum-genetic-mutation/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(end))
            return -1;
        return helper(start, end, dict);
    }

    int helper(string &start, string &end, unordered_set<string> &dict) {
        string gene = "ACGT";
        int steps = 0;

        queue<string> visiting;
        visiting.push(start);
        while (!visiting.empty()) {
            int levelSize = visiting.size();
            ++steps;
            for (int i = 0; i < levelSize; ++i) {
                string cur = visiting.front();
                visiting.pop();
                // tag as visiting
                dict.erase(cur);

                // find neighbor
                for (int i = 0; i < (int)cur.length(); ++i) {
                    char ori = cur[i];
                    for (char &tmp : gene) {
                        if (tmp == ori)
                            continue;
                        cur[i] = tmp;

                        // found end
                        if (cur == end)
                            return steps;

                        if (dict.count(cur))
                            visiting.push(cur);
                    }
                    cur[i] = ori;
                }
            }
        }

        // not find end
        return -1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    //cout << sol.minMutation("AACCGGTT", "AAACGGTA", bank) << endl;
    vector<string> bank = {"AACCGGTA"};
    cout << sol.minMutation("AACCGGTT", "AACCGGTA", bank) << endl;

    return 0;
}
