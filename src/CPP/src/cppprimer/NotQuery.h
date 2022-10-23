#ifndef SRC_CPPPRIMER_NOTQUERY_H_
#define SRC_CPPPRIMER_NOTQUERY_H_

#include "TextQuery.h"
#include "QueryBase.h"
#include "Query.h"

namespace cppprimer {

class NotQuery : public QueryBase {
    /* Source: Chapter 15.9.5
     * Description: Not query.
     */
    friend Query operator~(const Query &);

    NotQuery(Query q): query(q) { }

    // Concrete class, define all virtual functions
    std::set<line_no> eval(const TextQuery &t) const;

    std::ostream& display(std::ostream &os) const {
        return os << "~(" << query << ")";
    }

    const Query query;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_NOTQUERY_H_ */
