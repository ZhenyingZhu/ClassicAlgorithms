#ifndef SRC_EPI_CHAPTER12_FINDMISSINGELEMENT_HPP_
#define SRC_EPI_CHAPTER12_FINDMISSINGELEMENT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <istream>

namespace epi {
  namespace chapter12 {
    class FindMissingElement : myutils::Solution {
    public:
        FindMissingElement():
            Solution("EPI Chapter 12.9",
                     "Find the missing IP address",
                     "The input is in a file and is very large. To same RAM, "
                     "scan it twice. First scan prefixes of all IP address and "
                     "count the number of each prefix. If the count is not same "
                     "as it should be, rescan the file and use a hash table(bit "
                     "set) to record which has shown. Then scan the bitset to "
                     "return the result.") { }

        ~FindMissingElement() { }

        unsigned int findMissingElement(std::ifstream *ifs);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_FINDMISSINGELEMENT_HPP_ */
