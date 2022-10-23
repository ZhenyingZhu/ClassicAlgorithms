#include <string>

#include "Query.h"
#include "WordQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "NotQuery.h"

using std::string;

namespace cppprimer {

Query operator&(const Query &lhs, const Query &rhs) {
    return new AndQuery(lhs, rhs);
}

Query operator|(const Query &lhs, const Query &rhs) {
    return new OrQuery(lhs, rhs);
}

Query operator~(const Query &oper) {
    return new NotQuery(oper);
}

Query::Query(const string & queryWord):
        q(new WordQuery(queryWord)),
        use(new std::size_t(1)) { }

} //cppprimer
