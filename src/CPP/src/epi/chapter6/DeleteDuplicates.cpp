#include "DeleteDuplicates.hpp"

#include <vector>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {

int DeleteDuplicates::deleteDuplicates(vector<int> *vec_ptr) {
    vector<int> &vec = *vec_ptr;

    if (vec.empty())
        return 0;

    vector<int>::iterator insert_pos = vec.begin();

    for (vector<int>::iterator iter = vec.begin() + 1; iter != vec.end(); ++iter) {
        if (*iter != *insert_pos)
            *(++insert_pos) = *iter;
    }

    return insert_pos - vec.begin() + 1;
}

bool DeleteDuplicates::test() {
    vector<int> vec = {1, 1, 1, 2, 2, 3};

    cout << deleteDuplicates(&vec) << endl;
    cout << vec_to_string(vec) << endl;

    return true;
}

} // chapter6
} // epi
