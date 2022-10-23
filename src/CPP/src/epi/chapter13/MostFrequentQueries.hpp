#ifndef SRC_EPI_CHAPTER13_MOSTFREQUENTQUERIES_HPP_
#define SRC_EPI_CHAPTER13_MOSTFREQUENTQUERIES_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter13 {
    class MostFrequentQueries : public myutils::Solution {
    public:
        MostFrequentQueries():
            Solution("EPI Chapter 13.5",
                     "Compute the k most frequent queries",
                     "Use a hash table, key is string and value is freq. "
                     "Then use min heap to retrive the k largest strings. "
                     "T(n)=O(n+mlogk), where n is the number of string, m "
                     "is the number of uniq strings.") { }

        ~MostFrequentQueries() { }

        std::vector<std::string> mostFrequentQueries(const std::vector<std::string> &queries, size_t k);

        bool test();

    private:
        struct QueryFreq {
            std::string query;
            size_t freq;
        };

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_MOSTFREQUENTQUERIES_HPP_ */
