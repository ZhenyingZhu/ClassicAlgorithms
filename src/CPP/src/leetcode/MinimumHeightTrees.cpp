/*
 * [Source] https://leetcode.com/problems/minimum-height-trees/
 * [Difficulty]: Medium
 * [Tag]: Breadth-first Search
 * [Tag]: Graph
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// [Solution]: From defination, find all distances between nodes, and find two nodes that have minimal max distance to other nodes.
class SolutionBF {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (pair<int, int>& edge : edges) {
            int& first = edge.first;
            int& second = edge.second;
            graph[first].push_back(second);
            graph[second].push_back(first);
        }

        vector<vector<int>> distances(n, vector<int>(n, INT_MAX - 1)); // so that distance + 1 never overflow
        for (int i = 0; i < n; ++i) {
            distances[i][i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j)
                    continue;

                int distance = distances[i][j];
                for (int& end : graph[i]) {
                    if (j == end) {
                        distance = 1;
                    } else {
                        distance = min(distances[end][j] + 1, distance);
                    }
                }
                distances[i][j] = distance;
                distances[j][i] = distance;
            }
        }

        int minDistance = INT_MAX;
        unordered_map<int, vector<int>> heightOfNodes;
        for (int i = 0; i < n; ++i) {
            int maxDis = 0;
            for (int j = 0; j < n; ++j) {
cout << distances[i][j] << " ";
                maxDis = max(distances[i][j], maxDis);
            }
cout << endl;
            heightOfNodes[maxDis].push_back(i);
            minDistance = min(maxDis, minDistance);
        }
cout << endl;
        return heightOfNodes[minDistance];
    }
};

// [Solution]: Eliminate border nodes that have only one edge. The left 2 or 1 nodes are the result
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, unordered_set<int>> graph;
        for (pair<int, int>& edge : edges) {
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }

        queue<int> border;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1)
                border.push(i);
        }

        while (n > 2) {
            int eliminateNodes = border.size();
            n -= eliminateNodes;

            for (int i = 0; i < eliminateNodes; ++i) {
                int node = border.front();
                border.pop();

                int neighbor = *(graph[node].begin());
                graph[neighbor].erase(node);

                graph.erase(node);
            }

            for (auto nodeIt = graph.begin(); nodeIt != graph.end(); ++nodeIt) {
                if (nodeIt->second.size() == 1)
                    border.push(nodeIt->first);
            }
        }

        vector<int> res;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            res.push_back(it->first);
        }
        return res;
    }
};

int main() {
    Solution sol;

    //vector<pair<int, int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<pair<int, int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    for (int& node : sol.findMinHeightTrees(6, edges))
        cout << node << " ";
    cout << endl;

    return 0;
}
