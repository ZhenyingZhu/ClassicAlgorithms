#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class TopologicalSort {
public:
    // Kahn'a algorithm, need modify the graph
    static vector<int> sort(unordered_map<int, vector<int>> &graph) {
        unordered_map<int, int> vertexIncome;
        for (auto verIt = graph.begin(); verIt != graph.end(); ++verIt) {
            if (!vertexIncome.count(verIt->first))
                vertexIncome[verIt->first] = 0;
            for (auto edgeIt = verIt->second.begin(); edgeIt != verIt->second.end(); ++edgeIt) {
                ++vertexIncome[*edgeIt];
            }
        }

        queue<int> noIncomes;
        for (auto it = vertexIncome.begin(); it != vertexIncome.end(); ++it) {
            if (it->second == 0) {
                noIncomes.push(it->first);
                vertexIncome.erase(it);
            }
        }

        vector<int> list;
        while (!noIncomes.empty()) {
            int node = noIncomes.front();
            noIncomes.pop();
            list.push_back(node);

            for (int &neighbor : graph[node]) {
                --vertexIncome[neighbor];
                if (vertexIncome[neighbor] == 0) {
                    noIncomes.push(neighbor);
                    vertexIncome.erase(neighbor);
                }
            }
        }

        if (!vertexIncome.empty()) {
            cout << "Cycle detected" << endl;
            return {}; // cycle detected
        }
        return list;
    }
};

int main() {
    unordered_map<int, vector<int>> graph;
    graph[1] = {2};
    graph[2] = {3};
    graph[3] = {1};

    for (int &i : TopologicalSort::sort(graph))
        cout << i << " ";
    cout << endl;

    return 0;
}
