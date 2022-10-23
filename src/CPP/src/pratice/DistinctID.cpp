#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225497-1-1.html

// [Solution]: Union find with rank
class Solution {
public:
    int uniqueIds(int maxId, vector<pair<int, int>> &idsWithSameEmail) {
        if (maxId <= 0)
            return 0;
        UnionSet us(maxId + 1);

        for (pair<int, int> &idPair : idsWithSameEmail) {
            us.unite(idPair.first, idPair.second);
        }
        return us.count();
    }

private:
    struct UnionSet {
        UnionSet(int size) {
            parents.resize(size, -1);
            ranks.resize(size, 0);
        }

        int find(int x) {
            if (parents[x] == -1) {
                parents[x] = x;
                ranks[x] = 1;
            }

            while (parents[x] != x) {
                x = parents[x];
            }
            return x;
        }

        void unite(int x, int y) {
            int xRoot = find(x);
            int yRoot = find(y);
            if (ranks[xRoot] > ranks[yRoot]) {
                parents[yRoot] = xRoot;
                ++ranks[xRoot];
            } else {
                parents[xRoot] = yRoot;
                ++ranks[yRoot];
            }
        }

        int count() {
for (int &par : parents) cout << par << ","; cout << endl;
for (int &rank : ranks) cout << rank << ","; cout << endl;
            unordered_set<int> roots;
            for (int i = 0; i < (int)parents.size(); ++i) {
                int root = find(i);
                roots.insert(root);
            }
            return roots.size();
        }

        vector<int> parents;
        vector<int> ranks;
    };
};

int main() {
    Solution sol;

    vector<pair<int, int>> idPairs = {
        {1,2}, {2,3}, {6,5}
    };
    cout << sol.uniqueIds(6, idPairs) << endl;

    return 0;
}
