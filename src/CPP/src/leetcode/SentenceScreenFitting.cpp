/*
 * [Source] https://leetcode.com/problems/sentence-screen-fitting/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// [Solution]: Use a hash map to store, on each line, if start with word i, what will be the end word, and how many times the sentences prints.
// [Corner Case]:
class Solution {
public:
    struct EdTimes {
        int edIdx;
        int times;
    };

    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        if (sentence.empty() || cols < (int)sentence[0].length())
            return 0;

        unordered_map<int, EdTimes> stIdxMap; // line start from the stIdx word in sentence, which is the edIdx(next st) and how many times the sentence repeat

        int res = 0;
        int stIdx = 0;
        for (int i = 0; i < rows; ++i) {
            res += helper(stIdx, sentence, cols, stIdxMap);
        }
        return res;
    }

    int helper(int &stIdx, vector<string> &sentence, int cols, unordered_map<int, EdTimes> &stIdxMap) {
        if (stIdxMap.count(stIdx)) {
            EdTimes &edTimes = stIdxMap[stIdx];
            stIdx = edTimes.edIdx;
            return edTimes.times;
        }

        int oldSt = stIdx;
        int len = 0;
        int repeats = 0;
        while (len <= cols) {
            if (len != 0)
                ++len; // space
            len += sentence[stIdx].length();
            if (len > cols)
                break;

            ++stIdx;
            if (stIdx == (int)sentence.size()) {
                stIdx = 0;
                ++repeats;
            }
        }

        stIdxMap[oldSt] = {stIdx, repeats};
        return repeats;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<string> sentence = {"hello", "world"};
    //cout << sol.wordsTyping(sentence, 2, 8) << endl;
    //vector<string> sentence = {"a", "bcd", "e"};
    //cout << sol.wordsTyping(sentence, 3, 6) << endl;
    vector<string> sentence = {"I", "had", "apple", "pie"};
    cout << sol.wordsTyping(sentence, 4, 5) << endl;

    return 0;
}
