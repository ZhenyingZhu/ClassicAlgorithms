#ifndef SRC_CPPPRIMER_ANDQUERY_H_
#define SRC_CPPPRIMER_ANDQUERY_H_

#include "BinaryQuery.h"
#include "Query.h"
#include "TextQuery.h"

namespace cppprimer {

class AndQuery : public BinaryQuery {
    /* Source: Chapter 15.9.5
     * Description: And query.
     */
    friend Query operator&(const Query&, const Query&);

    AndQuery(Query left, Query right):
        BinaryQuery(left, right, "&") { }

    // Concrete class. display() inherited
    std::set<line_no> eval(const TextQuery&) const;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_ANDQUERY_H_ */
