#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-229745-1-1.html

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
    int connectedComponent(vector<ListNode*> &nodes) {
        if (nodes.empty())
            return 0;

        unordered_map<ListNode*, ListNode*> parents;
        for (ListNode *node : nodes) {
            unionNodes(node, node->next, parents);
        }

        return count(nodes, parents);
    }

private:
    ListNode* getParent(ListNode *node, unordered_map<ListNode*, ListNode*> &parents) {
        if (node == NULL)
            return NULL;

        if (!parents.count(node))
            parents[node] = node;
        if (parents[node] != node)
            return getParent(parents[node], parents);
        return parents[node];
    }

    void unionNodes(ListNode *node1, ListNode *node2, unordered_map<ListNode*, ListNode*> &parents) {
        ListNode *parent1 = getParent(node1, parents);
        ListNode *parent2 = getParent(node2, parents);
        if (parent1 == NULL || parent2 == NULL)
            return;
        parents[parent2] = parent1;
    }

    int count(vector<ListNode*> &nodes, unordered_map<ListNode*, ListNode*> &parents) {
        unordered_set<ListNode*> roots;
        for (ListNode* node : nodes) {
            roots.insert(getParent(node, parents));
        }
        return roots.size();
    }
};

int main() {
    Solution sol;

    ListNode l1(1), l2(2), l3(3), l4(4), l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    vector<ListNode*> nodes = {&l4, &l3, &l1, &l2, &l5};
    cout << sol.connectedComponent(nodes) << endl;

    return 0;
}
