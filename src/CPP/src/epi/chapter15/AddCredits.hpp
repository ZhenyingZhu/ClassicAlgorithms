#ifndef SRC_EPI_CHAPTER15_ADDCREDITS_HPP_
#define SRC_EPI_CHAPTER15_ADDCREDITS_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class AddCredits : public myutils::Solution {
    public:
        class ClientsCreditsInfo;

        AddCredits():
            Solution("EPI Chapter 15.13",
                     "Add credits",
                     "A data structure that support search by id, find the max credit, "
                     "increase all credits and add/remove. Use hash table to store "
                     "id-credit map, BST to store credit-ids map. Increase all credits can "
                     "be implemented by using a global offset.") { }

        ~AddCredits() { }

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_ADDCREDITS_HPP_ */
