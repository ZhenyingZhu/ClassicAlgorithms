#ifndef SRC_EPI_CHAPTER13_MERGECONTACTLISTS_HPP_
#define SRC_EPI_CHAPTER13_MERGECONTACTLISTS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter13 {
    class MergeContactLists {
    public:
        struct ContactList;

        struct HashContactList;

        MergeContactLists() { }

        ~MergeContactLists() { }

        std::vector<ContactList> mergeContactLists(const std::vector<ContactList> &contacts);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_MERGECONTACTLISTS_HPP_ */
