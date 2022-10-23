/*
 * [Source] https://leetcode.com/problems/rearrange-string-k-distance-apart/
 * [Difficulty]: Hard
 * [Tag]: Hash Table
 * [Tag]: Heap
 * [Tag]: Greedy
 */

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// [Solution]: Count the char number and place chars every k position away. Place the char appear most times first. If when place a char and it is not k distance apart from the first char in the result, return empty string
// [Corner Case]:
class Solution {
public:
    struct CharCnt {
        char c;
        int cnt;
    };

    struct Compare {
        bool operator()(const CharCnt &c1, const CharCnt &c2) {
            return c1.cnt < c2.cnt;
        }
    };

    string rearrangeString(string str, int k) {
        if (k == 0)
            return str;

        unordered_map<char, int> charCnt;
        for (char &c : str)
            ++charCnt[c];

        priority_queue< CharCnt, vector<CharCnt>, Compare > pq;
        for (auto it = charCnt.begin(); it != charCnt.end(); ++it) {
            int cnt = it->second;
            // if a12a12a is longer than the string length, then ("aaa***",3) has no result
            if ( (cnt - 1) * k + 1 > (int)str.length() )
                return "";

            pq.push( {it->first, cnt} );
        }

        vector<char> res(str.length(), '*');
        int idx = 0;
        while (!pq.empty()) {
            char c = pq.top().c;
            int cnt = pq.top().cnt;
            pq.pop();

            // since already pick char from most freq to less freq. if a char still placed around its start position, there is no room for it
            int st = idx;
            for (int i = 0; i < cnt; ++i) {
                if (idx != st && abs(idx - st) < k)
                    return "";
                res[idx] = c;
                idx = getNext(idx, k, res.size());
            }
        }
        return string(res.begin(), res.end());
    }

    int getNext(int idx, int k, int size) {
        if (idx + k  < size)
            return idx + k;
        return idx % k + 1;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //cout << sol.rearrangeString("abacabcd", 2) << endl;
    //cout << sol.rearrangeString("aaabc", 3) << endl;
    cout << sol.rearrangeString("aabbcc", 2) << endl;

    return 0;
}
