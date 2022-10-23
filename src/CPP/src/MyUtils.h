#ifndef SRC_MYUTILS_H_
#define SRC_MYUTILS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

#include "ListNode.h"
#include "BinaryTreeNode.h"
#include "BSTNode.h"

namespace myutils {

    std::ifstream& open_file(std::ifstream &in, char *file);

    std::string make_plural(size_t ctr, const std::string &word, const std::string &ending);

    template <typename T>
    bool test_same(T shouldBe, T result) {
        if (shouldBe != result) {
            std::cout << "Should be: " << shouldBe << std::endl;
            std::cout << "Result: " << result << std::endl;
            return false;
        }

        return true;
    }

    template <typename T>
    std::string vec_to_string(const std::vector<T> &vec) {
        std::string output = "<";
        bool first_ele(true);
        for (typename std::vector<T>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter) {
            if (first_ele)
                first_ele = false;
            else
                output += ", ";

            output += std::to_string(*iter);
        }
        output += ">";

        return output;
    }

    template <typename T>
    std::string matrix_to_string(const std::vector< std::vector<T> > &matrix) {
        std::string output = "";

        for (typename std::vector<std::vector<T>>::const_iterator line = matrix.begin(); line != matrix.end(); ++ line) {
            bool first_ele = true;
            output += "|";
            for (typename std::vector<T>::const_iterator iter = line->begin(); iter != line->end(); ++iter) {
                if (first_ele)
                    first_ele = false;
                else
                    output += "\t";

                output += std::to_string(*iter);
            }
            output += "|";
            output += "\n";
        }

        return output;
    }

    template <typename T>
    std::shared_ptr<ListNode<T>> createList(const std::vector<T> &vec) {
        if (vec.size() == 0)
            throw std::invalid_argument("Input vector is empty.");

        std::shared_ptr<ListNode<T>> head( new ListNode<T>(vec[0]) ), cur = head;

        for (size_t i = 1; i != vec.size(); ++i) {
            std::shared_ptr<ListNode<T>> newNode(new ListNode<T>(vec[i]));
            cur->next = newNode;
            cur = cur->next;
        }

        return head;
    }

    std::unique_ptr<BinaryTreeNode<int>> createPreOrderIntBTree(const std::vector<int> &vec, size_t *pos);

    std::unique_ptr<BSTNode<int>> createPreOrderIntBST(const std::vector<int> &vec, size_t *pos);

    std::unique_ptr<BSTNode<int>> createBSTFromPreorder(const std::vector<int> &preorderSeq);

    void traversePreInOrder(std::unique_ptr<myutils::BinaryTreeNode<int>> &tree, std::vector<int> &preorder, std::vector<int> &inorder);

    template <typename T>
    bool is_equal(const std::shared_ptr<ListNode<T>> &l1, const std::shared_ptr<ListNode<T>> &l2) {
        std::shared_ptr<ListNode<T>> p1 = l1;
        std::shared_ptr<ListNode<T>> p2 = l2;
        while (p1 && p2) {
            if (p1->data != p2->data) {
                return false;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        if (p1 || p2) {
            return false;
        }

        return true;
    }

    template <typename T>
    std::shared_ptr<ListNode<T>> find_node(const std::shared_ptr<ListNode<T>> &list, T data) {
        std::shared_ptr<ListNode<T>> ptr = list;
        while (ptr) {
            if (ptr->data == data)
                break;

            ptr = ptr->next;
        }
        return ptr;
    }

    template <typename T>
    std::string list_to_string(const std::shared_ptr<ListNode<T>> &list) {
        std::string res("");

        std::shared_ptr<ListNode<T>> head = list;
        while (head) {
            res += std::to_string(head->data) + "->";
            head = head->next;
        }

        res += "null";

        return res;
    }
} // myutils

#endif /* SRC_MYUTILS_H_ */
