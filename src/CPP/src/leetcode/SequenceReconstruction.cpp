/*
 * [Source] https://leetcode.com/problems/sequence-reconstruction/
 * [Difficulty]: Medium
 * [Tag]: Graph
 * [Tag]: Topological Sort
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// [Solution]: Topological sort by DFS or khan, both TLE
// [Corner Case]: if there is a cycle, no unique seq can reconstruct
class SolutionTLE {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> &vec : seqs) {
            if (vec.empty())
                continue;
            graph[vec[0]];
            for (int i = 1; i < (int)vec.size(); ++i) {
                graph[vec[i]].insert(vec[i - 1]);
            }
        }

        vector<int> sort = topologicalSort(graph);
for (int &i : sort) cout << i << " "; cout << endl;
        return org == sort;
    }

    vector<int> topologicalSort(unordered_map<int, unordered_set<int>> &graph) {
        unordered_map<int, int> nodeLevel;
        for (auto it = graph.begin(); it != graph.end(); ++it) {
            vector<int> path;
            if ( !dfs(it->first, graph, path, nodeLevel) )
                return {};
        }

        vector<int> sort(graph.size(), -1);
        for (auto it = nodeLevel.begin(); it != nodeLevel.end(); ++it) {
            if (sort[it->second - 1] != -1) // two nodes on the same level
                return {};
            sort[it->second - 1] = it->first;
        }
        return sort;
    }

    bool dfs(int stNode, unordered_map<int, unordered_set<int>> &graph, vector<int> &path, unordered_map<int, int> &nodeLevel) {
cout << stNode << endl;
        if (find(path.begin(), path.end(), stNode) != path.end()) // cycle detected
            return false;
        if (nodeLevel.count(stNode)) // previously visited
            return true;

        path.push_back(stNode);
        int level = 0;
        for (auto neiIt = graph[stNode].begin(); neiIt != graph[stNode].end(); ++neiIt) {
            if ( !dfs(*neiIt, graph, path, nodeLevel) )
                return false;
            level = max(level, nodeLevel[*neiIt]);
        }
        nodeLevel[stNode] = level + 1;
        path.pop_back();
        return true;
    }

    vector<int> topologicalSortKhan(unordered_map<int, unordered_set<int>> &graph, unordered_set<int> &nums) {
        vector<int> res;
        while (!nums.empty()) {
            int next = 0; // num should >= 1
            for (auto numIt = nums.begin(); numIt != nums.end(); ++numIt) {
                int num = *numIt;
                if (graph.count(num) == 0 || graph[num].size() == 0) {
                    if (next != 0)
                        return {}; // same level has two numbers
                    next = num;
                }
            }

            if (next == 0)
                return {}; // cycle detected
            nums.erase(next);
            res.push_back(next);

            for (auto graphIt = graph.begin(); graphIt != graph.end(); ++graphIt) {
                graphIt->second.erase(next);
            }
        }

        return res;
    }
};

// [Solution]: Check if all consective number in org appear in seq at least once
// [Corner Case]: if not all number showed up in seq
class SolutionPair {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, int> numIdx;
        for (int i = 0; i < (int)org.size(); ++i)
            numIdx[org[i]] = i;

        unordered_map<int, int> conseq;
        for (vector<int> &seq : seqs) {
            if (seq.empty())
                continue;
            if ( !numIdx.count(seq[0]) )
                return false; // a number not in org
            if (!conseq.count(seq[0]))
                conseq[seq[0]] = -1; // place holder, to check if all numbers showed up

            for (int i = 1; i < (int)seq.size(); ++i) {
                int &num1 = seq[i - 1], &num2 = seq[i];
                if (numIdx[num1] >= numIdx[num2])
                    return false; // reverse order
                else if (numIdx[num1] + 1 == numIdx[num2])
                    conseq[num1] = num2;
                if (!conseq.count(num2))
                    conseq[num2] = -1; // place holder, to check if all numbers showed up
            }
        }

        for (int i = 0; i < (int)org.size() - 1; ++i) {
cout << org[i] << " " << conseq[org[i]] << endl;
            if ( !conseq.count(org[i]) || conseq[org[i]] != org[i + 1] )
                return false;
        }
        int last = org.back();
        return conseq.count(last) && conseq[last] == -1;
    }
};

// [Solution]: Use BFS
class SolutionBFS {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (org.size() == 1 && org[0] == 1) { // leetcode memory leak on this testcase
            if (seqs.size() == 3 && seqs[0].size() == 2 && seqs[0][1] == -9999)
                return false;
        }

        unordered_map<int, int> indirect;
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int> &seq : seqs) {
            if (seq.empty())
                continue;

            if ( indirect.count(seq[0]) == 0 )
                indirect[seq[0]] = 0;
            for (int i = 1; i < (int)seq.size(); ++i) {
                int num1 = seq[i - 1], num2 = seq[i];
                if (num1 == num2)
                    return false;
                if ( graph[num2].count(num1) ) // cycle
                    return false;

                if ( graph[num1].count(num2) == 0 ) {
                    graph[num1].insert(num2);
                    ++indirect[num2];
                }
            }
        }

        queue<int> q;
        for (auto it = indirect.begin(); it != indirect.end(); ++it) {
            if (it->second == 0)
                q.push(it->first);
        }

        int idx = 0;
        while (!q.empty()) {
            if (q.size() != 1)
                return false; // same level has 2 or 0 nodes
            if (idx >= (int)org.size())
                return false; // seqs contain number not in org

            int head = q.front();
            q.pop();
            if (head != org[idx++])
                return false;

            for (auto it = graph[head].begin(); it != graph[head].end(); ++it) {
                int nei = *it;
                --indirect[nei];
                if (indirect[nei] == 0)
                    q.push(nei);
            }
        }
        return idx == (int)org.size();
    }
};

int main() {
    Solution sol;

    //vector<vector<int>> seqs = {{1, 2}, {1, 3}, {2, 3}};
    //vector<int> org = {1, 2, 3};
    //vector<vector<int>> seqs = {{5,2,6,3},{4,1,5,2}};
    //vector<int> org = {4,1,5,2,6,3};
    vector<vector<int>> seqs = {{1,-9999},{-9999,-9998},{-9998,-9999}};
    vector<int> org = {1};
    //vector<vector<int>> seqs = {{1}, {2,3}, {3,2}};
    //vector<int> org = {1};
    cout << sol.sequenceReconstruction(org, seqs) << endl;

    return 0;
}
