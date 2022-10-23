#include <iostream>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-228718-1-1.html

struct Rabbit {
    int id;
    unordered_set<Rabbit*> directRelated;
    Rabbit(int i): id(i) { }
};

class Solution {
public:
    // the solution is wrong, because parents of a rabbit is not blood related
    bool isBloodRelated(Rabbit *r1, Rabbit *r2) {
        if (r1 == NULL || r2 == NULL)
            return false;

        unordered_set<Rabbit*> visited;
        return dfs(r1, r2, visited);
    }

private:
    bool dfs(Rabbit *node, Rabbit *target, unordered_set<Rabbit*> visited) {
        if (node == target)
            return true;

        visited.insert(node);
        for (Rabbit *direct : node->directRelated) {
            if (visited.count(direct))
                continue;
            if (dfs(direct, target, visited))
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    Rabbit r1(1), r2(2), r3(2), r4(4), r5(5), r6(6), r7(7), r8(8), r9(9), r0(0);
    r1.directRelated.insert(&r2); r1.directRelated.insert(&r3);
    r2.directRelated.insert(&r1); r2.directRelated.insert(&r4); r2.directRelated.insert(&r5);
    r3.directRelated.insert(&r1); r3.directRelated.insert(&r6); r3.directRelated.insert(&r7);
    r4.directRelated.insert(&r2); r4.directRelated.insert(&r5);
    r5.directRelated.insert(&r2); r5.directRelated.insert(&r4); r5.directRelated.insert(&r8);
    r6.directRelated.insert(&r3); r6.directRelated.insert(&r8); r6.directRelated.insert(&r9);
    r7.directRelated.insert(&r3);
    r8.directRelated.insert(&r5); r8.directRelated.insert(&r6);
    r9.directRelated.insert(&r6);

    cout << sol.isBloodRelated(&r1, &r6) << endl;
    cout << sol.isBloodRelated(&r4, &r9) << endl;
    cout << sol.isBloodRelated(&r1, &r0) << endl;

    return 0;
}
