#ifndef SRC_SOLUTIONCOLLECTION_H_
#define SRC_SOLUTIONCOLLECTION_H_

#include <vector>

namespace myutils {

class SmartPtr;

class SolutionCollection {
    /* A singleton class
     * Contain a vector of pointers of Solutions
     */
public:
    static SolutionCollection* getInstance();

    SolutionCollection() { }

    ~SolutionCollection() { }

    void insertSolution(const SmartPtr&);

    bool checkSolutions();

    size_t solutionsNum();
private:
    static SolutionCollection *instance;

    std::vector<SmartPtr> solVec;

    // Copy construction, don't define to avoid use by mistake
    SolutionCollection(const SolutionCollection&);

    SolutionCollection& operator=(const SolutionCollection&);

};

} // myutils

#endif /* SRC_SOLUTIONCOLLECTION_H_ */
