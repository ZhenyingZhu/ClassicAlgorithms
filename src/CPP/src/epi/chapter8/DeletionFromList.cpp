#include "DeletionFromList.hpp"

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
    void DeletionFromList::deletionFromList(shared_ptr<ListNode<int>> &node) {
        if (!node->next) {
            node = nullptr; // will it cause a memory leak?
        }

        node->data = node->next->data;
        node->next = node->next->next;
    }

    bool DeletionFromList::test() {
        vector<int> vec1 = {1, 2, 3, 4};
        vector<int> vec2 = {1, 2, 4};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);
        auto node3 = find_node(list1, 3);

        deletionFromList(node3);

        if ( !is_equal(list1, list2) ) {
            cout << "Should be: " << list_to_string(list2) << endl;
            cout << "But result: " << list_to_string(list1) << endl;

            return false;
        }


        return true;
    }

  } // chapter8
} // epi
