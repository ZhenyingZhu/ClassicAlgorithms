#ifndef SRC_EPI_CHAPTER14_GROUPBYAGE_HPP_
#define SRC_EPI_CHAPTER14_GROUPBYAGE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class GroupByAge : public myutils::Solution {
    public:
        struct Person;

        GroupByAge():
            Solution("EPI Chapter 14.7",
                     "Partitioning and sorting an array with many repeated entries",
                     "In place bucket sort. Use a hash table to record the end of each "
                     "bucket. Each time pick the next cell of last element in the first "
                     "bucket, and place it into the right bucket. When a bucket is full, "
                     "remove the bucket from hash table. At the end the array will be sorted.") { }

        ~GroupByAge() { }

        void groupByAge(std::vector<Person> &persons);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_GROUPBYAGE_HPP_ */
