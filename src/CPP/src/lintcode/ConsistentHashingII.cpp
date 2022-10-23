/*
 * [Source] http://www.lintcode.com/en/problem/consistent-hashing-ii/
 * [Difficulty]: Medium
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

// [Corner Case]:
// [Solution]: Use a list to store points, and a hash map to store point machine map.
class Solution {
private:
    struct ListNode {
        ListNode(int p):
            point(p) { }

        bool operator<(const ListNode& other) const {
            return point < other.point;
        }

        int point;
        ListNode *next;
    };

public:
    // @param n a positive integer present machine number
    // @param k a positive integer present how much data point does one machine charge
    // @return a Solution object
    static Solution create(int n, int k) {
        return Solution(n, k);
    }

    Solution(int n, int k):
        range_(n), pointNum_(k) {
        dummy_ = new ListNode(-1);
        pointMachine_.clear();
        srand (time(NULL));
    }

    ~Solution() {
        ListNode *cur = dummy_;
        while (cur != NULL) {
            ListNode *tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }

    // @param machine_id an integer
    // @return a list of shard ids
    vector<int> addMachine(int machine_id) {
        vector<int> nums = getRandomNums();
        for (int& num : nums) {
            addPoint_(num, machine_id);
        }
        return nums;
    }

    // @param hashcode an integer
    // @return a machine id
    int getMachineIdByHashCode(int hashcode) {
        ListNode *prev = getPreviousNode_(hashcode);
        ListNode *node;
        if (prev->next == NULL) {
            node = dummy_->next;
        } else {
            node = prev->next;
        }
printNodes_();
        return pointMachine_[node->point];
    }

private:
    vector<int> getRandomNums() {
        vector<int> randNums;
        while ((int)randNums.size() < pointNum_) {
            int tmp = rand() % range_;
            if ( pointMachine_.find(tmp) == pointMachine_.end() && find(randNums.begin(), randNums.end(), tmp) == randNums.end() )
                randNums.push_back(tmp);
        }
        return randNums;
    }

    ListNode* getPreviousNode_(int num) {
        // Never return NULL because there is a dummy
        ListNode *cur = dummy_;
        while (cur->next != NULL) {
            if (cur->next->point >= num)
                break;
            cur = cur->next;
        }
        return cur;
    }

    void addPoint_(int num, int machineId) {
        ListNode *prev = getPreviousNode_(num);
        ListNode *cur = new ListNode(num);
        ListNode *tmp = prev->next;
        cur->next = tmp;
        prev->next = cur;
        pointMachine_[num] = machineId;
    }

    void printNodes_() {
        ListNode* cur = dummy_;
        while (cur != NULL) {
            int machine = pointMachine_[cur->point];
            cout << cur->point << "(" << machine << ")->";
            cur = cur->next;
        }
        cout << endl;
    }

private:
    ListNode *dummy_;
    int range_;
    int pointNum_;
    unordered_map<int, int> pointMachine_;
};

// [Solution]:

int main() {
    Solution sol = Solution::create(100, 3);
    for (int& n : sol.addMachine(1))
        cout << n << " ";
    cout << endl;
    cout << sol.getMachineIdByHashCode(4) << endl;
    for (int& n : sol.addMachine(2))
        cout << n << " ";
    cout << endl;
    cout << sol.getMachineIdByHashCode(61) << endl;
    cout << sol.getMachineIdByHashCode(91) << endl;

    return 0;
}
