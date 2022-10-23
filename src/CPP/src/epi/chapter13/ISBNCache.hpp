#ifndef SRC_EPI_CHAPTER13_ISBNCACHE_HPP_
#define SRC_EPI_CHAPTER13_ISBNCACHE_HPP_

#include "../../Solution.h"

#include <unordered_map>
#include <utility>
#include <list>
#include <cassert>
#include <iostream>

namespace epi {
  namespace chapter13 {
    class ISBNCache : myutils::Solution {
    public:
        template <size_t capacity>
        class LRUCache {
        public:
            typedef int ISBN;
            typedef int Price;

            void insert(ISBN isbn, Price price) {
                Table::iterator iter = isbnPriceTable_.find(isbn);
                if (iter != isbnPriceTable_.end()) {
                    moveToFront_(isbn, iter);
                    return;
                }

                if (lruQueue_.size() == capacity) {
                    isbnPriceTable_.erase(lruQueue_.back());
                    lruQueue_.pop_back();
                }

                lruQueue_.push_front(isbn);
                isbnPriceTable_[isbn] = {lruQueue_.begin(), price};
            }

            bool lookup(ISBN isbn, Price *price) {
                Table::iterator tableIter = isbnPriceTable_.find(isbn);
                if (tableIter == isbnPriceTable_.end())
                    return false;

                //*price = tableIter->second.second; // does that work?
                int p = tableIter->second.second;
                *price = p;
                moveToFront_(isbn, tableIter);
                return true;
            }

            bool erase(ISBN isbn) {
                Table::iterator tableIter = isbnPriceTable_.find(isbn);
                if (tableIter == isbnPriceTable_.end())
                    return false;

                lruQueue_.erase(tableIter->second.first);
                isbnPriceTable_.erase(tableIter);
                return true;
            }

            size_t size() {
                return isbnPriceTable_.size();
            }

        private:
            typedef std::unordered_map<ISBN, std::pair< std::list<ISBN>::iterator, Price>> Table;

            Table isbnPriceTable_;
            std::list<ISBN> lruQueue_;

        private:
            void moveToFront_(ISBN isbn, const Table::iterator &tableIter) {
                assert( isbn == tableIter->first );

                lruQueue_.erase(tableIter->second.first);
                lruQueue_.push_front(isbn);
                tableIter->second.first = lruQueue_.begin();
            }
        };

        ISBNCache():
            Solution("EPI Chapter 13.3",
                     "Implement an ISBN cache",
                     "Key is ISBN, value is price. Insert until cache is "
                     "full, then use LRU to remove entry by implement a "
                     "linked list queue with hash table record key and list node.") { }

        ~ISBNCache() { }

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_ISBNCACHE_HPP_ */
