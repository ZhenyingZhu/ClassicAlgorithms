/*
 * [Source] https://leetcode.com/problems/graph-valid-tree/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 * [Tag]: Graph
 * [Tag]: Union Find
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

// [Solution]: DFS
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < n; ++i)
            graph[i];
        for (pair<int, int> &edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        int components = 0;
        unordered_set<int> visited;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            if (!visited.count(it->first)) {
                ++components;
                if (!dfs(it->first, -1, graph, visited))
                    return false;
            }
        }
        return components == 1;
    }

    bool dfs(int node, int prev, unordered_map<int, unordered_set<int>> &graph, unordered_set<int> &visited) {
        if (visited.count(node))
            return false;

        visited.insert(node);
        for (auto it = graph[node].begin(); it != graph[node].end(); ++it) {
            if (*it == prev)
                continue;
            if (!dfs(*it, node, graph, visited))
                return false;
        }
        return true;
    }
};

// [Solution]: Use level. If two nodes are each neighbors, if there level different by 1, they are parent-child. Otherwise there is a cycle.
// [Corner Case]: Extra nodes that not connect to the graph
class SolutionSelfSolution {
public:
    struct NodeLevel {
        int id, level;
    };

    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.empty())
            return n == 1;

        unordered_map<int, unordered_set<int>> graph;
        for (pair<int, int> &edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }

        unordered_map<int, int> visited;
        stack<NodeLevel> visiting;
        visiting.push({graph.begin()->first, 0});
        while (!visiting.empty()) {
            NodeLevel node = visiting.top();
            visiting.pop();
            visited[node.id] = node.level;

            unordered_set<int> &neighbors = graph[node.id];
            for (auto neighborIt = neighbors.begin(); neighborIt != neighbors.end(); ++neighborIt) {
                if (visited.count(*neighborIt)) {
                    if (visited[*neighborIt] != node.level - 1)
                       return false;
                } else {
                    visiting.push({*neighborIt, node.level + 1});
                }
            }
        }
        return (int)visited.size() == n;
    }
};

int main() {
    Solution sol;

    //vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    //vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    //vector<pair<int, int>> edges = {{0, 1}, {1, 3}, {3, 4}};
    vector<pair<int, int>> edges = {};
    cout << sol.validTree(2, edges) << endl;

    return 0;
}
