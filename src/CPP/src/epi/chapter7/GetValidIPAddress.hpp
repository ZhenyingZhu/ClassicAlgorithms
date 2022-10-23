#ifndef SRC_EPI_CHAPTER7_GETVALIDIPADDRESS_HPP_
#define SRC_EPI_CHAPTER7_GETVALIDIPADDRESS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>
#include <vector>

namespace epi {
  namespace chapter7 {

    class GetValidIPAddress : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        GetValidIPAddress():
            Solution("EPI Chapter 7.10",
                     "Compute all valid IP addresses",
                     "each part should be between 0 to 255, and cannot be 01.") {
        }

        ~GetValidIPAddress() { }

        std::vector<std::string> getValidIPAddress(const std::string &s);

        bool test();

    private:
        void getValidIPAddressHelper(const std::string &s, size_t pos,
                                     std::string partialStr, size_t part,
                                     std::vector<std::string> &vec);

        bool isValidIPPart(const std::string &partialIP);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_GETVALIDIPADDRESS_HPP_ */
