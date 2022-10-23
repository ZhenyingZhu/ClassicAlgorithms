/*
 * [Source] http://www.lintcode.com/en/problem/consistent-hashing/
 * [Difficulty]: Easy
 * [Tag]: 
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// [Corner Case]:
// [Solution]: Use priority queue. Notice priority queue put largest element at top. So to ge the largest machine, operator< need first compare size, and return the machine with smaller size. If size are same, return the bigger id.
class Solution {
public:
    /**
     * @param n a positive integer
     * @return n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        priority_queue<Machine> machines;
        machines.push(Machine(1, 0, 359));
        for (int i = 2; i <= n; ++i) {
            Machine bigMachine = machines.top();
            machines.pop();
            Machine newMachine = bigMachine.divide(i);
            machines.push(bigMachine);
            machines.push(newMachine);
        }

        vector<vector<int>> res;
        while (!machines.empty()) {
            res.push_back(machines.top().getVector());
            machines.pop();
        }
        return res;
    }

private:
    class Machine {
    public:
        Machine(int i, int s, int e): 
            id_(i), st_(s), ed_(e) { }

        Machine divide(int newId) {
            int newEd = ed_;
            ed_ = (st_ + ed_) / 2;
            int newSt = ed_ + 1;
            return Machine(newId, newSt, newEd);
        }

        vector<int> getVector() const {
            return {st_, ed_, id_};
        }

        bool operator<(const Machine& other) const {
            if ((ed_ - st_) < (other.ed_ - other.st_)) {
                return true;
            } else if ((ed_ - st_) == (other.ed_ - other.st_)) {
                return id_ > other.id_;
            } else {
                return false;
            }
        }

    private:
        int id_;
        int st_, ed_;
    };
};

// [Solution]: Use inplace change, so that smaller id always shows eariler than other machines.

int main() {
    Solution sol;
    for (int i = 1; i <= 26; ++i) {
        cout << "machines: " << i << endl;
        vector<vector<int>> res = sol.consistentHashing(i);
        for (vector<int>& vec : res) {
            for (int& num : vec) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
