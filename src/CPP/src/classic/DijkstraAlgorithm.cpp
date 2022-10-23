#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <climits>
#include <algorithm>

using namespace std;

// [Source]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

class Solution {
public:
    vector<string> shortestPath(unordered_map<string, unordered_map<string, int>> &graph, string src, string des) {
        map<int, unordered_set<string>> minHeap;
        unordered_map<string, int> minDist;
        unordered_map<string, string> prev;
        minHeap[0].insert(src);
        minDist[src] = 0;

        while (!minHeap.empty()) {
            unordered_set<string> &nodes = minHeap.begin()->second;
            string node = *nodes.begin();
            int dist = minDist[node];
            if (node == des)
                return getPath(node, src, prev);

            nodes.erase(node);
            if (nodes.empty())
                minHeap.erase(dist);

            for (auto neighborIt = graph[node].begin(); neighborIt != graph[node].end(); neighborIt++) {
                string neighbor = neighborIt->first;
                int neiDist = neighborIt->second + dist;
                if (minDist.count(neighbor) && minDist[neighbor] <= neiDist) {
                    continue;
                }

                if (minDist.count(neighbor)) {
                    int preDist = minDist[neighbor];
                    minHeap[preDist].erase(neighbor);
                }

                minHeap[neiDist].insert(neighbor);
                minDist[neighbor] = neiDist;
                prev[neighbor] = node;
            }
        }

        return {};
    }

    vector<string> getPath(string &des, string &src, unordered_map<string, string> &prev) {
        vector<string> path;
        string node = des;
        while (node != src) {
            path.push_back(node);
            node = prev[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main() {
    Solution sol;

    unordered_map<string, unordered_map<string, int>> graph;
    graph["a"]["b"] = 1; graph["a"]["c"] = 2; graph["a"]["d"] = 3;
    graph["b"]["e"] = 5; graph["b"]["d"] = 1;
    graph["c"]["e"] = 4;
    graph["d"]["e"] = 1;

    for (string &node : sol.shortestPath(graph, "a", "e"))
        cout << node << "->";
    cout << endl;

    return 0;
}
