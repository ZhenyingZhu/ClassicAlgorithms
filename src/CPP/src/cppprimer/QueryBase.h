#ifndef SRC_CPPPRIMER_QUERYBASE_H_
#define SRC_CPPPRIMER_QUERYBASE_H_

#include <iostream>

#include "TextQuery.h"

namespace cppprimer {

class Query;

class QueryBase {
    /* Source: Chapter 15.9.1
     * Description: Root class of all queries.
     */
    friend class Query; // a handler
protected:
    typedef TextQuery::line_no line_no;
    virtual ~QueryBase() { }
private:
    // Return all line numbers that include the work
    virtual std::set<line_no> eval(const TextQuery&) const = 0;
    // The executed query operation
    virtual std::ostream& display(std::ostream& = std::cout) const = 0;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_QUERYBASE_H_ */
