#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-226105-1-1.html

class Solution {
public:
    vector<int> findCycle(vector<pair<int, int>> &edges) {
        // build graph
        unordered_map<int, Node*> nodeMap;
        for (pair<int, int> &edge : edges) {
            int val1 = edge.first, val2 = edge.second;
            if (!nodeMap.count(val1))
                nodeMap[val1] = new Node(val1);
            if (!nodeMap.count(val2))
                nodeMap[val2] = new Node(val2);

            nodeMap[val1]->neighbors.insert(nodeMap[val2]);
            nodeMap[val2]->neighbors.insert(nodeMap[val1]);
        }

        // dfs detect cycle
        vector<int> cycleNodes;
        for (auto it = nodeMap.begin(); it != nodeMap.end(); ++it) {
            if (it->second->visit > 0)
                continue;
            if (dfsDetectedCycle(it->second, 0, cycleNodes)) {
                break;
            }
        }

        // release resources
        for (auto it = nodeMap.begin(); it != nodeMap.end(); ++it) {
            delete it->second;
        }

        return cycleNodes;
    }

private:
    struct Node {
        int val;
        int visit;
        unordered_set<Node*> neighbors;
        Node(int x): val(x), visit(0) { }
    };

private:
    bool dfsDetectedCycle(Node *node, int preDepth, vector<int> &cycleNodes) {
        if (node->visit != 0) {
            // the parent of the node
            if (node->visit == preDepth - 1)
                return false;

            // cycle detected
            return true;
        }

        node->visit = preDepth + 1;
        cycleNodes.push_back(node->val);
        for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it) {
            if (dfsDetectedCycle(*it, preDepth + 1, cycleNodes))
                return true;
        }
        cycleNodes.pop_back();
        return false;
    }
};

int main() {
    Solution sol;

    vector<pair<int, int>> pairs = { {4,5}, {1,2}, {3, 2}, {3,1} };
    for (int &n : sol.findCycle(pairs))
        cout << n << "->";
    cout << endl;

    return 0;
}
