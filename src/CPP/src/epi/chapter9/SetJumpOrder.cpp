#include "SetJumpOrder.hpp"

#include <stack>
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <vector>

using std::stack;
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::stoi;
using std::length_error;
using std::invalid_argument;
using std::cout;
using std::endl;
using std::vector;

namespace epi {
  namespace chapter9 {
    struct SetJumpOrder::PostingListNode {
        PostingListNode(): id(0), order(-1) { }

        PostingListNode(int i): id(i), order(-1) { }

        int id;
        std::shared_ptr<PostingListNode> jump;
        std::shared_ptr<PostingListNode> next;
        int order;
    };

    void SetJumpOrder::setJumpOrderHelper(shared_ptr<PostingListNode> &node, int &order) {
        if (node && node->order == -1) {
            node->order = order++;
            setJumpOrderHelper(node->jump, order);
            setJumpOrderHelper(node->next, order);
        }
    }

    void SetJumpOrder::setJumpOrderRecursive(const shared_ptr<PostingListNode> &list) {
        auto node = list;
        int order = 0;
        setJumpOrderHelper(node, order);
    }

    void SetJumpOrder::setJumpOrder(const shared_ptr<PostingListNode> &list) {
        if (!list)
            return;

        stack<shared_ptr<PostingListNode>> st;
        auto node = list;
        st.push(node);

        int order = 0;
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();

            if (cur->order != -1)
                continue;
            cur->order = order++;

            if (cur->next)
                st.push(cur->next);
            if (cur->jump)
                st.push(cur->jump);
        }
    }

    bool SetJumpOrder::test() {
        shared_ptr<PostingListNode> a1(new PostingListNode(1)), a2(new PostingListNode(2)),
                a3(new PostingListNode(3)), a4(new PostingListNode(4)), a5(new PostingListNode(5));
        a1->next = a2, a2->next = a3, a3->next = a4, a4->next = a5;
        a1->jump = a4, a2->jump = a3, a3->jump = a5, a4->jump = a3, a5->jump = a5;
        vector<shared_ptr<PostingListNode>> veca = {a1, a2, a3, a4, a5};

        shared_ptr<PostingListNode> b1(new PostingListNode(1)), b2(new PostingListNode(2)),
                b3(new PostingListNode(3)), b4(new PostingListNode(4)), b5(new PostingListNode(5));
        b1->next = b2, b2->next = b3, b3->next = b4, b4->next = b5;
        b1->jump = b4, b2->jump = b3, b3->jump = b5, b4->jump = b3, b5->jump = b5;
        vector<shared_ptr<PostingListNode>> vecb = {b1, b2, b3, b4, b5};

        setJumpOrderRecursive(a1);
        setJumpOrderRecursive(b1);

        for (size_t i = 0; i != veca.size(); ++i) {
            auto a = veca[i];
            auto b = vecb[i];
            if (a->order != b->order) {
                cout << "Node " << i << "should be " << a->order << endl;
                cout << "Result: " << b->order << endl;
                return false;
            }
        }
        return true;
    }

  } // chapter9
} // epi

