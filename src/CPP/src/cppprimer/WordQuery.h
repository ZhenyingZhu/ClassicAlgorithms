#ifndef SRC_CPPPRIMER_WORDQUERY_H_
#define SRC_CPPPRIMER_WORDQUERY_H_

#include "TextQuery.h"
#include "QueryBase.h"
#include "Query.h"

namespace cppprimer {

class WordQuery: public QueryBase {
    /* Source: Chapter 15.9.5
     * Description: Normal query.
     */
    friend class Query; // No public members.

    WordQuery(const std::string &s) : queryWord(s) { }

    std::set<line_no> eval(const TextQuery &t) const {
        return t.run_query(queryWord);
    }

    std::ostream& display(std::ostream &os) const {
        return os << queryWord;
    }

    std::string queryWord;
};

} // cppprimer

#endif /* SRC_CPPPRIMER_WORDQUERY_H_ */
