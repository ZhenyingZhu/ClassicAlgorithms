#include "FindMissingElement.hpp"

#include <vector>
#include <bitset>
#include <istream>
#include <cassert>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::bitset;
using std::ifstream;
using std::ios;
using std::runtime_error;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter12 {
    unsigned int FindMissingElement::findMissingElement(ifstream *ifs) {
        const size_t prefixBitNum = 16;

        const size_t bucketNum = 1 << prefixBitNum;
        vector<size_t> counters(bucketNum, 0);
        unsigned int x;
        while (*ifs >> x) {
            unsigned int prefix = x >> prefixBitNum;
            ++counters[prefix];
        }

        const size_t bucketCapacity = 1 << (32 - prefixBitNum);
        size_t candidatePrefix = 0;
        for (;candidatePrefix != counters.size(); ++candidatePrefix) {
            if (counters[candidatePrefix] < bucketCapacity)
                break;
        }

        ifs->clear();
        ifs->seekg(0, ios::beg);
        bitset<bucketCapacity> bitVec;
        while (*ifs >> x) {
            if (x >> prefixBitNum == candidatePrefix) {
                unsigned int remain = ((1 << 16) - 1) & x;
                bitVec.set(remain);
            }
        }
        ifs->close();

        for (size_t i = 0; i != bucketCapacity; ++i) {
            if (bitVec[i] == 0) {
                return candidatePrefix << 16 | i;
            }
        }

        throw runtime_error("Not found.");
        return 0;
    }

    bool FindMissingElement::test() {
        ifstream file("resources/IPs.txt", ifstream::in);
        ifstream *fPtr = &file;

        try {
            unsigned int res = findMissingElement(fPtr);
            if (res != 8) {
                cout << "Should be 8" << endl;
                cout << "Result is " << res << endl;
                return false;
            }
        } catch (runtime_error &ex) {
            cout << ex.what() << endl;
        }

        return true;
    }

  } // chapter12
} // epi
