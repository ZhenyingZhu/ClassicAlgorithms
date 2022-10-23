#ifndef SRC_CPPPRIMER_ORQUERY_H_
#define SRC_CPPPRIMER_ORQUERY_H_

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

namespace cppprimer {

class OrQuery : public BinaryQuery {
    /* Source: Chapter 15.9.5
     * Description: Or query.
     */
    friend Query operator|(const Query&, const Query&);

    OrQuery(Query left, Query right):
        BinaryQuery(left, right, "|") { }

    // Concrete class. display() inherited
    std::set<line_no> eval(const TextQuery&) const;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_ORQUERY_H_ */
