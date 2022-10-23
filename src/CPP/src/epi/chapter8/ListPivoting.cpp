#include "ListPivoting.hpp"

#include "../../ListNode.h"
#include "../../MyUtils.h"
#include "HasCycle.hpp"

#include <memory>
#include <iostream>
#include <vector>
#include <stdexcept>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;
using myutils::ListNode;
using myutils::createList;
using myutils::is_equal;
using myutils::list_to_string;
using myutils::find_node;
using std::invalid_argument;

namespace epi {
  namespace chapter8 {
    shared_ptr<ListNode<int>> ListPivoting::listPivoting(const shared_ptr<ListNode<int>> &list, int k) {
        shared_ptr<ListNode<int>> smaller(new ListNode<int>()), same(new ListNode<int>()), larger(new ListNode<int>());

        auto cur = list, s = smaller, m = same, l = larger;
        while (cur) {
            if (cur->data < k) {
                s->next = cur;
                s = s->next;
            } else if (cur->data == k) {
                m->next = cur;
                m = m->next;
            } else {
                l->next = cur;
                l = l->next;
            }

            cur = cur->next;
        }

        s->next = same->next;
        m->next = larger->next;
        l->next = nullptr;

        return smaller->next;
    }

    bool ListPivoting::test() {
        vector<int> vec1 = {3, 2, 2, 11, 7, 5, 11};
        vector<int> vec2 = {3, 2, 2, 5, 7, 11, 11};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);

        auto head = listPivoting(list1, 7);

        if ( !is_equal(head, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(head) << endl;

            return false;
        }

        return true;
    }

  } // chapter8
} // epi
