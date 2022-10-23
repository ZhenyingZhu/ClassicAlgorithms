#ifndef SRC_EPI_CHAPTER15_NODESONPATH_HPP_
#define SRC_EPI_CHAPTER15_NODESONPATH_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class NodesOnPath : public myutils::Solution {
    public:
        NodesOnPath():
            Solution("EPI Chapter 15.11",
                     "Test if three BST nodes are totally ordered",
                     "Search from one node to mid, if find, then search "
                     "from mid to the other node. Otherwise search from "
                     "the other node to mid.") { }

        ~NodesOnPath() { }

        bool pairIncludesAncestorAndDescendantOfM(const std::unique_ptr<myutils::BSTNode<int>> &node0,
                                                  const std::unique_ptr<myutils::BSTNode<int>> &node1,
                                                  const std::unique_ptr<myutils::BSTNode<int>> &mid);

        bool test();

    private:
        bool isAncestor(const std::unique_ptr<myutils::BSTNode<int>> &ancestor,
                        const std::unique_ptr<myutils::BSTNode<int>> &descendant);

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_NODESONPATH_HPP_ */
