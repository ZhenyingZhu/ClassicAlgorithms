#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-228718-2-1.html

struct Rabbit {
    int id;
    Rabbit *father, *mother;
    Rabbit(int i): id(i), father(NULL), mother(NULL) { }
};

class Solution {
public:
    bool isBloodRelated(Rabbit *r1, Rabbit *r2) {
        if (r1 == NULL || r2 == NULL)
            return false;

        unordered_set<Rabbit*> visited1, visited2;
        queue<Rabbit*> q1, q2;
        q1.push(r1);
        q2.push(r2);

        while (!q1.empty() && !q2.empty()) {
            if (update(q1, visited1, visited2))
                return true;
            if (update(q2, visited2, visited1))
                return true;
        }

        while (!q1.empty()) {
            if (update(q1, visited1, visited2))
                return true;
        }

        while (!q2.empty()) {
            if (update(q2, visited2, visited1))
                return true;
        }

        return false;
    }

    bool update(queue<Rabbit*> &q, unordered_set<Rabbit*> &visited, unordered_set<Rabbit*> &otherVisited) {
        Rabbit *next = q.front();
        q.pop();

        if (otherVisited.count(next))
            return true;

        if (!visited.count(next)) {
            if (next->father != NULL)
                q.push(next->father);

            if (next->mother != NULL)
                q.push(next->mother);
        }
        visited.insert(next);

        return false;
    }
};

int main() {
    Solution sol;

    Rabbit r1(1), r2(2), r3(3), r4(4), r5(5), r6(6), r7(7), r8(8), r9(9), r0(0);
    r1.father = &r2; r1.mother = &r3;
    r2.father = &r4; r2.mother = &r5;
    r3.father = &r6; r3.mother = &r7;
    r5.father = &r4; r5.mother = &r8;
    r6.father = &r8; r6.mother = &r9;

    cout << sol.isBloodRelated(&r1, &r6) << endl;
    cout << sol.isBloodRelated(&r4, &r9) << endl;
    cout << sol.isBloodRelated(&r1, &r0) << endl;

    return 0;
}
