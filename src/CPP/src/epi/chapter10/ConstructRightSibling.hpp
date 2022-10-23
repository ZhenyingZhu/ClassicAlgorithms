#ifndef SRC_EPI_CHAPTER10_CONSTRUCTRIGHTSIBLING_HPP_
#define SRC_EPI_CHAPTER10_CONSTRUCTRIGHTSIBLING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

namespace epi {
  namespace chapter10 {

    class ConstructRightSibling : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        template <typename T>
        struct BTSiblingNode {
            BTSiblingNode(T d): data(d), next(nullptr) { }

//            ~BTSiblingNode() {
//                delete next; // error: double free or corruption (fasttop)
//            }

            T data;
            std::unique_ptr<BTSiblingNode> left, right;
            BTSiblingNode *next;
        };

        ConstructRightSibling():
            Solution("EPI Chapter 10.16",
                     "Compute the right sibling tree",
                     "level order traverse the tree using a queue. At "
                     "the current level, link all next level nodes.") { }

        ~ConstructRightSibling() { }

        void constructRightSibling(BTSiblingNode<int> *tree);

        bool test();

    private:
        void updateRightSibling(BTSiblingNode<int> *node, BTSiblingNode<int> *parent);

        std::unique_ptr<BTSiblingNode<int>> createPreOrderIntBTree(const std::vector<int> &vec, size_t *pos);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_CONSTRUCTRIGHTSIBLING_HPP_ */
