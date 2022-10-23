#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/word-ladder-ii/
// http://www.1point3acres.com/bbs/thread-225659-1-1.html
// Not finished. DFS timed out, BFS is wrong at adding node part

class SolutionDFS {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        //dict.insert(endWord);

        vector<string> path = {beginWord};
        vector<vector<string>> res;
        minLen = INT_MAX;
        helper(beginWord, endWord, path, dict, res);

        vector<vector<string>> collection;
        for (vector<string> &vec : res) {
            if ((int)vec.size() == minLen)
                collection.push_back(vec);
            else
                cout << "Longer" << endl;
        }
        return collection;
    }

    void helper(string &beginWord, string &endWord, vector<string> &path, unordered_set<string> &dict, vector<vector<string>> &res) {
        if (beginWord == endWord) {
            minLen = path.size();
            res.push_back(path);
            return;
        }
        if ((int)path.size() >= minLen)
            return;

        for (int i = 0; i < (int)beginWord.length(); ++i) {
            char oriChar = beginWord[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == oriChar)
                    continue;

                beginWord[i] = c;
                if (!dict.count(beginWord))
                    continue;

                path.push_back(beginWord);
                dict.erase(beginWord);
                helper(beginWord, endWord, path, dict, res);
                dict.insert(beginWord);
                path.pop_back();
            }
            beginWord[i] = oriChar;
        }
    }

    int minLen;
};


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, Node*> graph;
        for (string &word : wordList) {
            graph[word] = new Node(word);
        }

        if (!graph.count(endWord))
            return {};

        queue<Node*> q;
        Node *begin = new Node(beginWord);
        graph[beginWord] = begin;
        q.push(begin);

        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                Node *run = q.front();
                q.pop();
                if (run->word == endWord) {
                    found = true;
                    break;
                }

                run->status = 1;
                string word = run->word;
                for (int i = 0; i < (int)word.length(); ++i) {
                    char oriChar = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == oriChar)
                            continue;

                        word[i] = c;
                        if (!graph.count(word))
                            continue;

                        Node *neighbor = graph[word];
                        if (neighbor->status == 1)
                            continue;
                        neighbor->prevs.insert(run);
                        q.push(neighbor);
                    }
                    word[i] = oriChar;
                }
            }

            if (found)
                break;
        }

        if (!found)
            return {};

        vector<vector<string>> res;
        vector<string> path;
        constructRes(graph[endWord], graph, path, res);
        return res;
    }

private:
    struct Node {
        Node(string &w): word(w), status(0) { }
        string word;
        int status; // 0 unvisit, 1 visiting, 2. visited
        unordered_set<Node*> prevs;
    };

private:
    void constructRes(Node *node, unordered_map<string, Node*> &graph, vector<string> &path, vector<vector<string>> &res) {
        path.push_back(node->word);

        if (node->prevs.empty()) {
            vector<string> reversePath = path;
            reverse(reversePath.begin(), reversePath.end());
            res.push_back(reversePath);
        } else {
            for (Node *neighbor : node->prevs) {
                constructRes(neighbor, graph, path, res);
            }
        }

        path.pop_back();
    }
};

int main() {
    Solution sol;

    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    for (vector<string> &vec : sol.findLadders("hit", "cog", wordList)) {
        for (string &str : vec)
            cout << str << " ";
        cout << endl;
    }

    return 0;
}
