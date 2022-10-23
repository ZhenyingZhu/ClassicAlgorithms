#include "EliminateDuplicate.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::sort;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter14 {
    struct EliminateDuplicate::Name {
        void operator=(const Name &that) {
            firstName = that.firstName;
            lastName = that.lastName;
        }

        bool operator==(const Name &that) const {
            return firstName == that.firstName;
        }

        bool operator!=(const Name &that) const {
            return !operator==(that);
        }

        bool operator<(const Name &that) const {
            return firstName < that.firstName;
        }

        string firstName, lastName;
    };

    void EliminateDuplicate::eliminateDuplicate(std::vector<Name> &vec) {
        if (vec.size() <= 1)
            return;

        sort(vec.begin(), vec.end());

        vector<Name>::iterator cur = vec.begin();
        for (vector<Name>::iterator iter = vec.begin() + 1; iter != vec.end(); ++iter) {
            if (*iter != *cur) {
                *(++cur) = *iter;
            }
        }

        vec.erase(++cur, vec.end());
    }

    bool EliminateDuplicate::test() {
        vector<Name> vec = {{"Ian", "Botham"}, {"David", "Gower"}, {"Ian", "Bell"}, {"Ian", "Chappell"}};

        eliminateDuplicate(vec);

        if (vec.size() != 2) {
            cout << "Should be size 2" << endl;
            cout << "But result contains" << endl;
            for (size_t i = 0; i != vec.size(); ++i) {
                cout << vec[i].firstName << " " << vec[i].lastName << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter14
} // epi
