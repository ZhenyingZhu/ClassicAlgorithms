#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/h-index/?tab=Description
// http://www.1point3acres.com/bbs/thread-228718-1-1.html

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int size = citations.size();
        vector<int> citePapersMap(size + 1, 0);
        for (int &cite : citations) {
            int idx = cite > size ? size : cite;
            citePapersMap[idx]++;
        }

        int papers = 0;
        for (int cite = size; cite >= 0; --cite) {
            papers += citePapersMap[cite];
            if (papers >= cite)
                return cite;
        }
        return 0;
    }
};

int main() {
    Solution sol;

    //vector<int> cites = {3, 0, 6, 1, 5};
    vector<int> cites = {3, 3,3};
    cout << sol.hIndex(cites) << endl;

    return 0;
}
