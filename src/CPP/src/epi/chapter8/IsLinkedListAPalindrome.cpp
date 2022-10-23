#include "IsLinkedListAPalindrome.hpp"

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
    shared_ptr<ListNode<int>> IsLinkedListAPalindrome::reverse(const shared_ptr<ListNode<int>> &list) {
        shared_ptr<ListNode<int>> dummy(new ListNode<int>());

        dummy->next = list;
        auto cur = list;

        while (cur && cur->next) {
            auto tmp = dummy->next;
            dummy->next = cur->next;
            cur->next = cur->next->next;
            dummy->next->next = tmp;
        }

        return dummy->next;
    }

    bool IsLinkedListAPalindrome::isLinkedListAPalindrome(const shared_ptr<ListNode<int>> &list) {
        if (!list || !list->next)
            return true;

        auto slow = list, fast = list->next;
        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
        }

        auto firstHalf = list, secondHalf = reverse(slow->next);

        while (firstHalf && secondHalf) {
            if (firstHalf->data != secondHalf->data) {
                return false;
            }

            firstHalf = firstHalf->next, secondHalf = secondHalf->next;
        }

        secondHalf = reverse(secondHalf);
        slow->next = secondHalf;

        return true;
    }

    bool IsLinkedListAPalindrome::test() {
        vector<int> vec1 = {0, 1, 2, 3, 2, 1, 0};
        vector<int> vec2 = {0, 2, 4, 4, 2, 0};
        vector<int> vec3 = {0, 2, 4, 4, 2, 0, 0};
        shared_ptr<ListNode<int>> list1 = createList(vec1);
        shared_ptr<ListNode<int>> list2 = createList(vec2);
        shared_ptr<ListNode<int>> list3 = createList(vec3);

        if ( !isLinkedListAPalindrome(list1) or !isLinkedListAPalindrome(list2) ) {
            cout << "Should be: " << "is palindrome." << endl;
            cout << "But result: " << "list1 " << (isLinkedListAPalindrome(list1) ? "is" : "is not") << endl;
            cout << "But result: " << "list2 " << (isLinkedListAPalindrome(list2) ? "is" : "is not") << endl;
            return false;
        }

        if ( isLinkedListAPalindrome(list3) ) {
            cout << "Should be: " << "not palindrome." << endl;
            cout << "But result: " << "list3 " << (isLinkedListAPalindrome(list3) ? "is" : "is not") << endl;
            return false;
        }

        return true;
    }

  } // chapter8
} // epi
