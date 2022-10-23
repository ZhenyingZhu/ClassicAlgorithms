/*
 * [Source] https://leetcode.com/problems/h-index/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Sort the array. Use a counter start from 0 to count how many papers are larger than the counter. When the counter is same or larger than the index, previously there are h paper larger or equal than h (as counter hasn't increase when hit paper h - 1). From the defination: the max i of (min(n[i], i + 1), where i start from 0.
// [Corner Case]:
class Solution {
public:
    int hIndexSort(vector<int>& citations) {
        if (citations.empty())
            return 0;

        sort(citations.begin(), citations.end(), std::greater<int>());

        int res = 0;
        for (int i = 0; i < (int)citations.size(); ++i) {
            if (citations[i] > res) // Notice cannot be >=, because then res will 1 larger than result
                ++res;
        }

        return res;
    }

// [Solution]: Bucket sort
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        vector<int> paperNumWithCite(size + 1);
        for (size_t i = 0; i < citations.size(); ++i) {
            int idx = min(citations[i], size);
            ++paperNumWithCite[idx];
        }

        int sum = 0;
        for (int i = size; i >= 0; --i) {
            sum += paperNumWithCite[i];
            if (sum >= i)
                return i;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    vector<int> cications = {3, 0, 6, 1, 5};
    cout << sol.hIndex(cications) << endl;

    return 0;
}
