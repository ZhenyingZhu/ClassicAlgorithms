#include "ReverseSublist.hpp"

#include "../../ListNode.h"

#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "../../MyUtils.h"

using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using myutils::ListNode;
using myutils::createList;
using myutils::is_equal;
using myutils::list_to_string;
using std::invalid_argument;

namespace epi {
  namespace chapter8 {
    shared_ptr<ListNode<int>> ReverseSublist::reverseSublist(shared_ptr<ListNode<int>> list, int start, int finish) {
        if (start >= finish)
            return list;

        shared_ptr<ListNode<int>> dummy(new ListNode<int>);
        dummy->next = list;

        shared_ptr<ListNode<int>> s = list, f = list, pre = dummy;
        auto i = 0;

        for (; i != start; ++i) {
            if (!s)
                throw invalid_argument("start is larger than the list length");

            if (i != 0)
                pre = s;

            s = s->next;
        }

        f = s;
        for (; i != finish; ++i) {
            if (!f)
                throw invalid_argument("finish is larger than the list length");
            f = f->next;
        }

        shared_ptr<ListNode<int>> cur = s;
        while (cur != f) {
            pre->next = cur->next;
            shared_ptr<ListNode<int>> tmp = f->next;
            f->next = cur;
            cur->next = tmp;
            cur = pre->next;
        }

        return dummy->next;
    }

    bool ReverseSublist::test() {
        vector<int> vec = {0, 11, 5, 3, 7, 2};
        vector<int> sv = {0, 11, 7, 3, 5, 2};
        shared_ptr<ListNode<int>> list = createList(vec);
        shared_ptr<ListNode<int>> shouldBe = createList(sv);
        shared_ptr<ListNode<int>> res = reverseSublist(list, 2, 4);

        if ( !is_equal(res, shouldBe) ) {
            cout << "Should be: " << list_to_string(shouldBe) << endl;
            cout << "But result: " << list_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter8
} // epi
