#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> levelOrder(string src, unordered_map<string, vector<string>> &undirectGraph) {
        vector<vector<string>> res;
        unordered_set<string> visited;
        queue<string> q;
        q.push(src);
        while (!q.empty()) {
            res.push_back({});
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();

                if (visited.count(cur))
                    continue;

                visited.insert(cur);
                res.back().push_back(cur);

                for (string &nei : undirectGraph[cur])
                    q.push(nei);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    unordered_map<string, vector<string>> undirectGraph;
    undirectGraph["a"].push_back("b"); undirectGraph["a"].push_back("c");
    undirectGraph["b"].push_back("a"); undirectGraph["b"].push_back("c");
    undirectGraph["c"].push_back("a"); undirectGraph["a"].push_back("b");

    for (vector<string> &level : sol.levelOrder("a", undirectGraph)) {
        for (string &node : level)
            cout << node << ", ";
        cout << endl;
    }

    return 0;
}
