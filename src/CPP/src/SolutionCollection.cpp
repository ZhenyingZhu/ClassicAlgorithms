#include <stddef.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

#include "SolutionCollection.h"
#include "SmartPtr.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::exception;

namespace myutils {
static const string SEPARATE(10, '=');

SolutionCollection *SolutionCollection::instance = NULL;

SolutionCollection* SolutionCollection::getInstance() {
    if (!instance) {
        instance = new SolutionCollection();
    }
    return instance;
}

void SolutionCollection::insertSolution(const SmartPtr& solPtr) {
    solVec.push_back(solPtr);
}

bool SolutionCollection::checkSolutions() {
    for (vector<SmartPtr>::iterator iter = solVec.begin();
            iter != solVec.end(); ++iter) {
        cout << SEPARATE << endl;
        cout << iter->displaySource() << endl;
        cout << iter->displayTitle() << endl;
        try {
            if ( !iter->runTest() ) {
                cout << "Failed" << endl;
                return false;
            } else {
                cout << "Passed" << endl;
            }
        } catch (exception &ex) {
            cout << ex.what() << endl;
        }
    }

    return true;
}

size_t SolutionCollection::solutionsNum() {
    return solVec.size();
}

} // myutils
