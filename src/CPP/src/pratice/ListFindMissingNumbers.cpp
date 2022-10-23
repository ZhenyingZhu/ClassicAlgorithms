#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-224113-1-1.html

class Solution {
public:
    void findMissing(list<int> &list) {
        if (list.empty())
            return;

        list.sort();
        auto it = list.begin();
        int pre = *it;
        while (it != list.end()) {
            int cur = *it;
            for (int i = pre + 1; i < cur; ++i)
                cout << i << " ";

            pre = *it;
            ++it;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;

    vector<int> vec = {1, 2, 3, 7, 9, 4, 8};
    list<int> list(vec.begin(), vec.end());
    sol.findMissing(list);

    return 0;
}
