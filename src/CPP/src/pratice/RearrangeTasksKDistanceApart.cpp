#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-257097-1-1.html

class Solution {
// This solution is wrong. Error case: "aabbcc", 1. return is a,b,a,b,c,*,c, but can be a,b,c,a,b,c
// The solution in https://leetcode.com/problems/rearrange-string-k-distance-apart/ is to fix the size as the old string, and append to the end, like 1. a*a***, 2. aba*b*, 3. abacbc
public:
    string rearrangeTask(string tasks, int k) {
        if (tasks.empty() || k == 0)
            return tasks;

        // assume there is only one task, the max length is 1,*,*,1,*,*
        string res( tasks.length() * (k + 1), '*' );

        // count appear times of each task and push them into a max heap
        unordered_map<char, int> task2cnt;
        for (char &t : tasks)
            task2cnt[t]++;
        priority_queue<TaskCnt> maxHeap;
        for (auto it = task2cnt.begin(); it != task2cnt.end(); it++)
            maxHeap.push( {it->first, it->second} );

        // place tasks that appear most times first, because 1,2,*,1 is better than 2,1,*,*,1
        int idx = 0;
        while (!maxHeap.empty()) {
            TaskCnt taskCnt = maxHeap.top();
            maxHeap.pop();
            char task = taskCnt.t;
            int cnt = taskCnt.cnt;

            for (int i = 0; i < cnt; i++) {
                res[idx] = task;
                idx = idx + k + 1;
            }

            idx = res.find_first_of("*");
        }

        // remove place holders
        res.erase(res.find_last_not_of("*") + 1);
        if (res.find("*") != string::npos)
            return "";
        return res;
    }

private:
    struct TaskCnt {
        char t;
        int cnt;
        bool operator<(const TaskCnt &other) const {
            return cnt < other.cnt;
        }
    };
};

int main() {
    Solution sol;
    cout << sol.rearrangeTask("1112233", 0) << endl;
    cout << sol.rearrangeTask("1112233", 1) << endl;
    cout << sol.rearrangeTask("1112233", 2) << endl;
    cout << sol.rearrangeTask("1112233", 3) << endl;
    cout << sol.rearrangeTask("11223344", 2) << endl;

    return 0;
}
