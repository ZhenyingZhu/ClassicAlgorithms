#include <iostream>
#include <string>

#include "SmartPtr.h"
#include "Solution.h"

using std::string;

namespace myutils {

SmartPtr::SmartPtr(Solution *solution):
        solPtr(solution), use(new std::size_t(1)) { }


SmartPtr::SmartPtr(const SmartPtr &copy):
    solPtr(copy.solPtr), use(copy.use) {
        ++*use;
}

SmartPtr& SmartPtr::operator=(const SmartPtr &copy) {
    descUse(); // release itself first

    solPtr = copy.solPtr;
    use = copy.use;
    ++*use;
    return *this;
}

void SmartPtr::descUse() {
    --*use;
    if (*use == 0) {
        delete solPtr;
        delete use;
    }
}

string SmartPtr::displaySource() {
    return solPtr->getSource();
}

string SmartPtr::displayTitle() {
    return solPtr->getTitle();
}

string SmartPtr::displayDescription() {
    return solPtr->getDescription();
}

bool SmartPtr::runTest() {
    return solPtr->test();
}

} // myutils
