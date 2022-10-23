#ifndef SRC_CPPPRIMER_QUERY_H_
#define SRC_CPPPRIMER_QUERY_H_

#include <iostream>
#include "TextQuery.h"
#include "QueryBase.h"

namespace cppprimer {

class Query {
    /* Source: Chapter 15.9.2
     * Description: A handler.
     */
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const std::string&);

    // Three copy control functions.
    Query(const Query &c) : q(c.q), use(c.use) {
        ++*use;
    }

    ~Query() {
        decr_use();
    }

    Query& operator=(const Query&);

    // Two interface functions that call QueryBase dynamic binding
    std::set<TextQuery::line_no> eval(const TextQuery &t) const {
        return q->eval(t);
    }

    std::ostream& display(std::ostream &os) const {
        return q->display(os);
    }

private:
    Query(QueryBase *query): q(query), use(new std::size_t(1)) { }

    QueryBase *q;
    std::size_t *use;

    void decr_use() {
        if (--*use == 0) {
            delete q;
            delete use;
        }
    }

}; // Query

inline std::ostream& operator<<(std::ostream &os, const Query& q) {
    return q.display(os);
}

} // cppprimer
#endif
